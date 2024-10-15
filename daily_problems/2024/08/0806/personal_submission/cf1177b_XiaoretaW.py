n = int(input())

if (n < 10):
    print(n)
    exit()

a, b = [], []
x, y = 9, 1
tot = 0
while tot <= n:
    tot += x * y
    a.append(tot)
    b.append([10 ** (y - 1), 10 ** y - 1, y])
    x, y = x * 10, y + 1

# 先二分到位数
l, r = 0, len(a) - 1
while l < r:
    mid = (l + r) // 2
    if a[mid] >= n: r = mid
    else: l = mid + 1
n = n - a[l - 1]
# 二分具体数字
t = l
d = b[t][2]
l, r = b[t][0], b[t][1]
while l < r:
    mid = (l + r) // 2
    if ((mid - b[t][0] + 1) * d >= n): r = mid
    else: l = mid + 1
# print(n, l)
move = n - (l - b[t][0]) * d - 1
ans = str(l)
print(ans[move])
