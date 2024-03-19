t = int(input())
def check(num):
    opt_q = q * num
    opt_p = p * num
    if opt_q <  y:
        return False
    elif opt_q == y and opt_p == x:
        return True
    elif opt_q > y:
        cha = opt_q -y
        if x + cha >= opt_p and x <= opt_p:
            return True
        else:
            return False
for _ in range(t):
    x,y,p,q = map(int,input().split())
    left = 0
    right = 10 ** 9 + 1
    while left + 1 < right:
        mid = (left + right) // 2
        if check(mid):
            right = mid
        else:
            left = mid
    if right > 10 ** 9:
        print(-1)
    else:
        print(q * right - y)
