# Submission link: https://codeforces.com/contest/911/submission/313673257
def main():
    n, k = MII()
    nums = LII()

    cur = 1

    stk = [n + 1]
    for v in nums:
        stk.append(v)
        
        while stk and stk[-1] == cur:
            stk.pop()
            cur += 1

    stk.append(cur - 1)

    for i in range(len(stk) - 1, 0, -1):
        if stk[i - 1] < stk[i]:
            exit(print(-1))
        
        for j in range(stk[i - 1] - 1, stk[i], - 1):
            nums.append(j)

    print(' '.join(map(str, nums)))