# Submission link: https://codeforces.com/gym/106235/submission/391736932
def main():
    n = II()
    path = [0] * n
    
    dp = [0] * (1 << n)
    dp[0] = 1
    
    def count_method():
        for i in range(1, 1 << n):
            dp[i] = 0
            cur = i
            
            while cur:
                v = cur & -cur
                bit = v.bit_length() - 1
                if path[bit] & i == 0:
                    dp[i] += dp[i - v]
                cur -= v
        
        return dp[-1]
    
    total = math.factorial(n)
    
    while True:
        query = LI()
        
        if query[0] == '?':
            x = int(query[1]) - 1
            y = int(query[2]) - 1
            
            orig = path[x]
            path[x] |= 1 << y
            w1 = count_method()
            path[x] = orig
            
            w2 = total - w1
            
            if w1 >= w2:
                path[x] |= 1 << y
                total = w1
                print('<', flush=True)
            else:
                path[y] |= 1 << x
                total = w2
                print('>', flush=True)
    
        else:
            p = [int(x) - 1 for x in query[1:]]
            indeg = [0] * n
            
            for i in range(n):
                for j in range(n):
                    if path[i] >> j & 1:
                        indeg[j] += 1
            
            cur = []
            stk = [i for i in range(n) if indeg[i] == 0]
            
            for _ in range(n):
                if len(stk) > 1 and stk[-1] == p[len(cur)]:
                    stk.reverse()
                
                u = stk.pop()
                cur.append(u)
                
                for v in range(n):
                    if path[u] >> v & 1:
                        indeg[v] -= 1
                        if indeg[v] == 0:
                            stk.append(v)
            
            print('!', *(x + 1 for x in cur), flush=True)
            
            break