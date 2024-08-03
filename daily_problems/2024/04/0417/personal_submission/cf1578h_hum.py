s = '(' + input() + ')'
i = 0
nums = []
ops = []

while i < len(s):
  if s[i] == '(':
    if s[i + 1] == ')':
      nums.append(0)
      i += 2
    else:
      ops.append('(')
      i += 1
  elif s[i] == ')':
    num = nums.pop()
    while ops[-1] == '-':
      ops.pop()
      num = max(num, nums.pop() + 1)
    ops.pop()
    nums.append(num)
    i += 1
  else:
    ops.append('-')
    i += 2

print(nums[0])
