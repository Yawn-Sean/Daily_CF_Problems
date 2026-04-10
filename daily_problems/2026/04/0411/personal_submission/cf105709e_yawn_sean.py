# Submission link: https://codeforces.com/gym/105709/submission/370540142
def main(): 
    n, k, q = MII()
    strs = [[ord(c) - ord('a') for c in I()] for _ in range(n)]
    
    vis = [0] * k
    cur = 1
    
    uf = UnionFind(n)
    outs = []
    
    for _ in range(q):
        query = LII()
        
        if query[0] == 1:
            idx = query[1] - 1
            
            if not vis[idx]:
                vis[idx] = 1
                tmp = [-1] * 10
                
                for i in range(n):
                    if tmp[strs[i][idx]] != -1:
                        uf.merge(tmp[strs[i][idx]], i)
                    tmp[strs[i][idx]] = i
                    cur = fmax(cur, uf.getSize(i))
            
        elif query[0] == 2:
            outs.append(uf.getSize(query[1] - 1))
        else:
            outs.append(cur)
    
    print('\n'.join(map(str, outs)))