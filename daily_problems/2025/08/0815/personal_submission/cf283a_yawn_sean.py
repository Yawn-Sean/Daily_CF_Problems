# Submission link: https://codeforces.com/contest/283/submission/333935404
def main():
    n = II()
    
    vals = [0]
    adds = [0]
    outs = []
    
    total = 0
    
    for _ in range(n):
        op = LII()
        if op[0] == 1:
            cnt = op[1]
            val = op[2]
            
            total += cnt * val
            adds[cnt - 1] += val
        
        elif op[0] == 2:
            val = op[1]
            total += val
            
            vals.append(val)
            adds.append(0)
        
        else:
            adds[-2] += adds[-1]
            total -= adds[-1] + vals[-1]
            
            vals.pop()
            adds.pop()
        
        outs.append(total / len(vals))
    
    print('\n'.join(map(str, outs)))