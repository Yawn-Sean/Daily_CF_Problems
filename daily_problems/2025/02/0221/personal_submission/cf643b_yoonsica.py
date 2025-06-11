import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/643/B
n个点，最多k条边，构造一个图，使得a到b，c到d各有一条路径经过所有点恰好一次
ab，cd不直接相连

7 11
2 4 7 3

a,b,c,d不同，至少加两条边
'''
n, k = RII()
a, b, c, d = RII()
if n == 4 or k < n + 1:
    print(-1)
else:
    t = []
    for i in range(1, n + 1):
        if i not in (a, b, c, d):
            t.append(i)
    ans = [a, c] + t + [d, b]
    print(' '.join(map(str, ans)))
    ans = [c, a] + t + [b, d]
    print(' '.join(map(str, ans)))