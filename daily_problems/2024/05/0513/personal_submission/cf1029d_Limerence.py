# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-13 13:18:05
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


from collections import Counter

n, k = invr()
a = inlt()
len_dic = [Counter() for _ in range(11)]
for x in a:
    len_dic[len(str(x))][x % k] += 1
ans = 0
for x in a:
    this_ans = x
    for end_len in range(1, 11):
        this_ans *= 10
        this_ans %= k
        need_mod = (k - this_ans) % k
        ans += len_dic[end_len][need_mod]
        # delete i == j cases
        if len(str(x)) == end_len and (this_ans + x) % k == 0:
            ans -= 1

print(ans)
