import sys
from array import array

input = lambda: sys.stdin.readline().rstrip()


MOD = 998244353
n = int(input())

pow2 = array('i', [0] * (n + 1))
pow2[0] = 1
for i in range(1, n + 1):
    x = pow2[i - 1] << 1
    if x >= MOD:
        x -= MOD
    pow2[i] = x

a = list(map(lambda s: int(s) - 1, input().split()))
pos = array('i', [0] * n)
for i, x in enumerate(a):
    pos[x] = i


vis = bytearray(n)


def bfs(st: int, k: int) -> bool:
    ok = True
    vis[st] = 1
    p = [st]
    while p:
        u = p.pop()
        v = u - k
        if v < 0:
            ok = False
        else:
            v = pos[v]
            if not vis[v]:
                vis[v] = 1
                p.append(v)
        v = a[u] + k
        if v >= n:
            ok = False
        else:
            if not vis[v]:
                vis[v] = 1
                p.append(v)
    return ok


ans = 0
for k in range(n):
    vis = bytearray(n)
    cnt = 0
    for i in range(n):
        if not vis[i]:
            if bfs(i, k):
                cnt += 1
    ans += pow2[cnt] - 1

print(ans % MOD)


"""
有点卡常, 最后把 deque(队列) 换成了 list(普通的栈)
然后把 array('b') 换成了 bytearray 才过
"""
