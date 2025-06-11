# Submission Link: https://codeforces.com/contest/1442/submission/268392064
def main():
    t = II()
    outs = []
    mod = 998244353

    def delete(x):
        if pre[x] >= 0:
            nex[pre[x]] = nex[x]
        if nex[x] < n:
            pre[nex[x]] = pre[x]

    for _ in range(t):
        n, k = MII()
        perm = LGMI()
        target = LGMI()
        
        pos = [-1] * n
        for i in range(n):
            pos[perm[i]] = i
        
        for i in range(k):
            target[i] = pos[target[i]]
        
        chosen = [0] * n
        for i in range(k):
            chosen[target[i]] = 1
        
        pre = list(range(-1, n - 1))
        nex = list(range(1, n + 1))
        
        ans = 1
        for i in range(k):
            cnt = 0
            if pre[target[i]] >= 0 and not chosen[pre[target[i]]]:
                cnt += 1
            if nex[target[i]] < n and not chosen[nex[target[i]]]:
                cnt += 1
            if cnt == 0: ans = 0; break
            ans *= cnt
            ans %= mod
            delete(target[i])
        
        outs.append(ans)

    print('\n'.join(map(str, outs)))