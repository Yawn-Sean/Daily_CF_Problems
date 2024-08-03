# Submission link: https://codeforces.com/contest/226/submission/255555189
def main():
    n = II()
    nums = LII()
    nums.sort(reverse=True)
    acc = list(accumulate(nums, initial=0))

    ans = [0] * (n + 1)
    for i in range(1, n + 1):
        pt = 1
        cur = i
        weight = 1
        while pt < n:
            ans[i] += (acc[min(pt + cur, n)] - acc[pt]) * weight
            pt += cur
            cur *= i
            weight += 1

    q = II()
    print(' '.join(str(ans[min(x, n)]) for x in MII()))