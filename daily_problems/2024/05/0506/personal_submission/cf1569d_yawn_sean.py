# Submission link: https://codeforces.com/contest/1569/submission/259689979
def main():
    n, m, k = MII()
    
    xs = LII()
    ys = LII()
    
    cnt_x = [0] * n
    cnt_y = [0] * m
    cnt_x_counter = [Counter() for _ in range(n)]
    cnt_y_counter = [Counter() for _ in range(m)]
    
    for _ in range(k):
        x, y = MII()
        
        px = bisect.bisect_left(xs, x)
        py = bisect.bisect_left(ys, y)
        
        if xs[px] == x and ys[py] == y:
            continue
        
        if xs[px] == x:
            cnt_y[py] += 1
            cnt_x_counter[px][py] += 1
        else:
            cnt_x[px] += 1
            cnt_y_counter[py][px] += 1
    
    ans = 0
    for i in range(n):
        ans += cnt_x[i] * (cnt_x[i] - 1) // 2
        for v in cnt_x_counter[i].values():
            ans -= v * (v - 1) // 2
    
    for i in range(m):
        ans += cnt_y[i] * (cnt_y[i] - 1) // 2
        for v in cnt_y_counter[i].values():
            ans -= v * (v - 1) // 2
    
    print(ans)