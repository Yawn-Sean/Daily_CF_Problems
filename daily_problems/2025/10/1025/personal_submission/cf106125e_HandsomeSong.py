def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def query(l,r):
    print(l+2,r+1,flush=True)
    a=LII()
    if II()>=70:
        exit()
    return a
n=II()
a=[0]*n
while   True:
    cur_mn=0
    mn_idx=-1
    cur=0
    mx_seg=0
    l,r=-1,0
    for i in range(n):
        cur += 1 if a[i]==0 else -1
        if cur <cur_mn:
            cur_mn=cur
            mn_idx=i
        if cur-cur_mn>mx_seg:
            mx_seg=cur-cur_mn
            l,r=mn_idx,i
    a=query(l,r)