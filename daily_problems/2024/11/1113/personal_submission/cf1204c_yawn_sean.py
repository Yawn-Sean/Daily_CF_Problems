# Submission link: https://codeforces.com/contest/1204/submission/291253581
def main():
    n = II()
    grid = [I() for _ in range(n)]

    dis = [[n + 1] * n for _ in range(n)]

    for i in range(n):
        dis[i][i] = 0

    for i in range(n):
        for j in range(n):
            if grid[i][j] == '1':
                dis[i][j] = 1

    for i in range(n):
        for j in range(n):
            for k in range(n):
                dis[j][k] = fmin(dis[j][k], dis[j][i] + dis[i][k])

    m = II()
    route = LGMI()

    ans = [route[0]]
    pt = 0

    while pt < m - 1:
        npt = pt
        while npt < m - 1 and dis[route[pt]][route[npt + 1]] == dis[route[pt]][route[npt]] + 1:
            npt += 1
        ans.append(route[npt])
        pt = npt

    print(len(ans))
    print(' '.join(str(x + 1) for x in ans))