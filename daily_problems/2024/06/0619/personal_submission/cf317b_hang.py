
def main():
    n,t = map(int,input().split())
    g = [[0] * 160 for _ in range(160)]
    g[75][75] = n
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    while True:
        find = True
        for i in range(160):
            for j in range(160):
                if g[i][j] >= 4:
                    find = False
                    v,g[i][j] = divmod(g[i][j],4)
                    for k in range(4):
                        nx = i + dx[k]
                        ny = j + dy[k]
                        g[nx][ny] += v

        if find:
            break
    ans = []
    for _ in range(t):
        x,y = map(int,input().split())
        if abs(x) > 75 or abs(y) > 75:
            ans.append(0)
        else:
            ans.append(g[x+75][y+75])
    print(*ans,sep='\n')

if __name__ == '__main__':
    main()
