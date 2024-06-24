# Submission Link: https://codeforces.com/contest/863/submission/267242134
def main():
    k, a, b = MII()

    grid1 = [LGMI() for _ in range(3)]
    grid2 = [LGMI() for _ in range(3)]

    grid = [
        [0, 2, 1],
        [1, 0, 2],
        [2, 1, 0]
    ]

    a -= 1
    b -= 1

    vis = {}
    acc1 = [0]
    acc2 = [0]

    for i in range(k):
        if a * 3 + b in vis:
            last_vis = vis[a * 3 + b]
            cycle = i - last_vis
            x, y = divmod(k - last_vis, cycle)
            ans1 = acc1[last_vis] + x * (acc1[i] - acc1[last_vis]) + acc1[last_vis + y] - acc1[last_vis]
            ans2 = acc2[last_vis] + x * (acc2[i] - acc2[last_vis]) + acc2[last_vis + y] - acc2[last_vis]
            print(ans1, ans2)
            exit()
        
        acc1.append(acc1[-1])
        acc2.append(acc2[-1])
        if grid[a][b] == 1: acc1[-1] += 1
        elif grid[a][b] == 2: acc2[-1] += 1
        vis[a * 3 + b] = i
        a, b = grid1[a][b], grid2[a][b]

    print(acc1[-1], acc2[-1])