# Submission link: https://codeforces.com/gym/106368/submission/399110222
def main():
    a, m, b, n = MII()
    
    sz = n + 5
    ans = ''
    
    def bfs(x, base):
        global sz, ans
        
        pre = [-2] * n
        pre_op = [0] * n
        
        pre[x] = -1
        que = [x]
        
        for u in que:
            nu = (u + m) % n
            if pre[nu] == -2:
                pre[nu] = u
                pre_op[nu] = 0
                que.append(nu)
            
            nu = (u - m) % n
            if pre[nu] == -2:
                pre[nu] = u
                pre_op[nu] = 1
                que.append(nu)
            
            nu = u * m % n
            if pre[nu] == -2:
                pre[nu] = u
                pre_op[nu] = 2
                que.append(nu)
        
        if pre[b] != -2:
            cur = b
            ops = []
    
            while cur != x:
                ops.append(pre_op[cur])
                cur = pre[cur]
            
            ops.reverse()
            res = base + ''.join("+-*"[x] for x in ops)
            
            if len(res) < sz:
                sz = len(res)
                ans = res
    
    bfs(a % n, '')
    bfs(a % m % n, '%')
    bfs(0, '*%')
    
    if sz <= n:
        print(sz)
        print(ans)
    else:
        print(-1)