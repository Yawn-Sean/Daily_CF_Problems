def main():
    def count(max_s):
        ans = 0
        tmp = list(cnter)
        for i, v in enumerate(max_s):
            base = f[n-i-2] if i + 1 < n else 1
            v_sum = 0
            for j, cnt in enumerate(tmp):
                if cnt == 0:
                    continue
                base *= g[cnt-1]
                base %= MOD
                if j < v:
                    v_sum += cnt
            ans += base * v_sum % MOD
            ans %= MOD
            if tmp[v] == 0:
                break
            tmp[v] -= 1
        return ans

    MOD = 10 ** 9 + 7
    a = [ord(c) - ord("a") for c in input()]
    b = [ord(c) - ord("a") for c in input()]

    n = len(a)
    cnter = [0] * 26
    for v in a:
        cnter[v] += 1

    f = [1] * n
    for i in range(1, n):
        f[i] = f[i-1] * (i + 1) % MOD
    g = [pow(v, MOD-2, MOD) for v in f]

    return (count(b) - count(a) - 1 + MOD) % MOD


print(main())
