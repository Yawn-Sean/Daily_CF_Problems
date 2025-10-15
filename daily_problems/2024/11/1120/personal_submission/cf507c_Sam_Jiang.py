import sys,math,heapq
from collections import Counter
#sys.setrecursionlimit(400000)
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
    h,target=MI()
    level=0
    num=1
    direction='L'
    covered=1
    def check(level,num):
        return (target-1)//(1<<(h-level))==num-1 
    while level<h:
        a,b=0,0
        if direction=='R':
            a,b=level+1,2*num
        else:
            a,b=level+1,2*num-1
        if check(a,b):
            covered+=1
            level,num=a,b 
        else:
            covered+=((1<<(h-level))-1)
        if direction=='R':
            direction='L'
        elif direction=='L':
            direction='R'
    return covered-1


t=1
for i in range(t):
    w = main()
    print(w)

