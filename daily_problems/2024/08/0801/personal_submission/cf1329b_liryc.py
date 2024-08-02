'''
https://codeforces.com/contest/1329/submission/273851040
1329 B
2024/8/1 Y1
1700
math
'''

def init():
    d, m = map(int, input().split())
    return d, m

def solve(d: int, m: int) -> int:
    ans = 1
    b = 1
    while b <= d:
        ans *= min(b, d - b + 1) + 1
        b <<= 1
    return (ans - 1) % m

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
