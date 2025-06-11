"""
思路：以为贪错了，实际输出格式错了。尴尬的一集。

"""
#python代码：
ans = 0
res = []
n = int(input())
for _ in range(n):
    l, w = map(int,input().split())
    if l > w: l, w = w, l
    ans = fmax(ans, l * w)
    res.append([l, w])
res.sort()
mx = res[-1][1]
for i in range(n - 2, -1, -1):
    ans = fmax(ans, 2 * res[i][0] * fmin(mx, res[i][1]))
    mx = fmax(mx, res[i][1])
print(f'{ans//2}.{ans % 2 * 5}')
