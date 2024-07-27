'''
https://codeforces.com/contest/1660/submission/272646664
1660E
2024/7/26 Y1
1600
grid
'''

def init():
    input()
    n = int(input())
    a = []
    for _ in range(n):
        a.append(input())
    return n, a

def solve(n: int, a: list[str]) -> int:
    cn = sum(r.count('1') for r in a)
    ma = max(sum(int(a[i][(j + i) % n]) for i in range(n)) for j in range(n))
    return (cn - ma) + (n - ma) 

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)