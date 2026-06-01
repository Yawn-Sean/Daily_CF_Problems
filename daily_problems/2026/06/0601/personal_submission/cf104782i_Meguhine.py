from array import array

MOD = 10**9 + 7
N = 5 * 10**6 + 5

fc = array('i', [0] * N)
fc[0] = 1
for i in range(1, N):
    fc[i] = fc[i - 1] * i % MOD
fc_inv = array('i', [0] * N)
fc_inv[-1] = pow(fc[-1], -1, MOD)
for i in range(N - 2, -1, -1):
    fc_inv[i] = fc_inv[i + 1] * (i + 1) % MOD


def C(x: int, y: int) -> int:
    return fc[x] * fc_inv[y] * fc_inv[x - y] % MOD


K, S, T = map(int, input().split())
M, R = divmod(K, T)
if R == 0:
    s, r = divmod(S, M)
    if r:
        print("0")
    else:
        print(C(s - 1, T - 1))
    exit(0)
c1, c2 = R, T - R
S2_lim = M * c2
ans = 0
for s1 in range(R, S):
    S2 = S - (M + 1) * s1
    if S2 < S2_lim:
        break
    s2, r = divmod(S2, M)
    if r == 0:
        ans += C(s1 - 1, c1 - 1) * C(s2 - 1, c2 - 1)
print(ans % MOD)


"""
M*sum(a) + sum(a[0]...a[R-1]) == S
(M+1)*sum(a[0]...a[R-1]) + M*sum(a[R]...a[T-1]) == S
S 很小, 枚举两部分单独的和, 然后加起来即可
"""
