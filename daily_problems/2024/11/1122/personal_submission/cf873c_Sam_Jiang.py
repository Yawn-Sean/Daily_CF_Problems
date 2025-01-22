import sys,math,heapq
from collections import Counter
#sys.setrecursionlimit(200000)
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
from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    if not stack:break
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc

def main():
    n,m,k=MI()
    grid=[LII() for _ in range(n)] 
    def test(lst):
        presum=[0]
        cur=0
        for i in lst:
            cur+=i 
            presum.append(cur)
        ans=[presum[min(n,i+k)]-presum[i] for i in range(n)]
        
        if presum[-1]==0:
            return 0,0
        e=max(ans)
        cnt=0
        for i in range(n):
            if lst[i]==1 and ans[i]>=k:
                return k,cnt 
            elif lst[i]==1 and ans[i]==e:
                return e,cnt 
            elif lst[i]==1:
                cnt+=1 
        return min(k,e),cnt

        
    a,b=0,0
    for i in range(m):
        x,y=test([grid[j][i] for j in range(n)])
        a+=x 
        b+=y 
    print(a,b)

t=1
for i in range(t):
    w = main()

