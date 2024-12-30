MOD = 1000000007
Maxm = 5000005

t = [0] * Maxm
v = [0] * Maxm
f = [0] * Maxm
Pow = [0] * Maxm

def init():
    for i in range(2, Maxm):
        if v[i] == 0:
            t[i] = (i - 1) * i // 2
            for j in range(2 * i, Maxm, i):
                if v[j] == 0:
                    f[j] = i
                v[j] = 1
    
    for i in range(2, Maxm):
        if v[i]:
            t[i] = t[f[i]] * i // f[i] + t[i // f[i]]
        t[i] %= MOD

def main():
    T, l, r = MII()

    init()
    
    Pow[0] = 1
    for i in range(1, r - l + 1):
        Pow[i] = Pow[i - 1] * T % MOD

    ans = 0
    for i in range(l, r + 1):
        ans += Pow[i - l] * t[i] % MOD
        ans %= MOD

    print(ans)

if __name__ == "__main__":
    main()
