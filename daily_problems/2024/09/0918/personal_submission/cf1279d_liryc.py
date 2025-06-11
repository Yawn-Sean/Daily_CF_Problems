'''
https://codeforces.com/contest/1279/submission/281686479
1279D
2024/9/18 Y1
1700
ref, probabilities
'''

# Factorial类声明见模板
# class Factorial:

if __name__ == '__main__':
    mod = 998244353
    fact = Factorial(10 ** 6, mod)
    
    n = int(input())
    probs = [0] * 1000000
    
    pools = []
    for _ in range(n):
        _, *nums = map(lambda s: int(s) - 1, input().split())
        for v in nums:
            probs[v] += 1
        pools.append(nums)
    
    for i in range(1000000):
        probs[i] = probs[i] * fact.inv(n) % mod
    
    ans = 0
    for i in range(n):
        k = len(pools[i])
        for v in pools[i]:
            ans += probs[v] * fact.inv(k) % mod
    
    print(ans * fact.inv(n) % mod)