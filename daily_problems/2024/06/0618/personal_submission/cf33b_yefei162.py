# -*- coding: utf-8 -*-
import sys
import copy


def all_pairs_shortest_path(adjacency_matrix):
    new_array = copy.deepcopy(adjacency_matrix)

    for k in range(len(new_array)):
        for i in range(len(new_array)):
            for j in range(len(new_array)):
                if new_array[i][j] > new_array[i][k] + new_array[k][j]:
                    new_array[i][j] = new_array[i][k] + new_array[k][j]

    return new_array


input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../../input.txt', 'r')
I = lambda: int(input())
inf = 10 ** 18

s = input()
t = input()
n = I()
m1 = len(s)
m2 = len(t)
if m1 != m2:
    exit(print(-1))

mtx = [[inf for _ in range(26)] for _ in range(26)]
for i in range(n):
    u, v, w = input().split()
    u = ord(u) - ord('a')
    v = ord(v) - ord('a')
    mtx[u][v] = min(mtx[u][v], int(w))

for i in range(26):
    mtx[i][i] = 0

ret = ['#'] * m1
ans = 0
dis = all_pairs_shortest_path(mtx)
for i in range(m1):
    x = ord(s[i]) - ord('a')
    y = ord(t[i]) - ord('a')
    tmp = inf
    ret[i] = chr(x + ord('a'))
    for z in range(26):
        if dis[x][z] + dis[y][z] < tmp:
            tmp = dis[x][z] + dis[y][z]
            ret[i] = chr(z + ord('a'))
    ans += tmp

if ans < inf:
    print(ans)
    print(''.join(ret))
else:
    print(-1)
