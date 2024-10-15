"""
思路：预处理出N能拆出的所有数最后拆完的长度

分治处理，每次把[l,r]分到拆出的三段里。
"""
#python代码：
n, l, r = map(int, input().split())
m = defaultdict(int)
m[0] = m[1] = 1
ans = 0

def cal(x):
    if m[x]:
        return m[x]
    m[x] = cal(x >> 1) + cal(x & 1) + cal(x >> 1)
    return m[x]

cal(n)

def work(x, l, r):
    if x < 2:
        if x:
            ans += 1
        return
    mid = m[x >> 1]
    if r <= mid:
        work(x >> 1, l, r)
    elif l <= mid:
        work(x >> 1, l, mid)
    if l <= mid + 1 and r >= mid + 1:
        work(x & 1, 1, 1)
    if l > mid + 1:
        work(x >> 1, l - mid - 1, r - mid - 1)
    elif r > mid + 1:
        work(x >> 1, 1, r - mid - 1)

work(n, l, r)
print(ans)
