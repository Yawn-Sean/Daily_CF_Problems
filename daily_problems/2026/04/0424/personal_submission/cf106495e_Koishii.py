N = 1000006
primes = []
vis = [False] * N
for i in range(2, N):
    if not vis[i]:
        vis[i] = True
        primes.append(i)
    for p in primes:
        if i * p >= N:
            break
        vis[i * p] = True
        if i % p == 0:
            break


n, q = map(int, input().split())

ans = []
def dfs(now, id):
    ans.append(now)
    for j in range(id, len(primes)):
        if now * primes[j] <= n:
            dfs(now * primes[j], j)
        else:
            break

dfs(1, 0)

outs = []
for _ in range(q):
    k = int(input())
    outs.append(ans[k - 1])

print('\n'.join(map(str, outs)))
