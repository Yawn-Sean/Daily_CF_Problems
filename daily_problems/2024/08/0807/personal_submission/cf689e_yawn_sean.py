# Submission link: https://codeforces.com/contest/689/submission/275000312
def main():
    mod = 10 ** 9 + 7

    n, k = MII()
    fact = Factorial(n, mod)

    rnd = random.getrandbits(20)
    diff = Counter()
    for _ in range(n):
        l, r = MII()
        diff[l + rnd] += 1
        diff[r + 1 + rnd] -= 1

    seps = sorted(diff)

    cur = 0
    ans = 0
    for i in range(len(seps) - 1):
        cur += diff[seps[i]]
        ans += (seps[i+1] - seps[i]) * fact.combi(cur, k) % mod

    print(ans % mod)