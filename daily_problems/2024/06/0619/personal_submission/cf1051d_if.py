mod = 998244353
n,k = list(map(int,input().split()))
if k > 2*n:
    print(0)
elif k == 1 or k == 2*n:
    print(2)
else:
    same = [0] * (k+1)
    same[1] = 2
    diff = [0] * (k+1)
    diff[2] = 2
    for i in range(2, n+1):
        for j in range(min(k, 2*i), 1, -1):
            same[j] = same[j] + 2*diff[j] + same[j-1]
            same[j] %= mod
            diff[j] = diff[j] + 2*same[j-1] + diff[j-2]
            diff[j] %= mod
    print((same[k] + diff[k]) % mod)
