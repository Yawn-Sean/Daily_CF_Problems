from collections import  *
import math
n = int(input())

for _ in range(n):
    cnt = Counter()
    t = int(input())
    ans = 0
    for _ in range(t):
        x,y,u,v = map(int,input().split())
        delta_x = u - x
        delta_y = v - y
        g = math.gcd(delta_x,delta_y)
        delta_x //= g
        delta_y //= g
        ans += cnt[(-delta_x, -delta_y)]
        cnt[(delta_x,delta_y)] += 1
    print(ans)
