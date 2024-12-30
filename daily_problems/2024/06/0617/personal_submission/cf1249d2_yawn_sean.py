# Submission link: https://codeforces.com/contest/1249/submission/266124461
def main():
    n, k = MII()

    rs = []
    segs_l = [[] for _ in range(2 * 10 ** 5 + 2)]
    segs_r = [[] for _ in range(2 * 10 ** 5 + 2)]

    for i in range(n):
        l, r = MII()
        rs.append(r)
        segs_l[l].append(i)
        segs_r[r+1].append(i)

    msk = 2 * 10 ** 5 + 5

    hpq = []
    cur_used = [0] * n
    cur_size = 0

    ans = []

    for i in range(2 * 10 ** 5 + 1):
        for idx in segs_l[i]:
            cur_used[idx] = 1
            cur_size += 1
            heappush(hpq, -rs[idx] * msk + idx)
        
        for idx in segs_r[i]:
            cur_size -= cur_used[idx]
            cur_used[idx] = 0
        
        while cur_size > k:
            idx = heappop(hpq) % msk
            if cur_used[idx]:
                cur_size -= 1
                cur_used[idx] = 0
                ans.append(idx)

    print(len(ans))
    print(' '.join(str(x + 1) for x in ans))
