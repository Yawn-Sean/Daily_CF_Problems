import bisect
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
ans=[]
tails=[]
for x in a:
    tar=-x
    pos=bisect.bisect_right(tails,tar)
    if pos<len(tails):
        ans[pos].append(x)
        tails[pos]=tar
    else:
        ans.append([x])
        tails.append(tar)
for s in ans:
    print(' '.join(map(str,s)))