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
    left,right=MI()
    
    def find(num_digit,cycle_length):
        if cycle_length==num_digit:
            return 0
        if cycle_length==1:
            if left<=((1<<(num_digit))-1)<=right:
                return 1 
            return 0 
        factor=((1<<num_digit)-1)//((1<<cycle_length)-1)
        left_bound=1<<(num_digit-1)
        right_bound=(1<<num_digit)-1
        left_bound=max(left_bound,left)
        right_bound=min(right_bound,right)
        a,b=(left_bound+factor-1)//factor,right_bound//factor
        return max(0,b-a+1)
    ans=0
    for num_digit in range(2,62):
        if (1<<(num_digit-1))>right:
            break
        if (1<<num_digit)-1<left:
            continue
        cycle_lst=[]
        for cycle_length in range(num_digit-1,0,-1):
            if num_digit%cycle_length==0:
                cycle_lst.append(cycle_length)
        coefficient=[0]*len(cycle_lst)
        tmp_ans=[0]*len(cycle_lst)
        for idx in range(len(cycle_lst)):
            a=find(num_digit,cycle_lst[idx])
            if idx==0:
                coefficient[idx]=1
            else:
                tmp=0
                for j in range(idx):
                    if cycle_lst[j]%cycle_lst[idx]==0:
                        tmp+=coefficient[j]
                coefficient[idx]=1-tmp 
            tmp_ans[idx]=a 
        ans+=sum(coefficient[i]*tmp_ans[i] for i in range(len(cycle_lst)))
    return ans

t=1
for i in range(t):
    w = main()
    print(w)

