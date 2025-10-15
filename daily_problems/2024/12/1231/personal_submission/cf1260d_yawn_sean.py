# Submission link: https://codeforces.com/contest/1260/submission/299120637
def main():
    m, n, k, t = MII()
    nums = LII()

    ls = []
    rs = []
    ds = []

    for _ in range(k):
        l, r, d = MII()
        ls.append(l)
        rs.append(r)
        ds.append(d)

    nums.sort(reverse=True)

    l, r = 1, m
    diff = [0] * (n + 1)

    while l <= r:
        mid = (l + r) // 2

        for i in range(k):
            if nums[mid - 1] < ds[i]:
                diff[ls[i] - 1] += 1
                diff[rs[i]] -= 1
        
        res = n + 1
        cur = 0
        for i in range(n + 1):
            cur += diff[i]
            if cur: res += 2
            diff[i] = 0
        
        if res > t: r = mid - 1
        else: l = mid + 1

    print(r)