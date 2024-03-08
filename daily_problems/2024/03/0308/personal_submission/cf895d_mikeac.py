import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    s = list(ord(c) - 97 for c in input())
    t = list(ord(c) - 97 for c in input())

    n = len(s)
    cnt = [0] * 26
    for c in s:
        cnt[c] += 1

    # 阶乘
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i-1] * i % MOD
    # 逆元
    inverse = [0] * (n + 1)
    inverse[n] = pow(fact[n], MOD - 2, MOD)
    for i in range(n, 0, -1):
        inverse[i-1] = inverse[i] * i % MOD
    
    def f(ss) -> int:
        tmp_cnt = cnt[:]
        cur = fact[n]
        for c in tmp_cnt:
            cur = cur * inverse[c] % MOD
        
        ans = 0
        for i in range(n):
            cur = cur * fact[n - i - 1] * inverse[n - i] % MOD
            
            for j in range(ss[i]):
                ans = (ans + cur * tmp_cnt[j]) % MOD
            
            if tmp_cnt[ss[i]] == 0: break

            cur = (cur * tmp_cnt[ss[i]]) % MOD
            tmp_cnt[ss[i]] -= 1
        return ans

    print((f(t) - f(s) - 1) % MOD)

solve()
