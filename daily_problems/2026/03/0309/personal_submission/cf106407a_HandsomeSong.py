t=int(input())
for _ in range(t):
    m,n,k=map(int,input().split())
    if k==1:
        if m*n%2==1:
            print('Munir')
        else:
            print('Matthew')
    elif k>=4 or m%2==1 or n%2==1:
        print('Munir')
    else:
        print('Matthew')