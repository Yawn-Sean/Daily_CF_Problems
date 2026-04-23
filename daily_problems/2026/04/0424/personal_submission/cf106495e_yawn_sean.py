# Submission link: https://codeforces.com/gym/106495/submission/372236345
def main():
    n, q = MII()
    
    pr = [1] * (n + 1)
    primes = []
    
    for i in range(2, n + 1):
        if pr[i]:
            primes.append(i)
            for j in range(i * 2, n + 1, i):
                pr[j] = 0
    
    ans = [1]
    stk = [(1, 0)]
    
    while stk:
        x, idx = stk.pop()
        if idx == len(primes) or x * primes[idx] > n: continue
        
        stk.append((x, idx + 1))
        while x * primes[idx] <= n:
            x *= primes[idx]
            ans.append(x)
            stk.append((x, idx + 1))
    
    outs = []
    for _ in range(q):
        idx = II()
        outs.append(ans[idx - 1])
    
    print('\n'.join(map(str, outs)))