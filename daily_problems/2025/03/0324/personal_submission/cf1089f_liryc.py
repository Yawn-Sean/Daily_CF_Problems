'''
https://codeforces.com/problemset/submission/1089/312181424
'''
def solve(n: int) -> list[str]:
    for i in range(2, 40000 if n > 40000 else n):
        if n % i == 0 and gcd(i, n // i) == 1:
            x, y = i, n // i
            for j in range(1, x):
                if (n - 1 - j * y) % x == 0:
                    z = (n - 1 - j * y) // x
                    return [f"{z} {y}", f"{j} {x}"]
    return []
