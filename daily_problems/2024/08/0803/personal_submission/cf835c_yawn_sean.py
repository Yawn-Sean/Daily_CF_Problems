# Submission link: https://codeforces.com/contest/835/submission/274089961
def main():
    n, q, c = MII()

    grid = [[0] * (101 * 101) for _ in range(c + 1)]

    def f(x, y): return x * 101 + y

    for _ in range(n):
        x, y, s = MII()
        for i in range(c + 1):
            grid[i][f(x, y)] += (s + i) % (c + 1)
            

    for i in range(c + 1):
        for x in range(101):
            for y in range(100):
                grid[i][f(x, y + 1)] += grid[i][f(x, y)]
        
        for y in range(101):
            for x in range(100):
                grid[i][f(x + 1, y)] += grid[i][f(x, y)]

    outs = []
    for _ in range(q):
        t, x1, y1, x2, y2 = MII()
        t %= c + 1
        outs.append(grid[t][f(x2, y2)] - grid[t][f(x1 - 1, y2)] - grid[t][f(x2, y1 - 1)] + grid[t][f(x1 - 1, y1 - 1)])

    print('\n'.join(map(str, outs)))