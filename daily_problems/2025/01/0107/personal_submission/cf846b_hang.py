
from functools import cache
def main():
    
    n,k,M = map(int, input().split())
    t = list(map(int, input().split()))
    t.sort()
    tot = sum(t)
    ans = 0
    for i in range(n+1):
        cur = i * tot
        if cur > M: break
        tmp_score = (i) * (k + 1)
        tmp_time = M - cur
        for j in range(k):
            p = min(tmp_time // t[j],n-i)
            if p == 0: break
            tmp_score += p
            tmp_time -= p * t[j]
        ans = max(ans, tmp_score)
    print(ans)

    INF = 100000000
    # # a 个任务 还剩b时间，获得最大分数
    # @cache
    # def f(a, b):
    #     if a == 0 or b == 0: return 0

    #     res = 0
    #     for i in range(1, b // tot + 1):
    #         if a - i < 0: break
    #         res = max(res, i * (k + 1) + f(a - i, b - i * tot))
    #     cur = 0
    #     for i in range(k):
    #         cur += t[i]
    #         if b < cur: 
    #             break
    #         res = max(res, i + 1 + f(a - 1, b - cur))
    #     return res
    # print(f(n, M))
main()