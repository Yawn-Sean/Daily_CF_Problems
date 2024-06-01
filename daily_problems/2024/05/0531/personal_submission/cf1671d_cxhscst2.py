def func(x : int) -> int :
	return x if x > 0 else 0

for _ in range(int(input())) :
    n, x = map(int, input().split())
    a = [int(x) for x in input().split()]
    
    ans = 0

    for i in range(n - 1) :
        ans += abs(a[i + 1] - a[i])

    mx = min(func(x - a[0]), func(x - a[-1]), 2 * func(x - max(a)))
    mn = min(func(a[0] - 1), func(a[-1] - 1), 2 * func(min(a) - 1))

    print(ans + mx + mn)
