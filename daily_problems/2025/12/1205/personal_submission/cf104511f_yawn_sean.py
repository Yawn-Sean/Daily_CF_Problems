# Submission link: https://codeforces.com/gym/104511/submission/351808525
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, v = MII()
        s = I()
        transactions = []
        
        for _ in range(m):
            a, x, b, y, c, z = MII()
            x -= 1
            y -= 1
            z -= 1
            transactions.append((a, x, b, y, c, z))
        
        cost = [-1] * n
        for i in range(n):
            if s[i] == '1':
                cost[i] = 1
        
        for _ in range(n):
            for a, x, b, y, c, z in transactions:
                if cost[x] != -1 and cost[y] != -1:
                    if cost[z] == -1: cost[z] = (a * cost[x] + b * cost[y]) / c
                    else: cost[z] = fmin(cost[z], (a * cost[x] + b * cost[y]) / c)
        
        outs.append(v / cost[0] if cost[0] != -1 else 0)
    
    print('\n'.join(map(str, outs)))