from math import gcd

n = int(input())
arr = list(map(int, input().split()))
print('YES')

if gcd(*arr) > 1:
    print(0)
else:
    ans = 0
    i = 0
    while i < n:
        if arr[i] % 2 == 0:
            i += 1
        elif i+1 < n and arr[i+1] % 2 == 1:
            ans += 1
            i += 2
        else:
            ans += 2
            i += 2
    print(ans)