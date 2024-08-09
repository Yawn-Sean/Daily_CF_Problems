MOD = 10**9 + 7

def qp(a, b):
    ret = 1
    a %= MOD
    while b:
        if b & 1:
            ret = ret * a % MOD
        a = a * a % MOD
        b >>= 1
    return ret

def init(n, k):
    c = [0] * (n + 1)
    c[k] = 1
    for i in range(k + 1, n + 1):
        c[i] = (c[i-1] * (i % MOD)) % MOD * qp(i - k, MOD - 2) % MOD
    return c

def main():
    n, k = map(int, input().split())
    c = init(n, k)
    mp = {}
    
    for _ in range(n):
        a, b = map(int, input().split())
        if a in mp:
            mp[a] += 1
        else:
            mp[a] = 1
        
        if b + 1 in mp:
            mp[b + 1] -= 1
        else:
            mp[b + 1] = -1

    sorted_keys = sorted(mp.keys())
    val = 0
    ans = 0

    for i in range(1, len(sorted_keys)):
        lit = sorted_keys[i - 1]
        it = sorted_keys[i]
        val += mp[lit]
        ans = (ans + (it - lit) % MOD * c[val]) % MOD

    print(ans)
