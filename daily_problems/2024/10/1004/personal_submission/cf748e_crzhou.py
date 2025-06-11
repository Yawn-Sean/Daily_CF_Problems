maxn = 10**7 + 10
a = [0] * maxn

n, k = MII()
total_sum = 0

nums = LII()

for x in nums:
    a[x] += 1
    total_sum += x

if total_sum < k:
    print_number(-1)
else:
    total_sum = 0
    for i in range(10000000, 0, -1):
        if a[i]:
            total_sum += a[i]
            if i * 2 <= 10000000:
                total_sum -= a[i * 2] + a[i * 2 - 1]
            if i == 1:
                total_sum += a[i]
            if total_sum >= k:
                print_number(i)
                break
            a[i // 2] += a[i]
            a[(i + 1) // 2] += a[i]
