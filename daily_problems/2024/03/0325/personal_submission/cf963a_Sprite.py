n, a, b, k = map(int, input().split())
s = str(input())
MOD = 10**9+9

ans = 0
first = pow(a, n, MOD)
ni_a = pow(a, -1, MOD)
b_a = (b * ni_a) % MOD
b_a_k = pow(b_a, k, MOD)
turn = (n+1) // k
for i in range(k):
    if s[i] == '+':
        ans = (ans + first) % MOD
    else:
        ans = (ans - first) % MOD
    first = (first * b_a) % MOD

if b_a_k == 1:
    ans = (ans * turn) % MOD
else:
    pl = (1 - pow(b_a_k, turn, MOD)) * pow(1 - b_a_k, -1, MOD) % MOD
    ans = (ans * pl) % MOD
print(ans)
