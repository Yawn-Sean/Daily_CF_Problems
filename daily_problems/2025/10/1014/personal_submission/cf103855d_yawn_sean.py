# Submission link: https://codeforces.com/gym/103855/submission/343478742
def main():
    n = II()
    xs = []
    ys = []
    vs = []
    
    for _ in range(n):
        x, y, v = MII()
        xs.append(x)
        ys.append(y)
        vs.append(v)
    
    def solve():
        cnt = [0] * (10 ** 6 + 1)
        for i in range(n):
            cnt[ys[i]] += vs[i]
    
        higher_ys_order = sorted((i for i in range(10 ** 6 + 1) if cnt[i]), key=lambda x: -cnt[x]) + [i for i in range(10 ** 6 + 1) if cnt[i] == 0]
        
        res = 0
        for i in range(3):
            res += cnt[higher_ys_order[i]]
        
        tmp = [[] for _ in range(10 ** 6 + 1)]
        for i in range(n):
            tmp[xs[i]].append(i)
        
        for x in range(10 ** 6 + 1):
            cur = 0
            for idx in tmp[x]:
                cur += vs[idx]
                cnt[ys[idx]] -= vs[idx]
            
            v1, v2 = 0, 0
            for idx in range(len(tmp[x]) + 2):
                val = cnt[higher_ys_order[idx]]
                if val > v1: v1, v2 = val, v1
                elif val > v2: v2 = val
            
            res = fmax(res, cur + v1 + v2)
            
            for idx in tmp[x]:
                cnt[ys[idx]] += vs[idx]
        
        return res
    
    ans = solve()
    
    for i in range(n):
        xs[i], ys[i] = ys[i], xs[i]
    
    ans = fmax(ans, solve())
    
    print(ans)