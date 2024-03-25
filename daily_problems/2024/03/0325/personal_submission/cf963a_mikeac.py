import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    MOD = 10 ** 9 + 9
    n, a, b, k = mint()
    s = input()

    ans = 0
    v = pow(a, n, MOD)
    # b_a = b * pow(a, -1, MOD) % MOD
    b_a = b * pow(a, MOD - 2, MOD) % MOD
    b_a_k = pow(b_a, k, MOD)
    
    x, y = divmod(n + 1, k)
    for i in range(k):
        cnt = x + 1 if i < y else x
        if b_a_k == 1:
            res = cnt * v % MOD
        else:
            res = v * (pow(b_a_k, cnt, MOD) - 1) % MOD * pow(b_a_k - 1, MOD - 2, MOD) % MOD

        ans += res if s[i] == '+' else -res
        ans %= MOD

        v = v * b_a % MOD

    print(ans)

solve()
