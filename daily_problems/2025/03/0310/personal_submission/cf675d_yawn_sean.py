# Submission link: https://codeforces.com/problemset/submission/675/309689216#
def main():
    rnd = random.getrandbits(30)

    n = II()
    nums = [x + rnd for x in MII()]

    d = {v: i for i, v in enumerate(sorted(nums))}

    inf = n * 10 ** 6
    segmi = SegTree(fmin, inf, n)
    segma = SegTree(fmax, 0, n)

    p = d[nums[0]]
    segmi.set(p, p * n)
    segma.set(p, p * n)

    ans = []

    for i in range(1, n):
        p = d[nums[i]]
        cur = fmax(segmi.prod(p, n) % n, segma.prod(0, p) % n)
        ans.append(nums[cur] - rnd)
        segmi.set(p, p * n + i)
        segma.set(p, p * n + i)

    print(*ans)