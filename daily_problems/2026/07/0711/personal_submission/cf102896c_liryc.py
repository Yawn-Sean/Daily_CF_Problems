'''
https://codeforces.com/gym/102896/submission/382101475
'''
def solve(n: int, pa: list[int]) -> list[int]:
    children = [[] for _ in range(n + 1)]
    for i in range(2, n + 1):
        children[pa[i - 2]].append(i)
        
    sz = [0] * (n + 1)
    def dfs_sz(u):
        s = 1
        for v in children[u]:
            dfs_sz(v)
            s *= sz[v]
        sz[u] = s + 1
        
    dfs_sz(1)
    
    def moves_forward(u):
        c_moves = moves_product(children[u])
        return [u] + c_moves

    def moves_product(c_list):
        if not c_list:
            return []
        if len(c_list) == 1:
            return moves_forward(c_list[0])
            
        v = c_list[0]
        rest = c_list[1:]
        
        M = 1
        for c in rest:
            M *= sz[c]
            
        rest_moves = moves_product(rest)
        
        mf = moves_forward(v)
        mb = mf[::-1]
        
        res = []
        for i in range(M):
            if i % 2 == 0:
                res.extend(mf)
            else:
                res.extend(mb)
                
            if i < M - 1:
                res.append(rest_moves[i])
                
        return res

    return moves_product(children[1])

