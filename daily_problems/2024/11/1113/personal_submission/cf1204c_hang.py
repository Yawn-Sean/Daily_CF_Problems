def main():
    n = int(input())
    g = [input() for _ in range(n)]
    d = [[n + 1] * n for _ in range(n)]
    for i in range(n):
        d[i][i] = 0
    for i in range(n):
        for j in range(n):
            if g[i][j] == '1':
                d[i][j] = 1
    for i in range(n):
        for j in range(n):
            for k in range(n):
                d[j][k] = min(d[j][k], d[j][i] + d[i][k])
    m = int(input())
    p = list(map(lambda x:int(x) - 1,input().split()))
    ans = [p[0]]
    pt = 0
    while pt < m - 1:
        nxt = pt
        while nxt < m - 1 and d[p[pt]][p[nxt + 1]] == d[p[pt]][p[nxt]] + 1:
            nxt += 1
        ans.append(p[nxt])
        pt = nxt
    print(len(ans))
    ans = [x + 1 for x in ans]
    print(*ans)
main()