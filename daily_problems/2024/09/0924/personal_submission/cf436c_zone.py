"""
problem url   : https://codeforces.com/problemset/problem/436/C
submission url: https://codeforces.com/contest/436/submission/282735412
"""
def main():
    n, m, k, w = MII()
    d = [0] * (k + 1) ** 2
    a = [[I() for _ in range(n)] for _ in range(k)]
    
    def f(i, j):
        return i * (k + 1) + j 
    
    for i in range(k):
        d[f(i, k)] = n * m 
        for j in range(i):
            cnt = 0 
            for l in range(n):
                for r in range(m):
                    cnt += a[i][l][r] != a[j][l][r]
            d[f(i, j)] = d[f(j, i)] = cnt * w
    fin = 0 
    dis = [k] * (k + 1)
    st  = set(range(k + 1))
    while st: 
        cur = -1 
        for x in st: 
            if cur == -1 or d[f(x, dis[x])] < d[f(cur, dis[cur])]: 
                cur = x 
        fin += d[f(cur, dis[cur])] if cur != k else 0 
        st.remove(cur)
        for v in st: 
            if d[f(v, dis[v])] > d[f(v, cur)]:
                dis[v] = cur  
    
    outs = [] 
    stk = [k]
    while stk: 
        u = stk.pop() 
        for v in range(k):
            if dis[v] == u: 
                outs.append(f"{v + 1} {u + 1 if u != k else 0}")
                stk.append(v)
                    
    print(fin)
    print('\n'.join(outs))
