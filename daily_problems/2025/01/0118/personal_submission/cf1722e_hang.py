def main():
    n,q = map(int, input().split())
    p = [[0] * 1001 for _ in range(1001)]
    for _ in range(n):
        h,w = map(int, input().split())
        p[h][w] += h * w
    for i in range(1000):
        for j in range(1001):
            p[i + 1][j] += p[i][j]
    for i in range(1001):
        for j in range(1000):
            p[i][j + 1] += p[i][j]
    res = []
    for _ in range(q):
        hs,ws,hb,wb = map(int, input().split())
        res.append(p[hb - 1][wb - 1] - p[hs][wb - 1] - p[hb - 1][ws] + p[hs][ws])
    print(*res, sep='\n')
t = int(input())
for _ in range(t):  
    main()