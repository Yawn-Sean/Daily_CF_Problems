# Submission link: https://codeforces.com/contest/704/submission/299535923
def main():
    n, q = MII()

    cnt = [0] * (n + 1)
    unread = [0] * (n + 1)
    stk = []
    pt = 0

    ans = 0
    outs = []

    for i in range(q):
        t, x = MII()
        
        if t == 1:
            ans += 1
            cnt[x] += 1
            stk.append(x)
        
        elif t == 2:
            ans -= cnt[x]
            cnt[x] = 0
            unread[x] = len(stk)
        
        else:
            while pt < x:
                if pt >= unread[stk[pt]]:
                    ans -= 1
                    cnt[stk[pt]] -= 1
                pt += 1
        
        outs.append(ans)

    print('\n'.join(map(str, outs)))