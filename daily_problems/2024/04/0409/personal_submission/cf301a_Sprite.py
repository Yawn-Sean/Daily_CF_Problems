n = int(input())
nums = list(map(int, input().split()))
neg = 0
for i in nums:
    if i < 0:
        neg += 1
k = [abs(i) for i in nums]
k.sort()
if neg & 1 and not n & 1:
    print(sum(k) - k[0] * 2)
else:
    print(sum(k))
