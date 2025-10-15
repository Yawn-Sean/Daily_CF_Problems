# Submission link: https://codeforces.com/contest/963/submission/291254020
def main():
    n = II()
    parent = LGMI()

    tree = [[] for _ in range(n)]
    rt = -1

    degs = [0] * n

    for i in range(n):
        if parent[i] == -1:
            rt = i
        else:
            degs[i] ^= 1
            degs[parent[i]] ^= 1
            
            tree[parent[i]].append(i)

    stk = [rt]
    order = []

    while stk:
        u = stk.pop()
        order.append(u)
        
        for v in tree[u]:
            stk.append(v)

    if n % 2 == 0:
        print('NO')
    else:
        print('YES')
        vis = [0] * n
        ans = []
        for i in reversed(order):
            if degs[i] == 0:
                if i != rt:
                    degs[parent[i]] ^= 1
                stk.append(i)
                
                vis[i] = 1
                while stk:
                    u = stk.pop()
                    ans.append(u)
                    for v in tree[u]:
                        if not vis[v]:
                            vis[v] = 1
                            stk.append(v)
        
        print('\n'.join(str(x + 1) for x in ans))