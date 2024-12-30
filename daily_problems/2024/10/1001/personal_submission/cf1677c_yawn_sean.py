# Submission link: https://codeforces.com/contest/1677/submission/283833723
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        perm1 = LGMI()
        perm2 = LGMI()
        
        perm = [-1] * n
        for i in range(n):
            perm[perm1[i]] = perm2[i]
        
        k = 0
        vis = [0] * n
        
        for i in range(n):
            if not vis[i]:
                cnt = 0
                while not vis[i]:
                    vis[i] = 1
                    cnt += 1
                    i = perm[i]
                k += cnt // 2
        
        outs.append(2 * k * (n - k))

    print('\n'.join(map(str, outs)))