fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

def solve():
    n,a,b = map(int,input().split())
    arr = list(map(int,input()))
    #dp0表示截止到i位置,且i位置高度为1的总花费,dp1表示截止到i位置,且i位置高度为2的总花费
    #对于每种情况,再讨论前一个位置高度是1还是2
    dp0,dp1=b,inf
    for x in arr:
        #当前位置是十字路口,高度必须是2
        if x:
            #因此dp0无法实现,将其成本设置成inf,由于高度是2的前一段高度也必须是2,因此总花费就是dp1+a+2*b
            dp0,dp1=inf,dp1+a+2*b
        #当前位置是普通路口,无需抬高
        else:
            #当前高度选择设置成1
            #前一个位置如果高度是1,那么总花费就是dp0+a+b,前一个位置如果高度是2,即向下弯头,那么总花费就是dp1+2*a+b
            #二者取较小值
            ndp0=fmin(dp0+a+b,dp1+2*a+b)
            #当前高度选择设置成2
            #前一个位置如果高度是1,那么总花费就是dp0+2*a+a*b,即向上弯头,前一个位置如果高度是2,那么总话费就是dp1+a+2*b
            # 二者取较小值
            ndp1=fmin(dp0+2*a+2*b,dp1+a+2*b)
            dp0,dp1=ndp0,ndp1
    print(dp0)
    return 0

t = int(input())
for i in range(t):
    solve()
