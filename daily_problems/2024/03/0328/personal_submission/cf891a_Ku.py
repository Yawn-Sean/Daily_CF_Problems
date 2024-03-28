import math
n = int(input())
a = list(map(int,input().split()))
t = a.count(1)
if t > 0:
    print(n - t)
    exit()
ans = math.inf
for i in range(n):
    x = a[i]
    for j in range(i+1,n):
        x = math.gcd(x,a[j])
        if x == 1:
            ans = min(ans,j-i)
            break
if ans < math.inf:
    print(ans + n - 1)
else:
    print(-1)
