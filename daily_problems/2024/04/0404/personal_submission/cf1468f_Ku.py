from collections import  *
n = int(input())

for _ in range(n):
    cnt1 = Counter()
    cnt2 = Counter()
    t = int(input())
    ans = 0
    for _ in range(t):
        x,y,u,v = map(int,input().split())
        delta_x = u - x
        delta_y = v - y
        if delta_x == 0:
            if delta_y > 0:
                ans += cnt2['*']
                cnt1['*'] += 1
            else:
                ans += cnt1['*']
                cnt2['*'] += 1
        elif delta_x > 0:
            opt = delta_y / delta_x
            ans += cnt2[opt]
            cnt1[opt] += 1
        else:
            opt = delta_y / delta_x
            ans += cnt1[opt]
            cnt2[opt] += 1
    print(ans)
