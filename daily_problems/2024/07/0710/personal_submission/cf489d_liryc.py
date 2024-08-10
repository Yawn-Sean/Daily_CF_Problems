'''
https://codeforces.com/contest/489/submission/269648559
489D
2024/7/10 Y1
1700
graph
'''

def init():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        g[a].append(b)
    return g

def solve(g):
    n = len(g)
    ans = 0
    for a in range(n):
        cn = [0] * n
        for b in g[a]:
            for c in g[b]:
                if c != a:
                    cn[c] += 1
        ans += sum(x * (x - 1) >> 1 for x in cn)
    return ans

if __name__ == '__main__':
    g = init()
    ans = solve(g)
    print(ans)

''' version 1 - TLE
def init():
    n, m = map(int, input().split())
    g = [([], []) for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        g[b][0].append(a)
        g[a][1].append(b)
    return g

def solve(g):
    cn = Counter()
    for ia, oa in g:
        for a in ia:
            for b in oa:
                if a != b:
                    cn[(a, b)] += 1
    return sum(n * (n - 1) >> 1 for n in cn.values())
'''