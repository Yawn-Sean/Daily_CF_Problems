# Submission link: https://codeforces.com/gym/105789/submission/353791406
def main(): 
    pt = 0
    M = 10 ** 6 + 10
    
    pos = [-1] * M
    prev_pos = [-1] * M
    next_pos = [-1] * M
    
    def delete_node(x):
        p = pos[x]
        prev_pos[next_pos[p]] = prev_pos[p]
        next_pos[prev_pos[p]] = next_pos[p]
        pos[x] = -1
    
    def insert_node(y, x):
        nonlocal pt
        pt += 1
        pos[x] = pt
    
        p = pos[x]
        q = pos[y]
        
        prev_pos[p] = prev_pos[q]
        next_pos[p] = q
        
        prev_pos[next_pos[p]] = p
        next_pos[prev_pos[p]] = p
    
    n = II()
    nums = LII()
    
    pos[nums[-1]] = 0
    next_pos[0] = 0
    prev_pos[0] = 0
    
    cur = nums[-1]
    for i in range(n - 2, -1, -1):
        insert_node(cur, nums[i])
        cur = nums[i]
    
    q = II()
    outs = []
    
    for _ in range(q):
        op = LI()
        if op[0] == '-':
            v = int(op[1])
            delete_node(v)
    
        elif op[0] == '+':
            x = int(op[1])
            y = int(op[2])
            insert_node(y, x)
    
        else:
            k = int(op[1])
            vals = [int(x) for x in op[2:]]
            
            ans = 0
            res = 0
            for i in range(k * 2):
                if pos[vals[i % k]] == -1: res = 0
                elif prev_pos[pos[vals[i % k]]] == pos[vals[(i - 1) % k]]:
                    res += 1
                else: res = 1
                ans = fmax(ans, res)
            
            outs.append(str(ans) if ans < k * 2 else '*')
    
    print('\n'.join(outs))