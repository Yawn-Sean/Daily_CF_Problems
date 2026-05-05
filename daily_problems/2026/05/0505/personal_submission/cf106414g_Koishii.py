outs = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    d = dict()
    cnt = dict()
    for x in a:
        cnt[x] = 0
        if x in d: d[x] += 1
        else: d[x] = 1

    c1 = [-1, -1] #cnt, x
    c2 = [-1, -1]

    ans = 0
    for x in a:
        if c1[0] > 0 and c1[1] != x:
            ans = max(ans, c1[0] + d[x] - cnt[x])
        elif c2[0] > 0 and c2[1] != x:
            ans = max(ans, c2[0] + d[x] - cnt[x])

        cnt[x] += 1
        if cnt[x] > c1[0]:
            if c1[1] == x:
                c1 = [cnt[x], x]
            else:
                c2 = c1
                c1 = [cnt[x], x]
        elif cnt[x] > c2[0]:
            c2 = [cnt[x], x]

    outs.append(ans)

print('\n'.join(map(str, outs)))
