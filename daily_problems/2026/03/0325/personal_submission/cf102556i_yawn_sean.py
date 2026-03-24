# Submission link: https://codeforces.com/gym/102556/submission/368024374
def main(): 
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    pre = [[0] * n for _ in range(n)]
    
    def is_in(to_check, i, j, k):
        x, y = xs[to_check], ys[to_check]
        x1, y1 = xs[i], ys[i]
        x2, y2 = xs[j], ys[j]
        x3, y3 = xs[k], ys[k]
        
        return (x2 - x1) * (y - y1) > (x - x1) * (y2 - y1) and\
            (x3 - x2) * (y - y2) > (x - x2) * (y3 - y2) and\
            (x1 - x3) * (y - y3) > (x - x3) * (y1 - y3)
    
    for i in range(1, n):
        for j in range(i + 1, n):
            for k in range(1, n):
                if k != i and k != j and (is_in(k, 0, i, j) or is_in(k, 0, j, i)):
                    pre[i][j] += 1
    
    def area(x, y):
        x1, y1 = xs[x] - xs[0], ys[x] - ys[0]
        x2, y2 = xs[y] - xs[0], ys[y] - ys[0]
        return pre[x][y] if x1 * y2 > x2 * y1 else -pre[x][y]
    
    ans = 0
    
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                cnt = abs(area(i, j) + area(j, k) - area(i, k))
                if is_in(0, i, j, k) or is_in(0, i, k, j):
                    cnt += 1
                elif is_in(i, 0, j, k) or is_in(i, 0, k, j):
                    cnt -= 1
                elif is_in(j, 0, i, k) or is_in(j, 0, k, i):
                    cnt -= 1
                elif is_in(k, 0, i, j) or is_in(k, 0, j, i):
                    cnt -= 1
                ans += math.comb(cnt, 3)
    
    print(ans)