def main():
    n,m = map(int, input().split())
    g = []
    for _ in range(m):
        a = list(map(int, input().split()))
        g.append(a[1:])
    cnt = [0] * (n + 1)
    ans = [0] * m

    v = 0
    for i in range(m):
        ans[i] = g[i][0]
        cnt[ans[i]] += 1
        if cnt[ans[i]] > cnt[v]:
            v = ans[i]
        
    mx = m - m // 2 # 最大频率
    for i in range(m):
        if ans[i] == v and cnt[v] > mx and len(g[i]) > 1:
            ans[i] = g[i][1]
            cnt[v] -= 1

    if cnt[v] <= mx:
        print('YES')
        print(' '.join(map(str, ans)))
    else:
        print('NO')

t = int(input())
for _ in range(t):
    main()