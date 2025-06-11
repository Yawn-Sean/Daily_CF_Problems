"""
思路：A 必胜的情况仅限于 前缀长度为奇数或者后缀长度为奇数

其余情况是 B 胜
"""
#python代码：
n = int(input())
nums = list(map(int, input().split()))
l = 0
while l < n - 1 and nums[l+1] > nums[l]:
    l += 1
r = n - 1
while r > 0 and nums[r-1] > nums[r]:
    r -= 1
# 两个长度都是偶数, A 必败
print('Alice' if ((l + 1) % 2 or (n - r) % 2) else 'Bob')
