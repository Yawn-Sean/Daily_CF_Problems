'''
https://codeforces.com/gym/105262/submission/355241304
'''
def manacher(v, ra):
    n, p = len(v), 0
    for i in range(1, n - 1):
        if p + ra[p] > i:
            ra[i] = min(p + ra[p] - i, ra[p - (i - p)])
        while v[i + ra[i]] == v[i - ra[i]]:
            ra[i] += 1
        if i + ra[i] > p + ra[p]:
            p = i

def solve(n: int, a: list[int]) -> int:
    MOD = 10**9 + 7
    v = [0] * (2 * n + 1)
    v[0] = -2
    v[2 * n] = -1
    
    for i in range(n):
        v[2 * i + 1] = a[i]
    n = 2 * n + 1
    
    ra = [0] * n
    manacher(v, ra)
    
    pre = [0] * (n + 2)
    for i in range(1, n - 1):
        ra[i] -= ra[i] & 1 ^ (1 if v[i] else 0)
        
        pre[i - ra[i]] += 1
        pre[i + 1] -= 2
        pre[i + ra[i] + 2] += 1
    
    for i in range(1, n):
        pre[i] += pre[i - 1]
    for i in range(1, n):
        pre[i] += pre[i - 1]    

    for i in range(n):
        pre[i] >>= 1
    
    ans = 0
    for i in range(1, n - 1):
        ans = (ans + pre[i] * v[i]) % MOD
    
    return ans
