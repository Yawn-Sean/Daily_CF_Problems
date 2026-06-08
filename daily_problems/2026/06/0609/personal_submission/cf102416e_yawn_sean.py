# Submission link: https://codeforces.com/gym/102416/submission/377743843
def main():
    n = II()
    xs = []
    ys = []
    zs = []
    rs = []
    
    for _ in range(n):
        x, y, z, r = MII()
        xs.append(x)
        ys.append(y)
        zs.append(z)
        rs.append(r)
    
    ans = []
    for i in sorted(range(n), key=lambda x: -rs[x]):
        flg = True
        
        for j in ans:
            dx = xs[j] - xs[i]
            dy = ys[j] - ys[i]
            dz = zs[j] - zs[i]
            totr = rs[j] + rs[i]
            
            if dx * dx + dy * dy + dz * dz < totr * totr:
                flg = False
        
        if flg:
            ans.append(i)
    
    print(len(ans))
    print(*(x + 1 for x in ans))