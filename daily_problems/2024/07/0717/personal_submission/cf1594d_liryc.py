'''
https://codeforces.com/contest/1594/submission/270965597
1594D
2024/7/17 Y1
1700
xor, graph, bfs
'''

from collections import deque

def init():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        x, y, z = input().split()
        a, b, c = int(x) - 1, int(y) - 1, z == "imposter"
        g[a].append((b, c))
        g[b].append((a, c))
    return n, m, g

def solve(n, m, g):
    a = [-1] * n
    ans = 0
    for i in range(n):
        if a[i] < 0:
            dq = deque()
            a[i] = 0
            k, c = 1, 0
            dq.append(i)
            while dq:
                i = dq.pop()
                for j, t in g[i]:
                    if a[j] >= 0:
                        if a[j] != a[i] ^ t:
                            return -1
                    else:
                        a[j] = a[i] ^ t
                        k += 1
                        c += a[j]
                        dq.append(j)
            ans += max(c, k - c)
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
