import sys
import math
input = lambda: sys.stdin.readline().strip()
def I():
    return input()
def II():
    return int(input())
def MI():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def LFI():
    return list(map(float, input().split()))
def GMI():
    return map(lambda x: int(x) - 1, input().split())
def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))

def main():
    n,x,y=MI()
    points=[]
    distance=[]
    for _ in range(n):
        a,b=MI()
        points.append([a,b])
        q=(a-x)*(a-x)+(b-y)*(b-y)
        distance.append(q)
    distance.sort()
    long=distance[-1]
    short=distance[0]
    
    points.append(points[0])
    for i in range(1,n+1):
        a1,b1=points[i-1][0],points[i-1][1]
        a2,b2=points[i][0],points[i][1]
        if (x-a1)*(a2-a1)+(y-b1)*(b2-b1)>0 and \
            (a1-a2)*(x-a2)+(b1-b2)*(y-b2)>0 :
            k=((x-a1)*(a2-a1)+(y-b1)*(b2-b1))/((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1))
            c,d=a1+k*(a2-a1),b1+k*(b2-b1)
            tmp=(x-c)*(x-c)+(y-d)*(y-d)
            short=min(short,tmp)
    return math.pi*(long-short)

t = 1
for i in range(t):
    w = main()
    print(w)
