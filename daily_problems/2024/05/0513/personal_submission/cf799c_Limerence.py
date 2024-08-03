# ----------------------------------------------
# Author: zhengyi20thu
# Time: 2024-05-13 11:47:41
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


from bisect import bisect_right

n, c, d = invr()
c_cost_ls = []
d_cost_ls = []
c_beauty_ls = []
d_beauty_ls = []
for _ in range(n):
    tmp = ins().split()
    beauty, cost, tp = tmp[0], tmp[1], tmp[2]
    beauty = int(beauty)
    cost = int(cost)
    if tp == "C":
        c_cost_ls.append(cost)
        c_beauty_ls.append(beauty)
    else:
        d_cost_ls.append(cost)
        d_beauty_ls.append(beauty)

st_c = sorted(range(len(c_cost_ls)), key=lambda k: c_cost_ls[k])
st_d = sorted(range(len(d_cost_ls)), key=lambda k: d_cost_ls[k])
c_cost_ls = [c_cost_ls[i] for i in st_c]
c_beauty_ls = [c_beauty_ls[i] for i in st_c]
d_cost_ls = [d_cost_ls[i] for i in st_d]
d_beauty_ls = [d_beauty_ls[i] for i in st_d]
pre_max_beauty_c = [0] * len(c_beauty_ls)
pre_max_beauty_d = [0] * len(d_beauty_ls)
for i in range(0, len(c_beauty_ls)):
    if i == 0:
        pre_max_beauty_c[i] = c_beauty_ls[i]
    else:
        pre_max_beauty_c[i] = max(pre_max_beauty_c[i - 1], c_beauty_ls[i])
for i in range(0, len(d_beauty_ls)):
    if i == 0:
        pre_max_beauty_d[i] = d_beauty_ls[i]
    else:
        pre_max_beauty_d[i] = max(pre_max_beauty_d[i - 1], d_beauty_ls[i])

# one C and one D
ans_cd = 0
c_max_id = bisect_right(c_cost_ls, c) - 1
d_max_id = bisect_right(d_cost_ls, d) - 1
if c_max_id >= 0 and d_max_id >= 0:
    ans_cd = pre_max_beauty_c[c_max_id] + pre_max_beauty_d[d_max_id]


# two C
ans_cc = 0
for i in range(1, len(c_cost_ls)):
    if c_cost_ls[i] + c_cost_ls[0] > c:
        break
    max_cost_id = min(bisect_right(c_cost_ls, c - c_cost_ls[i]) - 1, i - 1)
    if 0 <= max_cost_id < i:
        ans_cc = max(ans_cc, c_beauty_ls[i] + pre_max_beauty_c[max_cost_id])


# two D
ans_dd = 0
for i in range(1, len(d_cost_ls)):
    if d_cost_ls[i] + d_cost_ls[0] > d:
        break
    max_cost_id = min(bisect_right(d_cost_ls, d - d_cost_ls[i]) - 1, i - 1)
    if 0 <= max_cost_id < i:
        ans_dd = max(ans_dd, d_beauty_ls[i] + pre_max_beauty_d[max_cost_id])

print(max(ans_cd, ans_cc, ans_dd))
