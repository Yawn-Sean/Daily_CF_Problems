# Submission link: https://codeforces.com/gym/102448/submission/377618070
def main():
    n, x, y = MII()
    
    dis = []
    rs = []
    
    for _ in range(n):
        x0, y0, r0 = MII()
        x0 -= x
        y0 -= y
        dis.append(math.sqrt(x0 * x0 + y0 * y0) - r0)
        rs.append(r0)
    
    ans = 0
    cur = 0
    
    for i in sorted(range(n), key=lambda x: dis[x]):
        ans = fmax(ans, dis[i] - cur)
        cur += rs[i]
    
    print(ans)