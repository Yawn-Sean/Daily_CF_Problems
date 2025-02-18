'''
https://codeforces.com/contest/873/submission/279425899
873D
2024/9/3 Y1
1800
implementation
'''

def init():
    n, k = map(int, input().split())
    return n, k

def solve(n: int, k: int) -> list[int]:
    ans = [0] * n

    def dfs(l: int, r: int, s: int, c: int) -> int:
        nonlocal ans
        if c == 0 or r - l <= 1:
            ans[l:r] = range(s, s + r - l)
        elif c > 0:
            c -= 2
            m = l + r >> 1
            c = dfs(l, m, s + r - m, c)
            c = dfs(m, r, s, c)
        return c
    
    c = dfs(0, n, 1, k - 1)
    if c != 0:
        return []
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans:
        print(*ans)
    else:
        print(-1)
