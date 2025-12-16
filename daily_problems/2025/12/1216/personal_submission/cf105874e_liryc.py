'''
https://codeforces.com/gym/105874/submission/353645371
'''
def solve(n: int, q: int, a: int, queries: list[tuple[int, int]]) -> list[int]:
    MOD = 1000000007
    prime = list(range(200001))
    for i in range(2, 200001):
        if prime[i] == i:
            for j in range(i, 200001, i):
                prime[j] = i
    fac = Factorial(200000, MOD)    
    pr = [n] * (200001)
    st = SegTree(lambda x, y: x * y % MOD, 1, n)
    ans = [0] * q
    for i in range(n - 1, -1, -1):
        prs = []
        x = a[i]
        while x > 1:
            p = prime[x]
            prs.append(p)
            while x % p == 0:
                x //= p
        val = 1
        for p in prs:
            if pr[p] < n:
                st.set(pr[p], st.get(pr[p]) * fac.inv(p) % MOD)
            val *= p
            pr[p] = i
        st.set(i, val)
        for idx, r in queries[i]:
            ans[idx] = st.prod(0, r + 1)
    return ans
