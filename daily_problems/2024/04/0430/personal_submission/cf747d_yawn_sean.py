# Submission link: https://codeforces.com/contest/747/submission/258802692
def main():
    n, k = MII()
    nums = LII()

    tmp1 = []
    tmp2 = []

    cur = 0
    for num in nums:
        if num >= 0:
            cur += 1
        else:
            k -= 1
            tmp2.append(cur)
            cur = 0

    if tmp2: tmp1.append(cur)
    tmp2 = tmp2[1:]

    if k < 0:
        print(-1)
        exit()

    orig = 2 * (len(tmp1) + len(tmp2))
    ans = orig

    tmp1.sort()
    tmp2.sort()

    for i in range(len(tmp1) + 1):
        res = orig
        v = k
        for j in range(i):
            v -= tmp1[j]
            res -= 1
        if v < 0: break
        for x in tmp2:
            if v >= x:
                v -= x
                res -= 2
        ans = min(ans, res)

    print(ans)