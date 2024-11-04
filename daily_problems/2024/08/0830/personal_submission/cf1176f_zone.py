# 遇到具有某种周期性的dp问题，在设计状态时可以考虑取模
# https://codeforces.com/contest/1176/submission/278734296

n = int(input()) 
inf = 10 ** 11 
dp  = [0] + [-inf] * 9 
ndp = [-inf] * 10

for _ in range(n): 
    k = int(input())
    vs = [[] for _ in range(4)]

    for _ in range(k):
        i, v = map(int, input().split())
        vs[i].append(v)

    for i in range(1, 4): 
        vs[i] = nlargest(3 // i, vs[i]) 

    for c1 in range(min(3, len(vs[1])) + 1): 
        for c2 in range(min(c1 <= 1, len(vs[2])) + 1):
            for c3 in range(min(c1 == 0 and c2 == 0, len(vs[3])) + 1): 

                d  = sum(vs[1][:c1]) + sum(vs[2][:c2]) + sum(vs[3][:c3])
                mx = max([0] + vs[1][:c1] + vs[2][:c2] + vs[3][:c3])

                for i in range(10): 
                    v = dp[i] + d
                    cnt = i + c1 + c2 + c3 
                    if cnt >= 10:
                        cnt -= 10 
                        v   += mx 
                    ndp[cnt] = max(ndp[cnt], v)
                    
    dp, ndp = ndp[:], [-inf] * 10

print(max(dp))
