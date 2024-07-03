# Submission link: https://codeforces.com/contest/524/submission/264988911
def main():
    n, k = MII()
    nums = LII()

    d = defaultdict(list)

    for c in range(1, k + 1):
        for i in range(n):
            d[c * nums[i]].append(i)

    sorted_one_coins = sorted(d.keys())

    q = II()
    outs = []

    for _ in range(q):
        x = II()
        ans = k + 1
        for v in sorted_one_coins:
            if v * 2 > x: break
            for i1 in d[v]:
                for i2 in d[x - v]:
                    if i1 != i2:
                        res = v // nums[i1] + (x - v) // nums[i2]
                        if res < ans: ans = res
        if x in sorted_one_coins:
            ans = min(ans, x // nums[d[x][0]])
        outs.append(ans if ans < k + 1 else -1)

    print('\n'.join(map(str, outs)))