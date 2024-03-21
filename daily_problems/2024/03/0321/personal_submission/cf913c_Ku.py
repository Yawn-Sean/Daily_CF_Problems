import bisect
import math
n, L = map(int,input().split())
c= list(map(int,input().split()))
vol = [2 ** i for i in range(n)]
#把每个价格都贪心成最小的，如 4 = 2 + 2 比较c[i] 和 2 * c[i-1]的大小
for i in range(1,n):
    c[i] = min(c[i-1] * 2 ,c[i])
ans = math.inf
cur = 0
for i in range(n-1,-1,-1):
    #全买vol[i]
    ans = min(ans,cur + c[i] * ((L-1) // vol[i] + 1))
    #不全买vol[i]
    buy = L // vol[i]
    cur += buy * c[i]
    L -= buy * vol[i]
print(ans)
