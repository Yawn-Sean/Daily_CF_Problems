import math
t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    a_b_lcm=math.lcm(a,b)
    ans=c-math.gcd(a_b_lcm,c)
    print(ans)