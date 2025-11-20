n = ix()
a = il()
b = il()
c = []

def LIS(nums):
    stack = []
    for num in nums:
        idx = bisect_left(stack, num)
        if idx < len(stack):
            stack[idx] = num
        else:
            stack.append(num)
    return len(stack)

for x, y in zip(a, b):
    if x > y:
        c += x,
        c += y,
    else:
        c += y,
        c += x,

print(LIS(c))
