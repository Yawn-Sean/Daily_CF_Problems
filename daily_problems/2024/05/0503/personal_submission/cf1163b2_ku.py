#https://codeforces.com/problemset/problem/1163/B2
from collections import  *
import sys
input = lambda :sys.stdin.readline().rstrip()
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
n = RI()
li = RILIST()
ans = 0
cnt1,cnt2 = Counter(),Counter()
for i,x in enumerate(li):
    if x in cnt1:
        cnt1[x] += 1
        cnt2[cnt1[x]] += 1
        cnt2[cnt1[x] - 1] -= 1
        if cnt2[cnt1[x] - 1] == 0:
            del cnt2[cnt1[x] - 1]
    else:
        cnt1[x] += 1
        cnt2[cnt1[x]] += 1
    #print(cnt1,cnt2)
    if len(cnt2) >= 3:
        continue
    elif len(cnt2) == 1:
        for k,v in cnt2.items():
            if v == 1 or k == 1:
                ans = max(ans,i+1)
    elif len(cnt2) == 2:
        li1,li2 = [], []
        for k,v in cnt2.items():
            li1.append(k)
            li2.append(v)
        if li1[0] == 1 and li2[0] == 1 or li1[1] == 1 and li2[1] == 1:
            ans = max(ans,i+1)
            continue
        if abs(li1[0]-li1[1]) == 1:
            if li1[0] > li1[1]:
                if li2[0] == 1:
                    ans = max(ans,i+1)
            else:
                if li2[1] == 1:
                    ans = max(ans,i+1)
    #print(i,ans)
print(ans)

