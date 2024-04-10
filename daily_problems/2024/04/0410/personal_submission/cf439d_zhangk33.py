# Submission link: https://codeforces.com/contest/439/submission/255943100

m, n = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

sab = set(a + b)
a.sort()
b.sort()

pa = [0] * (m+1)
pb = [0] * (n+1)
for i in range(m):
    pa[i+1] = pa[i] + a[i]
for i in range(n):
    pb[i+1] = pb[i] + b[i]

costa = costb = ans = 10 ** 16

# 肯定是保证a的最小>=x, b的最大<=x,枚举这个临界值
for x in sab:
    # 先找满足a[idx] <x 的最大值，可能索引为也0满足要求
    if a[0] >= x:
        # 这个时候不考虑处理a
        costa = 0
    # 排除边界以后，二分可以找到满足<x的最大值的索引
    else:
        l, r = 0, m-1
        while l < r:
            mid = l + r + 1 >> 1
            if a[mid] < x:
                l = mid
            else:
                r = mid - 1
        # 找到的这个位置的索引后，计算需要的代价,[0-l]的元素都要变成x
        costa = (l + 1) * x - pa[l+1]
    # 同理计算costb
    # 需要找满足条件的b[idx] > x的最小索引
    # 先判断不能二分的b的边界情况：可能b[-1]<=x
    if b[-1] <= x:
        costb = 0
    else:
        # 肯定可以二分
        l, r = 0, n-1
        while l < r:
            mid = l + r >> 1
            if b[mid] > x:
                r = mid
            else:
                l = mid + 1
        # 找到这个元素以后，计算代价
        # 需要让[l, n-1]的所有值都降为x
        costb = pb[n] - pb[l] - (n-l) * x
    ans = min(ans, costa + costb)
print(ans)
