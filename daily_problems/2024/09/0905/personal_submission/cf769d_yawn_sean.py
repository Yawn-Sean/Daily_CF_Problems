# Submission link: https://codeforces.com/contest/769/submission/279871535
def main():
    n, k = MII()
    nums = LII()

    cnt = [0] * (1 << 14)
    for num in nums:
        cnt[num] += 1

    if k == 0:
        print(sum(x * (x - 1) // 2 for x in cnt))
    else:
        vals = [i for i in range(1 << 14) if i.bit_count() == k]
        ans = 0
        for i in range(1 << 14):
            for v in vals:
                ans += cnt[i] * cnt[i ^ v]
        print(ans // 2)