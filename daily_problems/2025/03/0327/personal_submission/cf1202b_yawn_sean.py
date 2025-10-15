# Submission link: https://codeforces.com/contest/1202/submission/312632720
def main():
    s = I()

    cnt = [0] * 10
    cur = 0
    for i in range(len(s)):
        ncur = int(s[i])
        if i or ncur:
            cnt[(ncur - cur) % 10] += 1
        cur = ncur

    ans = [[-1] * 10 for _ in range(10)]

    for i in range(10):
        for j in range(10):
            dis = [10] * 10
            
            dis[i] = 0
            dis[j] = 0
            que = [i, j]
            
            for u in que:
                nu = (u + i) % 10
                if dis[nu] == 10:
                    dis[nu] = dis[u] + 1
                    que.append(nu)
                
                nu = (u + j) % 10
                if dis[nu] == 10:
                    dis[nu] = dis[u] + 1
                    que.append(nu)
            
            res = 0
            for x in range(10):
                if cnt[x] and dis[x] == 10:
                    break
                res += cnt[x] * dis[x]
            else:
                ans[i][j] = res

    for x in ans:
        print(*x)