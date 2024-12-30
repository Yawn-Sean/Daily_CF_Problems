import bisect
from collections import Counter
# 题解 https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/05/0506/solution/cf1569d.md
# 理解横对齐与竖对齐
def main():
    n,m,k = map(int,input().split())
    x_pos = list(map(int,input().split()))
    y_pos = list(map(int,input().split()))
    c_x = [0]*(n)
    c_y = [0]*(m)
    c_x_c = [Counter() for i in range(n)]
    c_y_c = [Counter() for i in range(m)]
    for _ in range(k):
        x,y = map(int,input().split())
        px = bisect.bisect_left(x_pos,x)
        py = bisect.bisect_left(y_pos,y)
        if x_pos[px] == x and y_pos[py] == y:
            continue
        elif x_pos[px] == x:
            c_y[py] += 1
            c_x_c[px][py] += 1
        else:
            c_x[px] += 1
            c_y_c[py][px] += 1
    ans = 0
    for i in range(n):
        ans += c_x[i] *(c_x[i]-1) // 2
        for z in c_x_c[i].values():
            ans -= z * (z-1) // 2
    for i in range(m):
        ans += c_y[i] *(c_y[i]-1) // 2
        for z in c_y_c[i].values():
            ans -= z * (z-1) // 2
        
    print(ans)

t = int(input())
for _ in range(t):
    main()