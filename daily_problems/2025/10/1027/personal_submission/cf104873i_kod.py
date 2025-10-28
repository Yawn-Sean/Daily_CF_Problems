n = ix()
ans = [[] for _ in range(n)]

def query(q):
    print('?', len(q), *q, flush=True)
    t = il()
    return t[1:]

def answer(ans):
    res = []
    for x in ans:
        res += len(x),
        res += x
    print('!', *res)

if n == 1:
    ans[0] = query([1])
else:
    for i in range(0, n, n // 2):
        t = []
        for j in range(i, i + n // 2):
            if j >= n: break
            t += j + 1,
            t += j + 1,
        res = query(t)
        k = len(t) // 2
        p = 0
        for j in range(i, i + k):
            pp = p + 1
            while res[pp] != res[p]:
                pp += 1
            ans[j] = res[p:pp]
            p = 2 * pp - p
answer(ans)
