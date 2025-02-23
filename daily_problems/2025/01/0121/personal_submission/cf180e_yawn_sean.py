# Submission link: https://codeforces.com/contest/180/submission/302156166
def main():
    n, m, k = MII()
    nums = LII()

    pos = defaultdict(list)
    for i in range(n):
        pos[nums[i]].append(i)

    l, r = 1, n
    while l <= r:
        mid = (l + r) // 2
        flg = False
        
        for v in pos.values():
            length = len(v)
            for i in range(length):
                if i + mid - 1 < length and v[i + mid - 1] - v[i] - (mid - 1) <= k:
                    flg = True
        
        if flg: l = mid + 1
        else: r = mid - 1

    print(r)