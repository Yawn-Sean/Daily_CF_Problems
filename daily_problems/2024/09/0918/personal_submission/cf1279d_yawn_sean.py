# Submission link: https://codeforces.com/contest/1279/submission/281674859
def main():
    mod = 998244353
    fact = Factorial(10 ** 6, mod)
    
    n = II()
    probs = [0] * 10 ** 6
    
    pools = []
    for _ in range(n):
        _, *nums = GMI()
        for v in nums:
            probs[v] += 1
        pools.append(nums)
    
    for i in range(10 ** 6):
        probs[i] = probs[i] * fact.inv(n) % mod
    
    ans = 0
    for i in range(n):
        k = len(pools[i])
        for v in pools[i]:
            ans += probs[v] * fact.inv(k) % mod
    
    print(ans * fact.inv(n) % mod)