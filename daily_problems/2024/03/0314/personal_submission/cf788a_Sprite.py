from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))
for i in range(n-1):
    a[i] = abs(a[i] - a[i+1]) * (-1)**i
a.pop()
prefix_a = [0] + list(accumulate(a))

ans_1 = 0
minus_1 = 0
for i in range(0, n-1, 2):
    minus_1 = min(minus_1, prefix_a[i])
    ans_1 = max(ans_1, prefix_a[i+1] - minus_1)

ans_2 = 0
minus_2 = 0
for i in range(1, n-1, 2):
    minus_2 = max(minus_2, prefix_a[i])
    ans_2 = min(ans_2, prefix_a[i+1] - minus_2)
print(max(ans_1, -ans_2))
