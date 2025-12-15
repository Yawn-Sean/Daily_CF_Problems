MOD = 998244353

# print(fastpow(3, 2))
# def dfs(now, fa) :
    
t = int(input())
def fastpow(a, b) :
    res = 1
    while b :
        if b % 2 :
            res = res * a % MOD
        a = a * a % MOD
        b = b >> 1
    return res
# print(n)
N = 212345
p = [0] * N
inv = [0] * N
p[0] = inv[0] = 1
for i in range(1, N) :
    p[i] = p[i - 1] * i % MOD
    inv[i] = fastpow(p[i], MOD - 2)
while t :
    t -= 1
    n = int(input())
    ans = 0
    edge = [[] for _ in range(n + 1)]

    def C(a, b) :
        if a < b:
            return 0
        return p[a] * inv[b] % MOD * inv[a - b] % MOD

    def dfs(now, fa, cnt) :
        global ans
        ans = ans + p[cnt] * C(n, cnt + 1) % MOD * p[n - cnt - 1] % MOD
        ans = ans % MOD
        # print(ans)
        for i in edge[now] :
            if i == fa :
                continue
            cnt += 1
            dfs(i, now, cnt)
            cnt -= 1
    # print(fastpow(2, 10))
    for i in range(n - 1) :
        a, b = map(int, input().split())
        edge[a].append(b)
        edge[b].append(a)
    dfs(1, -1, 0)
    print(ans * inv[n] % MOD)
    # print(p)

    # print(a, b)
    # pass


        
        
