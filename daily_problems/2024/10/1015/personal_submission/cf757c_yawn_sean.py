# Submission link: https://codeforces.com/contest/757/submission/285970850
def main():
    n, m = MII()
    tmp = [0] * m

    pw = random.randint(10 ** 5 + 5, 2 * 10 ** 5 + 5)
    md = random.getrandbits(46)

    for idx in range(1, n + 1):
        g, *nums = MII()
        for i in range(g):
            v = nums[i] - 1
            tmp[v] = tmp[v] * pw % md + idx
            if tmp[v] >= md: tmp[v] -= md

    mod = 10 ** 9 + 7
    ans = 1
    for v in Counter(tmp).values():
        for i in range(1, v + 1):
            ans = ans * i % mod

    print(ans)