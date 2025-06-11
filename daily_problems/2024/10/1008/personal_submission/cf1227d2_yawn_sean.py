# Submission link: https://codeforces.com/contest/1227/submission/284851065
def main():
    n = II()
    nums = LII()
    st_range = sorted(range(n), key=lambda x: -nums[x])

    xs = []
    queries = [[] for _ in range(n)]

    q = II()
    for i in range(q):
        k, x = MII()
        queries[k - 1].append(i)
        xs.append(x)

    ans = [-1] * q
    fen = FenwickTree(n)

    for i in range(n):
        fen.add(st_range[i], 1)
        
        for q_id in queries[i]:
            ans[q_id] = nums[fen.bisect_min_larger(xs[q_id])]

    print('\n'.join(map(str, ans)))