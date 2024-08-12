n, k = map(int, input().split())
s = k * (k + 1) // 2
if s > n:
    print('NO')
else:
    a = n - s
    b = a // k
    s += b * k
    nums = list(range(1 + b, 1 + b + k))


    while s < n:
        for i in range(k - 1, 0, -1):
            if nums[i] + 1 <= 2 * nums[i - 1]:
                nums[i] += 1
                s += 1
                if s == n:
                    break
            else:
                break
        if i == k - 1:
            break

    if s == n:
        print('YES')
        print(*nums)
    else:
        print('NO')
