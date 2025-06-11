# Submission Link: https://codeforces.com/contest/111/submission/269488111
M = 10 ** 5
prime_factor = list(range(M + 1))
for i in range(2, M + 1):
    if prime_factor[i] == i:
        for j in range(i * i, M + 1, i):
            prime_factor[j] = i

def factors(x):
    res = [1]
    while x > 1:
        k = len(res)
        p = prime_factor[x]
        while x % p == 0:
            for _ in range(k):
                res.append(res[-k] * p)
            x //= p
    return res

def main():
    last_vis = [-1] * (M + 1)

    q = II()
    outs = []

    for i in range(q):
        x, y = MII()
        ans = 0
        for f in factors(x):
            if i - last_vis[f] > y:
                ans += 1
            last_vis[f] = i
        outs.append(ans)

    print('\n'.join(map(str, outs)))