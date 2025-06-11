# https://codeforces.com/contest/671/submission/295963995

'''
富人降无可降，穷人升无可升，才是稳态。
因为富人财富只会减或不变，穷人相反，所以最后答案是富人最小-穷人最大
二分求富人财富最小值，穷人财富最大值，k天里最多能升/降多少
'''
n, k = RII()
a = RILIST()
total = sum(a)
# 这里边界要想一下，total = 5 n = 3 只能是 2 1 1开区间最大值l = 2 - 1
l, r = total // n - 1, max(a) + 1
if total % n:
    l += 1

# 最大值能降到多少，下限是均值
def check(mid):
    cnt = 0
    for x in a:
        cnt += mx(0, x - mid)
        if cnt > k:
            return False
    return True


while l + 1 < r:
    mid = l + r >> 1
    if check(mid):
        r = mid # 还有下降空间
    else:
        l = mid
        
ans1 = r
# 最小值能上升到多少，上限均值 2 1 1
l, r = min(a) - 1, total // n + 1
def check1(mid):
    cnt = 0
    for x in a:
        cnt += mx(0, mid - x)
        if cnt > k:
            return False
    return True


while l + 1 < r:
    mid = l + r >> 1
    if check1(mid):
        l = mid # 还能上升
    else:
        r = mid

print(ans1 - l)