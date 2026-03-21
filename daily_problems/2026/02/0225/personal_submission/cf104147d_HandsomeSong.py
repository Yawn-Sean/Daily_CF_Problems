fin = open('dotak.in', 'r')
input = lambda: fin.readline().strip()
    
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=n*k%(k+1)
    if a%2==1 or a==k:
        print('Omda')
    else:
        print('Teemo')