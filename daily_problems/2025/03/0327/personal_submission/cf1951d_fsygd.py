T = int(input())
for _ in range(T):
    n, k = list(map(int, input().split(' ')))
    if n == k:
        print('YES\n1 1')
    elif k * 2 < n + 2:
        print(f'YES\n2 {n - k + 1} 1')
    else:
        print('NO')