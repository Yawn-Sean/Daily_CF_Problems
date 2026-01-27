for i in range(ix()):
    k, x = il()
    print(x * pow(k + 1, x.bit_count() - 1, MOD) % MOD)
