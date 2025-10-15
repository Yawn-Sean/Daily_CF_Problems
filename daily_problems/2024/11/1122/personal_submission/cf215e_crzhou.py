def cal(len, j, o, a):
    c = 0
    b = 1
    for i in range(1, j + 1):
        c += (a[len - i] << (j - i))
    b = c
    for i in range(1, len // j):
        b <<= j
        b += c
    sum_val = 1 << (j - 1)
    return c - sum_val + (b <= o)

def solve(w):
    a = []
    len_ = 0
    ww = w
    ans = 0
    while w:
        a.append(w % 2)
        w //= 2
        len_ += 1
    
    for i in range(2, len_ + 1):
        dp = [0] * 100
        for j in range(1, i // 2 + 1):
            if i % j:
                continue
            if i < len_:
                dp[j] += (1 << (j - 1))
            else:
                dp[j] += cal(len_, j, ww, a)
            for k in range(1, j):
                if j % k == 0:
                    dp[j] -= dp[k]
            ans += dp[j]
    return ans

n, m = map(int, input().split())
print(solve(m) - solve(n - 1))
