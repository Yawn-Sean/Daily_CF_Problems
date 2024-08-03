n = int(input())
nums = list(map(int, input().split()))
neg = 0
zero = 0
for num in nums:
    if num < 0:
        neg += 1
    elif num == 0:
        zero += 1
if neg % 2 == 0 or zero or n % 2 == 1:
    print(sum(map(abs, nums)))
else:
    print(sum(map(abs, nums)) - 2*min(map(abs, nums)))
