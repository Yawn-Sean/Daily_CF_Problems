import sys

MOD = 10**9 + 7


def solve(n: int) -> str:
    m = (n - 1) // 2 + 1
    ans = (n - m) * (n - m - 1) * 3 % MOD
    ans = ans * pow((n - 1) * (n - 2), MOD - 2, MOD) % MOD
    ans = 1 - ans
    if ans < 0:
        ans += MOD
    return str(ans)


it = iter(sys.stdin.buffer.read().split())
next(it)
print('\n'.join(solve(int(s)) for s in it))
