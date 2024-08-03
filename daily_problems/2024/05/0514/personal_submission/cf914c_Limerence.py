import sys

input = sys.stdin.readline


def inp():
    return int(input().strip())


def inlt():
    return list(map(int, input().strip().split()))


def insr():
    s = input().strip()
    return list(s[: len(s) - 1])


def invr():
    return map(int, input().strip().split())


def ins():
    return input().strip()


MOD = 10**9 + 7
n = ins()
k = inp()

if k:
    # after one step, max bits = 1000
    cnt = {0: [1], 1: [2]}
    f = [0] * 1001
    f[1] = 0
    f[2] = 1

    # combinatorial number
    comb = [[0] * 1001 for _ in range(1001)]
    for i in range(0, 1001):
        comb[i][0] = 1
    for i in range(1, 1001):
        for j in range(1, i + 1):
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD

    for i in range(3, 1001):
        f[i] = 1 + f[bin(i).count("1")]
        if f[i] not in cnt:
            cnt[f[i]] = [i]
        else:
            cnt[f[i]].append(i)

    candidate = cnt.get(k - 1, [])
    ans = 0 if k != 1 else -1
    for x in candidate:
        left_ones = x
        left_bits = len(n)
        if left_bits < left_ones:
            break
        for i, ch in enumerate(n):
            if ch == "0":
                left_bits -= 1
                continue
            ans += comb[left_bits - 1][left_ones] if left_ones <= left_bits - 1 else 0
            left_bits -= 1
            left_ones -= 1
            if left_ones == 0:
                ans += 1
                break
    ans %= MOD
    print(ans)
else:
    print(1)
