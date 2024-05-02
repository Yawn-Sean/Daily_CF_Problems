# https://codeforces.com/contest/631/submission/259072173
def solve():
    n, m = [int(x) for x in input().split()]
    nums = [int(x) for x in input().split()]
    ope_r = [[int(x) for x in input().split()] for _ in range(m)]
    stack = []
    for ope, r in ope_r:
        while stack and stack[-1][1] <= r:
            stack.pop()
        stack.append((ope, r))
    vals = sorted(nums[: stack[0][1]])
    L, R = 0, len(vals) - 1
    stack.append((0, 0))
    for i, (ope, r) in enumerate(stack[:-1]):
        for idx in range(r - 1, stack[i + 1][1] - 1, -1):
            if ope == 2:
                nums[idx] = vals[L]
                L += 1
            else:
                nums[idx] = vals[R]
                R -= 1
    print(" ".join(str(x) for x in nums))


solve()
