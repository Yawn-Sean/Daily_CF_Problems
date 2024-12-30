def main(ac=FastIO()):
    """
    problem: https://codeforces.com/problemset/problem/131/F
    submission: https://codeforces.com/contest/131/submission/266515233
    """
    n, m, k = ac.read_list_ints()
    a = [list(map(int, list(ac.read_str()))) for _ in range(n)]

    if n < 3 or m < 3 or (n - 2) * (m - 2) <= k: 
        ac.st(int((n - 2) * (m - 2) == k and n >= 3 and m >= 3))
        return 

    is_star = [[0] * m for _ in range(n)]
    dirs = [(-1, 0), (0, 1), (0, -1), (1, 0)]
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            if a[i][j] == 0: continue
            cnt = 0
            for di, dj in dirs: 
                cnt += a[i + di][j + dj]         
            is_star[i][j] = int(cnt == 4)
    
    ans = 0

    for lx in range(n):
        cnt = [0] * m 
        for ly in range(lx + 2, n):
            for j in range(m):
                cnt[j] += is_star[ly - 1][j]
        
            l = r = 1 
            cur = 0
            while l < m - 1: 
                while r < m - 1 and cur < k: 
                    cur += cnt[r]
                    r += 1 
                if cur < k: break
                ans += m - r 
                cur -= cnt[l]
                l += 1 
    ac.st(ans)
