# Submission Link: https://codeforces.com/contest/243/submission/270945770
def main():
    n, m, h, t = MII()

    us = []
    vs = []
    path = [[] for _ in range(n)]

    for i in range(m):
        u, v = GMI()
        us.append(u)
        vs.append(v)
        path[u].append(v)
        path[v].append(u)

    used = [0] * n

    def check(u, v):
        if len(path[u]) <= h or len(path[v]) <= t:
            return
        
        cnt = 0
        
        for i in path[u]:
            if not used[i]:
                cnt += 1
            used[i] |= 1
        
        for i in path[v]:
            if not used[i]:
                cnt += 1
            used[i] |= 2
        
        if cnt >= h + t:
            v1 = [i for i in path[u] if used[i] == 1]
            v2 = [i for i in path[v] if used[i] == 2]
            v3 = [i for i in path[u] if used[i] == 3]
            chosen_1 = v1[:h]
            chosen_2 = v2[:t]
            for x in v3:
                if len(chosen_1) < h:
                    chosen_1.append(x)
                elif len(chosen_2) < t:
                    chosen_2.append(x)
            print('YES')
            print(u + 1, v + 1)
            print(' '.join(str(i + 1) for i in chosen_1))
            print(' '.join(str(i + 1) for i in chosen_2))
            exit()
        
        for i in path[u]:
            used[i] = 0
        
        for i in path[v]:
            used[i] = 0

    for i in range(m):
        u, v = us[i], vs[i]
        
        used[u] = used[v] = -1
        check(u, v)
        used[u] = used[v] = 0
        
        used[u] = used[v] = -1
        check(v, u)
        used[u] = used[v] = 0

    print('NO')