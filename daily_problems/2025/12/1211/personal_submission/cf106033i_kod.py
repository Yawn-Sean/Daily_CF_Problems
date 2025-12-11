n ,k = il()
n -= 1
f = Factorial(n * 2, mod)
ans = 0
for i in range(n - k - 1, n + k + 1):
    ans += f.combi(2 * n, i)
    ans %= mod
print(ans)
