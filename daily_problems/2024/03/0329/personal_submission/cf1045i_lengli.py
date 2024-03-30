import sys
from collections import Counter
input=sys.stdin.readline

s=Counter()

res=0
n=int(input())
for _ in range(n):
    str=input().strip()
    k=0
    for x in str:
        k^=(1<<(ord(x)-ord('a')))
    res+=s[k]
    for i in range(26):
        res+=s[k^(1<<i)]
    s[k]+=1
print(res)
