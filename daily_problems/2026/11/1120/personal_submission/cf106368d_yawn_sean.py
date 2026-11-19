# Submission link: https://codeforces.com/gym/106368/submission/399115255
def main(): 
    t = II()
    
    stk = []
    
    n = t // 2
    cur = 0
    timestamps = [0] * (n + 1)
    
    for i in range(1, t + 1):
        op, x = LI()
        x = int(x)
        
        ops = []
        
        if op == '+':
            cur += 1
            timestamps[cur] = x
        else:
            ops.append(f'2 {stk.pop()}')
        
        w = 2 * (i & -i) - 1
        tmp = [cur] if op == '+' else []
        
        while w and stk:
            w -= 1
            ops.append(f'2 {stk[-1]}')
            tmp.append(stk.pop())
        
        tmp.sort(lambda x: -timestamps[x])
        
        for x in tmp:
            ops.append(f'1 {x}')
            stk.append(x)
        
        print(len(ops))
        print('\n'.join(ops), flush=True)