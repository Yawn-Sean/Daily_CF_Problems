# 题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/07/0709/solution/cf111b.md
def  main():
    n = int(input())
    g = []
    for _ in range(n):
        x,y = map(int,input().split())
        g.append((x,y))
    m = 10**5 + 10
    pf = list(range(m))
    for i in range(2,m):
        if pf[i] == i:
            for j in range(i*i,m,i):
                pf[j] = i
    def factors(x):
        ans = [1]
        while x > 1:
            r = len(ans)
            p = pf[x]
            while x % p == 0:
                for _ in range(r):
                    ans.append(ans[-r] * p)
                x //= p
        return ans
    vis = [-1] * m
    for i,(x,y) in enumerate(g):
        ans = 0
        for f in factors(x):
            if i - vis[f] > y:
                ans += 1
            vis[f] = i
        print(ans)

main()