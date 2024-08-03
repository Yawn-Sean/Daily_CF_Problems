# Submission link: https://codeforces.com/contest/1114/submission/258041835
def main():
    n, b = MII()
    prime_factorization = []

    for i in range(2, b + 1):
        if i * i > b: break
        if b % i == 0:
            cnt = 0
            while b % i == 0:
                cnt += 1
                b //= i
            prime_factorization.append((i, cnt))

    if b > 1: prime_factorization.append((b, 1))

    ans = inf
    for p, c in prime_factorization:
        cur = n
        cnt = 0
        while cur:
            cur //= p
            cnt += cur
        ans = min(ans, cnt // c)

    print(ans)