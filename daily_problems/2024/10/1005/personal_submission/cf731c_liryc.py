'''
https://codeforces.com/contest/731/submission/284390859
731C
2024/10/5 Y1
1600
UnionFind
'''

from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()

# class UnionFind:

if __name__ == '__main__':
    n, m, k = map(int, input().split())
    colors = list(map(lambda s: int(s) - 1, input().split()))

    uni = UnionFind(n)

    for _ in range(m):
        u, v = map(lambda s: int(s) - 1, input().split())
        uni.union(u, v)

    di = {}
    for i in range(n):
        j = uni.find(i)
        if not j in di:
            di[j] = Counter()
        di[j][colors[i]] += 1

    ans = n
    for k, c in di.items():
        ans -= c.most_common(1)[0][1]

    print(ans)
