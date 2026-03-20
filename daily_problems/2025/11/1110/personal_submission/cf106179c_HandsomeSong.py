t=int(input())
for _ in range(t):
    c=int(input())
    m=0
    while 2**m<=c:
        m+=1
    a=c
    b=2**m*c
    print(a,end=' ')
    print(b)