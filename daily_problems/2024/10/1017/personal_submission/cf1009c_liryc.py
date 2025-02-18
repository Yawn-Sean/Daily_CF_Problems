'''
https://codeforces.com/problemset/submission/1009/286310116
1009C
2024/10/17 Y1
1700
'''
# ref
def solve():
    n, q = map(int, input().split())

    v1 = n * (n - 1) // 2
    v2 = sum(abs(i - n // 2) for i in range(n))

    ans = 0
    tot = 0

    for _ in range(q):
        x, y = map(int, input().split())
        ans += x
        tot += y * (v1 if y >= 0 else v2)

    return ans + tot / n

if __name__ == '__main__':
    ans = solve()
    print(ans)