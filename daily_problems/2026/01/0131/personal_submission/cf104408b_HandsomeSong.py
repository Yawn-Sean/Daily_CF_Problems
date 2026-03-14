n=int(input())
pie=3.14159265
for _ in range(n):
    x1,y1,x2,y2=map(int,input().split())
    if x1==x2==0:
        print(float(abs(y1-y2)))
    elif y1==y2==0:
        print(float(abs(x1-x2)))
    elif x1==y2==0:
        print(min(abs(x2),abs(y1))/2*pie+abs(abs(x2)-abs(y1)))
    elif x2==y1==0:
        print(min(abs(x1),abs(y2))/2*pie+abs(abs(x1)-abs(y2)))
