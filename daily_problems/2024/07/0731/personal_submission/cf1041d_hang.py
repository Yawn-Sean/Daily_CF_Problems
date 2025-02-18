def main():
    n,h = map(int,input().split())
    g = []
    for _ in range(n):
        x1, x2 = map(int,input().split())
        g.append([x1,x2])
    l,r = 0,0
    ch = h
    p = 0
    ans = 0
    while l < n:
        while r < n - 1 and g[r + 1][0] - g[r][1] < ch:
            p += g[r][1] - g[r][0]
            ch -= g[r+1][0] - g[r][1]
            r += 1
        ans  = max(ans, p + g[r][1] - g[r][0] + h)
        p -= g[l][1] - g[l][0]
        l += 1
        if l < n:
            ch += g[l][0] - g[l-1][1]
    print(ans)
main()