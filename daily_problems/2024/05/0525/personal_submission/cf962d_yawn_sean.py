# Submission link: https://codeforces.com/contest/962/submission/262492744
def main():
    n = II()
    nums = LII()

    hpq = [nums[i] * n + i for i in range(n)]
    heapify(hpq)

    ans = [-1] * n
    while hpq:
        x1, i1 = divmod(heappop(hpq), n)
        if hpq and hpq[0] // n == x1:
            i2 = heappop(hpq) % n
            x1 *= 2
            heappush(hpq, x1 * n + i2)
        else:
            ans[i1] = x1

    ans = [str(x) for x in ans if x != -1]
    print(len(ans))
    print(' '.join(ans))