import sys
from collections import Counter
input = sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
n=II()
cnt=Counter()
ans=0
for _ in range(n):
    msk=0
    s=I()
    for c in s:
        msk^=1<<ord(c)-ord('a')
    ans+=cnt[msk]
    for i in range(26):
        ans+=cnt[msk^(1<<i)]
    cnt[msk]+=1
print(ans)