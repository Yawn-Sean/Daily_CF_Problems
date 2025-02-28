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
    a=II()
    s=I()
    n=len(s)
    presum=[0]
    cur=0
    for i in s:
        cur+=int(i)
        presum.append(cur)
    dic={}
    if a>0:
        for i in range(1,n+1):
            for j in range(i-1,-1,-1):
                t=presum[i]-presum[j]
                if t>a :
                    break
                if t>0 and a%t==0:
                    if t not in dic:
                        dic[t]=1
                    else:
                        dic[t]+=1
        ans=0
        covered=set()
        for key in dic:
            tmp=a//key
            if tmp in dic and key not in covered and tmp not in covered:
                if key!=tmp:
                    ans+=dic[key]*dic[tmp]*2 
                else:
                    ans+=dic[key]*dic[tmp]
                covered.add(key)
                covered.add(tmp)
        return ans
    else:
        zero=0
        for i in range(1,n+1):
            for j in range(i-1,-1,-1):
                t=presum[i]-presum[j]
                if t==0:
                    zero+=1
                else:
                    break 
        non_zero=n*(n+1)//2
        non_zero-=zero 
        return non_zero*zero*2+zero*zero

t=1
for i in range(t):
    w = main()
    print(w)

