import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1082/D

给定一个由 $n$ 个整数 $a_1, a_2, a_n$ 组成的序列，构建一个由 $n$ 个顶点组成的**连通无向**图，使得：

- 该图不包含自循环和多重边；
- $i$ 个顶点的 $d_i$ 度不超过 $a_i$ （即 $d_i e a_i$ ）；
- 图的直径尽可能最大。
输出结果图或报告无解。

思路：
考虑极端情况，所有点都在一条直线肯定最优，但是要求中间的点d = 2
那么d = 1的只能放在端点，所以考虑d = 1的要么放第一个，要么往后放，d > 1的放中间，构造一个最长的直径，
按照d排序，能放在直径上的就放在直径上，如果直径最后一个点的可用度为0了，那就找最前面还有剩余度的点连，一个点连满了就连下一个有剩余度的点。
'''
n = RI()
a = RILIST()
b = sorted(range(n),key=lambda x: -a[x])
ori = a[b[0]]
d, left = 0, 0 # left记录有多余的度的点的id
ans = []
for i in range(1, n):
    if left >= i:
        print('NO')
        break
    # 直径上还能放，就放到直径上
    if a[b[i - 1]]:
        ans.append((b[i - 1] + 1, b[i] + 1))
        a[b[i - 1]] -= 1
        a[b[i]] -= 1
        d += 1
    else:
        # 找前面多余度的点连
        ans.append((b[left] + 1, b[i] + 1))
        a[b[left]] -= 1
        a[b[i]] -= 1
    
    while left < n and a[b[left]] == 0:
        left += 1
else:
    if a[b[0]] < ori - 1: # 第一个点前面还有其他点
        d += 1
    print('YES', d)
    print(len(ans))
    for u, v in ans:
        print(u, v)