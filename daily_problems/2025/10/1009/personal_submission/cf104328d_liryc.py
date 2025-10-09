'''
https://codeforces.com/gym/104328/submission/342672643
https://www.doubao.com/thread/w051f1539ee192c49
'''
# tree DP, primes

# preset (skipped)
# MAXN = 10000
# prime_set = /* list of primes up to MAXN */
# def initPrimes(): ...
# def prime_elements(n: int): /* yield (prime, count) pairs of n's prime factorization */

# edges have adjusted to 0-based index
def solve(n: int, pa: list[int], edges: list[list[int]]) -> bool:
    # build tree
    tg = [[] for _ in range(n)]
    for u, v in edges:
        tg[u].append(v)
        tg[v].append(u)

    # find p such that cnt[p] >= n / 2
    half_n = n >> 1
    cnt = Counter(pa)
    cp, candidates = Counter(), []
    for x, c in cnt.items():
        for p, _ in prime_elements(x):
            if cp[p] < 0: continue
            cp[p] += c
            if cp[p] > half_n:
                candidates.append(p)
                cp[p] = -1

    # prepare for tree DP - build post order of the tree
    sa, stk = [], [(0, -1)]
    while stk:
        u, parent = stk.pop()
        sa.append((u, parent))
        for v in tg[u]:
            if v != parent:
                stk.append((v, u))
    sa.reverse()

    # do tree DP for each candidate
    dp = [0] * n
    for x in candidates:
        for u, parent in sa:
            if pa[u] % x == 0:
                dp[u] = 1
                for v in tg[u]:
                    if v != parent:
                        if dp[v] + dp[u] > half_n:
                            return True
                        elif dp[v] + 1 > dp[u]:
                            dp[u] = dp[v] + 1
            else:
                dp[u] = 0
    return False
