# submission url: https://codeforces.com/contest/1065/submission/281077341

MOD = 998244353
n, m, s = map(int, input().split())

ans, cur = 1, 0

for num in map(int, input().split()):
    p = pow(s, num - cur, MOD)
    ans *= p * (p + 1) // 2 % MOD 
    ans %= MOD 
    cur = num 

print(ans * pow(s, n - cur * 2, MOD) % MOD)
