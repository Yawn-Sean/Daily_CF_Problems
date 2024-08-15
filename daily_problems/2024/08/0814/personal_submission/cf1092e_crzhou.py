N = 1000 + 10
maxx1 = [0] * N
maxx2 = [0] * N
dep = [0] * N
vs = [0] * N
flag = [0] * N
pre = [0] * N
vis = [0] * N
a = defaultdict(list)
answer = []
cnt = 0

def dfs(x, fa):
    vis[x] = 1
    for v in a[x]:
        if v == fa:
            continue
        pre[v] = x
        dep[v] = dep[x] + 1
        dfs(v, x)

def main():
    global cnt
    n, m = map(int, input().split())
    nowm = -1
    nowmi = -1

    for _ in range(m):
        u, v = map(int, input().split())
        a[u].append(v)
        a[v].append(u)

    for i in range(1, n + 1):
        if vis[i]:
            continue
        for j in range(1, n + 1):
            dep[j] = pre[j] = 0
        dfs(i, -1)
        now = []
        now1 = []
        maxn = 0
        maxni = i

        for j in range(1, n + 1):
            if dep[j] > maxn:
                maxn = dep[j]
                maxni = j
        x = maxni

        for j in range(1, n + 1):
            dep[j] = pre[j] = 0
        dfs(maxni, -1)
        maxn = 0
        maxni = i

        for j in range(1, n + 1):
            if dep[j] > maxn:
                maxn = dep[j]
                maxni = j
        x = maxni
        while x:
            now1.append(x)
            x = pre[x]
        now1.reverse()
        for i in now1:
            now.append(i)
        maxx1[cnt] = (len(now) - 1) // 2
        maxx2[cnt] = (len(now) - 1) - ((len(now) - 1) // 2)
        flag[cnt] = now[int((len(now) / 2.0))]
        if max(maxx1[cnt], maxx2[cnt]) > nowm:
            nowm = max(maxx1[cnt], maxx2[cnt])
            nowmi = cnt
        cnt += 1

    for i in range(cnt):
        if i == nowmi:
            continue
        a[flag[nowmi]].append(flag[i])
        a[flag[i]].append(flag[nowmi])
        answer.append((flag[nowmi], flag[i]))

    for j in range(1, n + 1):
        dep[j] = pre[j] = 0
    dfs(1, -1)
    now = []
    now1 = []
    maxn = 0
    maxni = 1

    for j in range(1, n + 1):
        if dep[j] > maxn:
            maxn = dep[j]
            maxni = j
    x = maxni

    for j in range(1, n + 1):
        dep[j] = pre[j] = 0
    dfs(maxni, -1)
    maxn = 0
    maxni = 1

    for j in range(1, n + 1):
        if dep[j] > maxn:
            maxn = dep[j]
            maxni = j

    print(maxn)
    for i in answer:
        print(i[0], i[1])

if __name__ == "__main__":
    main()
