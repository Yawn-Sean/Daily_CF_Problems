'''
https://codeforces.com/problemset/submission/1722/301737423
1722E
2025/01/18 Y1
1600
前缀和
'''
# 二维前缀和
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, q = map(int, input().split())
    a = [tuple(map(int, input().split())) for _ in range(n)]
    qa = [tuple(map(int, input().split())) for _ in range(q)]
    return n, q, a, qa

def solve(n, q, a, qa):
    a.sort()
    i = 0
    ps = [[0] * 1001 for _ in range(1001)]
    for h in range(1, 1001):
        for w in range(1, 1001):
            ps[h][w] = ps[h][w - 1]
            while i < len(a) and a[i][0] == h and a[i][1] == w:
                ps[h][w] += h * w
                i += 1
        for w in range(1001):
            ps[h][w] += ps[h - 1][w]

    def query(h1, w1, h2, w2):
        nonlocal ps
        return ps[h2 - 1][w2 - 1] - ps[h1][w2 - 1] - ps[h2 - 1][w1] + ps[h1][w1]
    
    return [query(h1, w1, h2, w2) for h1, w1, h2, w2 in qa]

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(*ans, sep='\n')
