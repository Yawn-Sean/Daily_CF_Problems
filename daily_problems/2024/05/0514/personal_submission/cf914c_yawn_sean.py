# Submission link: https://codeforces.com/contest/914/submission/260864172
def main():
    n = I()
    k = II()

    if k == 0:
        print(1)
        exit()

    if k == 1:
        print(len(n) - 1)
        exit()

    ops = [0] * (1 << 10)
    for i in range(2, 1 << 10):
        ops[i] = ops[i.bit_count()] + 1

    mod = 10 ** 9 + 7

    ones = [0] * (1 << 10)
    cur = 0
    for c in n:
        for i in range((1 << 10) - 1, 0, -1):
            ones[i] += ones[i-1]
            ones[i] %= mod
        if c == '1':
            ones[cur] += 1
            ones[cur] %= mod
            cur += 1

    ans = 0
    for i in range(1, 1 << 10):
        if ops[i] == k - 1:
            ans += ones[i]
            ans %= mod

    if ops[n.count('1')] == k - 1:
        ans += 1
        ans %= mod

    print(ans)