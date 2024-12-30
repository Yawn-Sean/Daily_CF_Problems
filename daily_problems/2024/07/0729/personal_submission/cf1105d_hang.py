def main():
    n,m,p = map(int,input().split())
    s = list(map(int,input().split()))
    g = []
    for _ in range(n):
        g.append(list(input()))
    dex = [[] for _ in range(p + 1)]
    ans = [0] * (p + 1)
    for i in range(n):
        for j in range(m):
            if '1' <= g[i][j] <= '9':
                t = ord(g[i][j]) - ord('0')
                dex[t].append((i,j))
                ans[t] += 1

    dirs = [(-1,0),(1,0),(0,-1),(0,1)]
    changed = True
    while changed:
        changed = False
        for i in range(1,p + 1):
            for _ in range(s[i - 1]):
                nxt_dex = []
                for x,y in dex[i]:
                    for dx,dy in dirs:
                        nx,ny = x + dx,y + dy
                        if 0 <= nx < n and 0 <= ny < m and g[nx][ny] == '.':
                            g[nx][ny] = chr(i + ord('0'))
                            ans[i] += 1
                            nxt_dex.append((nx,ny))
                dex[i] = nxt_dex
                if len(dex[i]) == 0:
                    break
            if len(dex[i]):
                changed = True
        if not changed:
            break
    print(*ans[1:])
main()
