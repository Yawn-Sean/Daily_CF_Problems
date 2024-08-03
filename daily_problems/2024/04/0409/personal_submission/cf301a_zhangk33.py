n = int(input())
nums = map(int, input().split())
# 统计负数的个数
cnt = 0
total = 0
min_abs = 1000
for num in nums:
    if num < 0:
        cnt += 1
    total += abs(num)
    min_abs = min(min_abs, abs(num))
ans = 0
# n是奇数的情况：
if n % 2 == 1:
    ans = total
# n是偶数的时候继续分类讨论
else:
    if cnt % 2 == 0:
        ans = total
    else:
        ans = total - 2 * min_abs
print(ans)
