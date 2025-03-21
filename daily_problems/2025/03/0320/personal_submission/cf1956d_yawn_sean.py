# Submission link: https://codeforces.com/contest/1956/submission/311465312
def main():
    n = II()
    nums = LII()

    dp = [0] * (n + 1)
    prev = [-1] * (n + 1)

    for i in range(1, n + 1):
        for j in range(i):
            v = dp[j] + (i - j) * (i - j)
            if v > dp[i]:
                dp[i] = v
                prev[i] = j
        
        v = dp[i - 1] + nums[i - 1]
        if v > dp[i]:
            dp[i] = v
            prev[i] = i - 1

    ops = []

    def mex(l, r):
        vis = set()
        for i in range(l, r):
            vis.add(nums[i])
        for i in range(n + 1):
            if i not in vis:
                return i
        return -1

    def op(l, r):
        ops.append(f'{l + 1} {r}')
        v = mex(l, r)
        for i in range(l, r):
            nums[i] = v
        return v

    def set_zero(l, r):
        if op(l, r):
            op(l, r)

    def mid_process(l, r):
        if l + 1 == r:
            set_zero(l, r)
            return
        mid_process(l, r - 1)
        op(l, r)
        mid_process(l, r - 1)

    def process(l, r):
        set_zero(l, r)
        mid_process(l, r)
        op(l, r)

    cur = n
    while cur:
        p = prev[cur]
        if p < cur - 1 or nums[p] == 0:
            process(p, cur)
        cur = p

    print(dp[n], len(ops))
    print('\n'.join(ops))