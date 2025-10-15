# Submission link: https://codeforces.com/contest/982/submission/289998393
def main():
    n = II()
    nums = LII()

    st_range = sorted(range(n), key=lambda x: nums[x])
    union = UnionFind(n)

    cur = -1
    locations = 0

    vis = [0] * n
    cnt = [0] * (n + 1)

    total = 0

    for p in st_range:
        
        if p > 0 and vis[p - 1]:
            sz = union.getSize(p - 1)
            cnt[sz] -= 1
            union.merge(p, p - 1)
            total -= 1
        
        if p + 1 < n and vis[p + 1]:
            sz = union.getSize(p + 1)
            cnt[sz] -= 1
            union.merge(p, p + 1)
            total -= 1
        
        vis[p] = 1
        
        sz = union.getSize(p)
        cnt[sz] += 1
        total += 1
        
        if cnt[sz] == total and total > locations:
            cur = nums[p] + 1
            locations = total

    print(cur)