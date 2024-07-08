#!/usr/bin/env python3
import os
import subprocess
import re
import csv
import urllib.request
import ssl

FILENAME = os.path.basename(__file__)


def main():
    Log("main")

    gcc_version = get_gcc_version()
    Log(f"gcc version: {gcc_version}")

    # GCC警告オプションを取得
    warning_option = get_gcc_warning_option()
    warning_option = get_gcc_warning_option_setting(warning_option, "default")
    warning_option = get_gcc_warning_option_setting(warning_option, "-Wall")
    warning_option = get_gcc_warning_option_setting(warning_option, "-Wall -Wextra")

    # GCC警告オプションをCSVファイルへ出力
    gcc_warning_option_file = f"gcc_warning_option_v{gcc_version}.csv"
    Log(f"gcc warning option file: {gcc_warning_option_file}")
    with open(gcc_warning_option_file, "w", encoding="shift-jis") as f:
        writer = csv.writer(f, delimiter=",", quotechar='"', quoting=csv.QUOTE_ALL)
        writer.writerow(["オプション名", "説明", "default", "'-Wall", "-Wall -Wextra"])
        for key in warning_option:
            option = warning_option[key]
            line = ["'" + key]
            line += ["'" + option["detail"]] if "detail" in option else [""]
            line += ["'" + option["default"]] if "default" in option else [""]
            line += ["'" + option["-Wall"]] if "-Wall" in option else [""]
            line += (
                ["'" + option["-Wall -Wextra"]] if "-Wall -Wextra" in option else [""]
            )
            writer.writerow(line)

    clang_version = "8.0.0"
    Log(f"clang version: {clang_version}")

    # Clang警告オプションを取得
    warning_option = get_clang_warning_option()

    # Clang警告オプションをCSVファイルへ出力
    clang_warning_option_file = f"clang_warning_option_v{clang_version}.csv"
    Log(f"clang warning option file: {clang_warning_option_file}")
    with open(clang_warning_option_file, "w", encoding="shift-jis") as f:
        writer = csv.writer(f, delimiter=",", quotechar='"', quoting=csv.QUOTE_ALL)
        writer.writerow(["オプション名", "説明", "default"])
        for key in warning_option:
            option = warning_option[key]
            line = ["'" + key]
            line += ["'" + option["detail"]] if "detail" in option else [""]
            line += ["'" + option["default"]] if "default" in option else [""]
            writer.writerow(line)


def get_clang_warning_option() -> dict:
    url = "https://releases.llvm.org/8.0.0/tools/clang/docs/DiagnosticsReference.html"
    ssl._create_default_https_context = ssl._create_unverified_context
    with urllib.request.urlopen(url) as res:
        html = res.read().decode()
    html_lines = html.splitlines()

    dict_warning_option = {}
    option_name = ""
    for line in html_lines:
        if line.startswith('<h3><a class="toc-backref"'):
            option_name = re.sub("<.+?>", "", line)
            option_name = re.sub("¶", "", option_name)
            # print(option_name)
            # 辞書に登録
            dict_warning_option[option_name] = {"detail": "", "default": ""}
            continue
        if option_name is not "":
            tmp1 = re.search("<p>.*?\.</p>", line)
            if not tmp1:
                option_name = ""
                continue
            tmp2 = re.search("<a\s", tmp1.group(0))
            if tmp2:
                option_name = ""
                continue
            setting = re.sub("<p>", "", line)
            setting = re.sub("</p>", "", setting)
            # print(setting)
            dict_warning_option[option_name]["default"] = setting
            option_name = ""
    return dict_warning_option


def get_gcc_version() -> str:
    """
    GCCのバージョン文字列を取得する
    """
    cmd = ["gcc"]
    cmd += ["--version"]
    result = DoResult(cmd)
    search_result = re.search("(\d+).(\d+).(\d+)", result)
    if search_result:
        version = search_result.group(0)
    return version


def get_gcc_warning_option() -> dict:
    """
    GCCの警告オプションリストを辞書型で取得する
    """
    cmd = ["gcc"]
    cmd += ["--help=warnings"]
    result = DoResult(cmd)
    result = result.splitlines()

    dict_warning_option = {}
    option_name = ""
    for i, line in enumerate(result):
        # 1行目は説明文のためスルー
        if i == 0:
            continue

        # 正規表現で警告オプション名の取得
        search_option_name = re.search("(-+)(\S+)", line)
        if search_option_name:
            # 警告オプション名があれば新規登録
            option_name = search_option_name.group(0)

            # 警告オプションの説明文を取得
            tmp1 = re.sub("\A(\s+)", "", line)
            tmp1 = re.sub("\A(-+)(\S+)", "", tmp1)
            detail = re.sub("\A(\s+)", "", tmp1)

            # 辞書に登録
            dict_warning_option[option_name] = {"detail": detail}
        else:
            # 警告オプション名があれば説明文の続き
            add_detail = re.sub("\A(\s+)", "", line)
            # 既に登録済みの説明文に追記
            dict_warning_option[option_name]["detail"] += f" {add_detail}"
    return dict_warning_option


def get_gcc_warning_option_setting(warning_option: dict, add_opt: str) -> dict:
    """
    取得済みのGCCの警告オプションリストに設定値を追記する
    """
    cmd = ["gcc"]
    cmd += ["-Q"]
    cmd += ["--help=warnings"]
    if add_opt is not "default":
        cmd += add_opt.split(" ")
    result = DoResult(cmd)
    result = result.splitlines()

    for i, line in enumerate(result):
        # 1行目は説明文のためスルー
        if i == 0:
            continue

        # 正規表現で警告オプション名の取得
        search_option_name = re.search("(-+)(\S+)", line)
        if not search_option_name:
            continue
        option_name = search_option_name.group(0)

        # 正規表現で警告オプションの設定値を取得
        tmp1 = re.sub("\A(\s+)", "", line)
        setting = re.sub("\A(-+)(\S+)(\s+)", "", tmp1)

        if option_name in warning_option:
            warning_option[option_name][add_opt] = setting

    return warning_option


def DoResult(cmd):
    result = subprocess.run(cmd, encoding="utf-8", stdout=subprocess.PIPE)
    if result.returncode != 0:
        command = " ".join(cmd)
        Error(command + "  result=" + str(result.returncode))
    return result.stdout.strip()


def Do(cmd):
    command = " ".join(cmd)
    Log("Do: " + command)
    result = subprocess.call(command, shell=True)
    if result != 0:
        Error(command + "  result=" + str(result))


def Error(msg):
    Log(f"error: {msg}")
    os.sys.exit(0)


def Log(msg):
    print(f"[{FILENAME}] {msg}")


if __name__ == "__main__":
    main()
