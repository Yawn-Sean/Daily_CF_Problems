# Submission link: https://codeforces.com/gym/105505/submission/375640501
def main():
    n, t = MII()
    
    pr = list(range(n))
    pc = list(range(n))
    
    for _ in range(t):
        c, i, j = LI()
        i = int(i) - 1
        j = int(j) - 1
        
        if c == 'R': pr[i], pr[j] = pr[j], pr[i]
        else: pc[i], pc[j] = pc[j], pc[i]
    
    vis_r = [0] * n
    groups_r = []
    
    for i in range(n):
        if not vis_r[i]:
            cur = i
            group = []
            
            while not vis_r[cur]:
                vis_r[cur] = 1
                group.append(cur)
                cur = pr[cur]
            
            groups_r.append(group)
    
    vis_c = [0] * n
    groups_c = []
    
    for i in range(n):
        if not vis_c[i]:
            cur = i
            group = []
            
            while not vis_c[cur]:
                vis_c[cur] = 1
                group.append(cur)
                cur = pc[cur]
            
            groups_c.append(group)
    
    m = len(groups_r)
    k = len(groups_r[0])
    
    for x in groups_r:
        if len(x) != k:
            exit(print('*'))
    
    for x in groups_c:
        if len(x) != k:
            exit(print('*'))
    
    grid = [[0] * n for _ in range(n)]
    
    for i in range(m):
        for j in range(m):
            start = (i + j) % m * k + 1
            
            for vi in range(k):
                for vj in range(k):
                    grid[groups_r[i][vi]][groups_c[j][vj]] = start + (vi - vj) % k
    
    print('\n'.join(' '.join(map(str, x)) for x in grid))