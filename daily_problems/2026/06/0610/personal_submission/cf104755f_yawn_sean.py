# Submission link: https://codeforces.com/gym/104755/submission/377874513
def main():
    n, m = MII()
    holes = LII()
    targets = LII()
    
    rnd = random.getrandbits(20)
    d = {v ^ rnd: i for i, v in enumerate(targets)}
    
    mi = min(holes)
    
    ans = []
    vis = [0] * m
    
    for v in targets:
        flg = True
        
        for x in holes:
            if (v + 2 * (x - mi)) ^ rnd not in d:
                flg = False
        
        if flg:
            ans.append(2 * mi - v)
            for x in holes:
                vis[d[(v + 2 * (x - mi)) ^ rnd]] = 1
    
    if min(vis):
        print('Yes')
        print(len(ans))
        print(*ans)
    else:
        print('No')