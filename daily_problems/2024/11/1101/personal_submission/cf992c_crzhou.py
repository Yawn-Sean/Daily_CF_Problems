x, k = MII()

print((x * pow(2, k + 1, MOD) % MOD - pow(2, k, MOD) % MOD + 1) % MOD if x else 0)
