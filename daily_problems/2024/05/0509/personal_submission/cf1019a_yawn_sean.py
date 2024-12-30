# Submission link: https://codeforces.com/contest/1019/submission/260058940
def main():
    n, m = MII()

    parties = []
    costs = []

    for _ in range(n):
        p, c = MII()
        parties.append(p - 1)
        costs.append(c)

    st_range = sorted(range(n), key=lambda x: costs[x], reverse=True)
    used = [0] * n
    cnt = [0] * m

    ans = inf

    for max_votes in range(0, n + 1):
        cnt_votes = 0
        res = 0
        for i in st_range:
            if parties[i] == 0:
                cnt_votes += 1
            else:
                if cnt[parties[i]] < max_votes:
                    cnt[parties[i]] += 1
                    used[i] = 1
                else:
                    cnt_votes += 1
                    res += costs[i]
        
        for i in range(n - 1, -1, -1):
            if cnt_votes <= max_votes and used[st_range[i]]:
                res += costs[st_range[i]]
                cnt_votes += 1
            used[st_range[i]] = 0
            cnt[parties[i]] = 0
        
        ans = min(ans, res)

    print(ans)