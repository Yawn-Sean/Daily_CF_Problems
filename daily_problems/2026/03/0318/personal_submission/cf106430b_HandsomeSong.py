import math
n=int(input())
for _ in range(n):
    a,b=map(int,input().split())
    if a==b:
        print(0)
    elif a<b:
        ans=0
        while a<b:
            a*=2
            ans+=1
        print(ans)
    else:
        if b==1 or b==2:
            print(-1)
        else:
            ans = 0
            while a > b:
                a = 2 * a // 3 + 1
                ans += 1
            print(ans)