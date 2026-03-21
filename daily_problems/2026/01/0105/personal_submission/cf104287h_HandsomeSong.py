t=int(input())
mod=10**9+7
for _ in range(t):
    n=int(input())
    inv2 = (mod + 1) // 2 
    total_d=0
    total_v=(pow(2,n,mod)-1+mod)%mod
    pow_i = 2
    pow_n_minus_i = pow(2, n - 1, mod)
    for i in range(1,n):
        item1 = pow_i
        item2 = (pow_n_minus_i - 1 + mod) % mod
        item3 = (total_v - pow_n_minus_i + 1 + mod) % mod
        total_d = (total_d + item1 * item2 % mod * item3 % mod) % mod
        pow_i = (pow_i * 2) % mod
        pow_n_minus_i = (pow_n_minus_i * inv2) % mod
    print(total_d*2%mod)
