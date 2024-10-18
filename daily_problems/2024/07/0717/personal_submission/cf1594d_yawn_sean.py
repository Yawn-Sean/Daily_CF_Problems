# Submission Link: https://codeforces.com/contest/1594/submission/270942912
def main():
    n, m = MII()
    path = [[] for _ in range(n)]
    for _ in range(m):
        u, v, s = LI()
        u = int(u) - 1
        v = int(v) - 1
        if s[0] == 'i':
            path[u].append(~v)
            path[v].append(~u)
        else:
            path[u].append(v)
            path[v].append(u)
    
    cols = [-1] * n
    flg = True
    ans = 0
    for i in range(n):
        if cols[i] == -1:
            stk = [i]
            cols[i] = 0
            cnt = 0
            cnt1 = 0
            while stk:
                u = stk.pop()
                cnt += 1
                for v in path[u]:
                    if v >= 0:
                        if cols[v] == -1:
                            cols[v] = cols[u]
                            if cols[v]: cnt1 += 1
                            stk.append(v)
                        elif cols[v] != cols[u]:
                            flg = False
                    else:
                        v = ~v
                        if cols[v] == -1:
                            cols[v] = cols[u] ^ 1
                            if cols[v]: cnt1 += 1
                            stk.append(v)
                        elif cols[v] == cols[u]:
                            flg = False
            ans += max(cnt - cnt1, cnt1)
    return ans if flg else -1