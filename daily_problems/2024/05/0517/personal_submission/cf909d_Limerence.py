# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-17 10:47:58
# ----------------------------------------------

import sys

input = sys.stdin.readline


def inp():
    return int(input())


def inlt():
    return list(map(int, input().split()))


def insr():
    s = input()
    return list(s[: len(s) - 1])


def invr():
    return map(int, input().split())


def ins():
    return input().strip()


s = ins()
n = len(s)
cnt = 1
len_ls = []
ch_ls = []
for i in range(1, n):
    if s[i] == s[i - 1]:
        cnt += 1
    else:
        len_ls.append(cnt)
        ch_ls.append(s[i - 1])
        cnt = 1
len_ls.append(cnt)
ch_ls.append(s[-1])
ans = 0
while len(len_ls) > 1:
    new_len_ls = []
    new_ch_ls = []
    if len_ls[0] > 1:
        new_len_ls.append(len_ls[0] - 1)
        new_ch_ls.append(ch_ls[0])
    for i in range(1, len(len_ls) - 1):
        if len_ls[i] > 2:
            if new_ch_ls and ch_ls[i] == new_ch_ls[-1]:
                new_len_ls[-1] += len_ls[i] - 2
            else:
                new_len_ls.append(len_ls[i] - 2)
                new_ch_ls.append(ch_ls[i])
    if len_ls[-1] > 1:
        if new_ch_ls and ch_ls[-1] == new_ch_ls[-1]:
            new_len_ls[-1] += len_ls[-1] - 1
        else:
            new_len_ls.append(len_ls[-1] - 1)
            new_ch_ls.append(ch_ls[-1])
    len_ls = new_len_ls
    ch_ls = new_ch_ls
    ans += 1
print(ans)
