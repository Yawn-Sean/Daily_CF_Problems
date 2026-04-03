# Submission link: https://codeforces.com/gym/102911/submission/369362456
def main(): 
    M = 5 * 10 ** 6 + 1
    pr = list(range(M))
    
    for i in range(2, M):
        if pr[i] == i:
            for j in range(i, M, i):
                pr[j] = i
    
    sg_vis = [0] * M
    sg = [0] * M
    
    for i in range(1, M):
        cur = i
        
        while cur > 1:
            sg_vis[i] |= sg_vis[i // pr[cur]] | (1 << sg[i // pr[cur]])
            cur //= pr[cur]
        
        x = ~sg_vis[i]
        x &= -x
        
        sg[i] = x.bit_length() - 1
    
    m, n, x, y = MII()
    
    c1 = [0] * 30
    c2 = [0] * 30
    
    for i in range(x + 1):
        c1[sg[m - i]] += 1
    
    for i in range(y + 1):
        c2[sg[n - i]] += 1
    
    ans = (x + 1) * (y + 1)
    for i in range(30):
        ans -= c1[i] * c2[i]
    
    print(ans)