'''
https://codeforces.com/problemset/submission/1056/297221660
1056C
2024/12/19 Y1
1700
greedy, interative
'''
# 选完控场的选最大的即可
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    mp = {}
    for _ in range(m):
        x, y = map(int, input().split())
        x, y = x - 1, y - 1
        mp[x] = y
        mp[y] = x
    t = input() == '1'
    return n, m, a, mp, t

def solve(n: int, m: int, a, mp, t) -> None:
    vis = [False] * (n << 1)
    hero = 0
    for _ in range(n << 1):
        if t:
            if not hero:
                if m:
                    x, y = next(t for t in mp.items())
                    vis[x] = vis[y] = True
                    del mp[x]
                    del mp[y]
                    m -= 1
                    hero = x + 1 if a[x] > a[y] else y + 1
                else:
                    hero = max(range(n << 1), key=lambda i: 0 if vis[i] else a[i])
                    vis[hero] = True
                    hero += 1
            print(hero, flush=True)
        else:
            hero = 0
            x = int(input()) - 1
            vis[x] = True
            if x in mp:
                y = mp[x]
                vis[y] = True
                hero = y + 1
                del mp[x]
                del mp[y]
                m -= 1
        t = not t

if __name__ == '__main__':
    args = init()
    solve(*args)
