# Submission link: https://codeforces.com/gym/106124/submission/362017910
def main(): 
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    def dis(i, j):
        x1, y1 = xs[i], ys[i]
        x2, y2 = xs[j], ys[j]
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)
    
    idx = 0
    for i in range(n):
        if dis(0, i) > dis(0, idx):
            idx = i
    
    st_range = sorted(range(n), key=lambda x: dis(idx, x))
    
    ans = 0
    for i in range(1, n):
        ans += math.sqrt(dis(st_range[i - 1], st_range[i]))
    
    print(ans)