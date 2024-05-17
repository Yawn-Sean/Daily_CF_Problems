def main():
    s = input()
    g = []
    g.append([s[0], 1])
    n = len(s)
    for i in range(1, n):
        if s[i] == g[-1][0]:
            g[-1][1] += 1
        else:
            g.append([s[i], 1])
    ans = 0
    while len(g) > 1:
        ans += 1
        c = []
        if g[0][1] > 1:
            c.append([g[0][0], g[0][1] - 1])
        for i in range(1, len(g) - 1):
            if g[i][1] > 2:
                if c and c[-1][0] == g[i][0]:
                    c[-1][1] += g[i][1] - 2
                else:
                    c.append([g[i][0], g[i][1] - 2])
        if g[-1][1] > 1:
            if c and c[-1][0] == g[-1][0]:
                c[-1][1] += g[-1][1] - 1
            else:
                c.append([g[-1][0], g[-1][1] - 1])
                    
        g = c
    print(ans)

main()