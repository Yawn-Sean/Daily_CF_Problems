import sys,math,heapq
from collections import Counter

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
    n,k=MI()
    binary=[0]*(n+35)
    lst=LII()
    for i in range(n+1):
        if lst[i]>0:
            j=0
            t=lst[i]
            #print(t,i+j)
            while t>0:
                if t&1:
                    binary[i+j]+=1
                    cur=i+j
                    while binary[cur]>=2:
                        x,y=divmod(binary[cur],2)
                        binary[cur]=y
                        binary[cur+1]+=x 
                        cur+=1
                t>>=1
                j+=1
        elif lst[i]<0:
            t=-lst[i]
            j=0 
            while t>0:
                if t&1:
                    binary[i+j]-=1
                    cur=i+j
                    while binary[cur]<=-2:
                    
                        tt=-binary[cur]
                        x,y=tt//2,tt%2
                        binary[cur]=-y
                        binary[cur+1]-=x 
                        cur+=1
                t>>=1
                j+=1

    e=int(math.log(2*k,2))+3
    stack=[]
    large=-1
    first_one=-1
    for i in range(len(binary)):
        if binary[i]!=0:
            first_one=i 
            break 
    for i in range(len(binary)-1,-1,-1):
        if large>=0 and large-first_one>e:
            return 0
        if binary[i]>0:
            if not stack:
                stack.append(i)
            else:
                if stack[-1]==-(i+1):
                    stack.pop()
                    stack.append(-i)
                else:
                    if large<0:
                        large=abs(stack[0])
                    stack.append(i)
        elif binary[i]<0:
            if not stack:
                stack.append(-i)
            else:
                if stack[-1]==(i+1):
                    stack.pop()
                    stack.append(i)
                else:
                    if large<0:
                        large=abs(stack[0])
                    stack.append(-i)

    first_div=0
    for i in stack:
        if i>0:
            first_div+=(1<<(i-first_one))
        else:
            first_div-=(1<<(-i-first_one))

    cnt=0
    
    while first_one>=0:
        if abs(first_div)>2*k:
            break
        if first_one>n:
            first_one-=1
            first_div<<=1
            continue
        t=abs(lst[first_one]-first_div)
        if (first_one==n and t!=0 and t<=k) or (first_one<n and t<=k):
            cnt+=1

        first_one-=1
        first_div<<=1 
    return cnt

t=1
for i in range(t):
    w = main()
    print(w)

