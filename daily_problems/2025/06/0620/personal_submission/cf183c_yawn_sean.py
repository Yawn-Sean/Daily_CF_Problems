# Submission link: https://codeforces.com/contest/183/submission/325213280
def main():
    n, m = MII()
    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(~u)

    note = 10 ** 6
    cols = [note] * n

    ans = 0

    for i in range(n):
        if cols[i] == note:
            cols[i] = 0
            
            stk = [i]
            while stk:
                u = stk.pop()
                
                for v in path[u]:
                    if v >= 0:
                        if cols[v] == note:
                            cols[v] = cols[u] + 1
                            stk.append(v)
                        else:
                            ans = math.gcd(ans, cols[u] + 1 - cols[v])
                    else:
                        v = ~v
                        if cols[v] == note:
                            cols[v] = cols[u] - 1
                            stk.append(v)
                        else:
                            ans = math.gcd(ans, cols[u] - 1 - cols[v])

    ans = abs(ans)

    print(ans if ans else n)