# submission url: https://codeforces.com/contest/1279/submission/281694198
mod = 998244353

n = int(input())

cnt = [0] * (10 ** 6 + 1)
fin = [0] * (10 ** 6 + 1)

for _ in range(n):
    a = list(map(int, input().split()))
    for i in a[1:]:
        cnt[i] += 1 
        fin[i] += pow(n * a[0], -1, mod)
        fin[i] %= mod 
ans = 0 
for x, y in zip(cnt, fin):
    ans += y * x * pow(n, -1, mod) % mod 
    ans %= mod 

print(ans)
