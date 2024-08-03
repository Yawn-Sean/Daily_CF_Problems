import sys
input = sys.stdin.readline
mod = 10 ** 9 + 7 # 998244353

s = input().strip().replace("()", "0").replace("->", ",")
nums, ops = [], []
for c in s:
    if c == '0':
        nums.append(0)
    elif c == ',':
        ops.append(1)
    elif c == '(':
        ops.append(0)
    else:
        while ops[-1]:
            x, y = nums.pop(), nums.pop()
            nums.append(max(x, y + 1))
            ops.pop()
        ops.pop()
while ops:
    x, y = nums.pop(), nums.pop()
    nums.append(max(x, y + 1))
    ops.pop()
print(nums[0])
