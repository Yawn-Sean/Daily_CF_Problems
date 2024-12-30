# Submission Link: https://codeforces.com/contest/622/submission/271097339
def main():
    n, q = MII()
    nums = LII()

    lefts = list(range(n))

    for i in range(1, n):
        if nums[i] == nums[i-1]:
            lefts[i] = lefts[i-1]

    outs = []
    for _ in range(q):
        l, r, x = MII()
        l -= 1
        r -= 1
        if nums[r] != x:
            outs.append(r + 1)
        else:
            outs.append(lefts[r] if lefts[r] - 1 >= l else -1)

    print('\n'.join(map(str, outs)))