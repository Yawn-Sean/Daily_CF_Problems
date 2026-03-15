t=int(input())
for _ in range(t):
    cnt=0
    a,b,m=map(int,input().split())
    k=m.bit_length()
    p=1<<k-1
    print((b+1)//p-a//p)