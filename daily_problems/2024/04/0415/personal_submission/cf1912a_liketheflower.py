# submission link: https://codeforces.com/contest/1912/submission/256860984
x, k = map(int, input().split())

ops = []
for _ in range(k):
    nums = list(map(int, input().split()))
    prefix_sum = 0
    max_prefix_sum = 0
    min_prefix_sum = 0
    prev_max_prefix_sum = 0
    for num in nums[1:]:
        prefix_sum += num
        min_prefix_sum = min(prefix_sum, min_prefix_sum)
        max_prefix_sum = max(prefix_sum, max_prefix_sum)
        if max_prefix_sum > prev_max_prefix_sum:
            delta = max_prefix_sum - prev_max_prefix_sum
            ops.append((min_prefix_sum, delta))
            prev_max_prefix_sum = max_prefix_sum

ops.sort(key=lambda x: -x[0])
for min_prefix_sum, delta in ops:
    if x + min_prefix_sum < 0:
        break
    else:
        x += delta
print(x)
