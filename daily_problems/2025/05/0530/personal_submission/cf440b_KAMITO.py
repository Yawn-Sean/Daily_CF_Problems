#前i个元素的总和要到达k/n*i都要经过第i个元素
def solve():
    n=II()
    a=LMII()
    k=sum(a)//n
    ans=0;s=0
    for i in range(n):
        s+=a[i]-k
        ans+=abs(s)
    print(ans)
    return
