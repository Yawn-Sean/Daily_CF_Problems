# Submission link: https://codeforces.com/contest/778/submission/336380541
def main():
    d = {}
    n, m = MII()
    
    d = {'?': -1}
    
    flg = [0] * n
    tmp = [None] * n
    ops = [None] * n
    
    op_mapping = {
        'XOR': xor,
        'OR': ior,
        'AND': iand
    }
    
    for i in range(n):
        op = LI()
        
        d[op[0]] = i
        
        if len(op) == 3:
            tmp[i] = [int(c) for c in op[2]]
        else:
            flg[i] = 1
            ops[i] = d[op[2]], op_mapping[op[3]], d[op[4]]
    
    ans0 = []
    ans1 = []
    
    for i in range(m):
        cur0 = [0] * n
        cur1 = [0] * n
    
        for j in range(n):
            if flg[j]:
                a, o, b = ops[j]
                
                x0 = cur0[a] if a >= 0 else 0
                x1 = cur1[a] if a >= 0 else 1
                
                y0 = cur0[b] if b >= 0 else 0
                y1 = cur1[b] if b >= 0 else 1
                
                cur0[j] = o(x0, y0)
                cur1[j] = o(x1, y1)
            
            else:
                cur0[j] = tmp[j][i]
                cur1[j] = tmp[j][i]
        
        c0 = sum(cur0)
        c1 = sum(cur1)
        
        if c0 <= c1: ans0.append(0)
        else: ans0.append(1)
        
        if c0 >= c1: ans1.append(0)
        else: ans1.append(1)
    
    print(*ans0, sep='')
    print(*ans1, sep='')