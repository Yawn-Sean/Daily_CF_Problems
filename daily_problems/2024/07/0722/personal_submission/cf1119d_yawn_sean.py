# Submission Link: https://codeforces.com/contest/1119/submission/271838962
def main():
    n = II()
    nums = LII()
    nums.sort()

    vals = [nums[i+1] - nums[i] for i in range(n - 1)]
    vals.append(10 ** 18 + 1)
    vals.sort()

    acc = list(accumulate(vals, initial=0))

    q = II()
    outs = []

    for _ in range(q):
        l, r = MII()
        x = r - l + 1
        p = bisect.bisect_right(vals, x)
        outs.append(acc[p] + (n - p) * x)

    print(' '.join(map(str, outs)))