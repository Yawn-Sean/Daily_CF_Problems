# Submission link: https://codeforces.com/contest/802/submission/263815241
def main():
    n, k = MII()
    ids = LGMI()

    next_pos = [n] * n
    pos = [n] * n

    for i in range(n - 1, -1, -1):
        next_pos[i] = pos[ids[i]]
        pos[ids[i]] = i

    hpq = []
    cnt = 0
    vis = [0] * n
    ans = 0

    for i in range(n):
        while hpq and vis[hpq[0] % n] == 0:
            heappop(hpq)
        
        if vis[ids[i]] == 0:
            if cnt == k:
                vis[heappop(hpq) % n] = 0
                cnt -= 1
            vis[ids[i]] = 1
            
            heappush(hpq, -next_pos[i] * n + ids[i])
            cnt += 1
            ans += 1
        
        heappush(hpq, -next_pos[i] * n + ids[i])

    print(ans)
