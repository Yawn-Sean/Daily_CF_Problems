import sys
from math import *
from collections import *
def solve(k):
    x,y=0,0
    for i in range(n): 
        if i==k: 
            if s[i]=="0" and s1[i]=="1":
                x+=1
            elif s[i]=="1" and s1[i]=="0":
                y+=1
        else:
            if s[i]=="1" and s1[i]=="1":
                x+=1
            elif s[i]=="0" and s1[i]=="0":
                y+=1
    if x==y: return 2*x
    return sys.maxsize
for _ in range(int(input())):
    n=int(input())
    s=input()
    s1=input()
    aa,bb,cc,idx1,idx2=0,0,0,-1,-1
    for i in range(n):
        if s[i]==s1[i]=="1": 
            aa+=1
            if idx1==-1: idx1=i
        elif s[i]=="1" and s1[i]=="0": 
            bb+=1
            if idx2==-1: idx2=i
        elif s[i]=="0" and s1[i]=="1":
            cc+=1
    cnt=sys.maxsize
    if bb==cc:
        cnt=2*bb
    if idx1!=-1:
        cnt=min(cnt,1+solve(idx1))
    if idx2!=-1:
        cnt=min(cnt,1+solve(idx2))
    if cnt==sys.maxsize:
        print(-1)
        continue
    print(cnt)
