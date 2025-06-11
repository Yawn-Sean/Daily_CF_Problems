# Submission link: https://codeforces.com/contest/115/submission/300455858
def main():
    n, m = MII()
    grid = [I() for _ in range(n)]

    vis0 = [-1] * n
    vis1 = [-1] * m

    for i in range(n):
        for j in range(m):
            if grid[i][j] != '.':
                v0 = (j & 1) ^ (grid[i][j] in '12')
                v1 = (i & 1) ^ (grid[i][j] in '14')
                
                if vis0[i] == -1: vis0[i] = v0
                elif vis0[i] != v0: exit(print(0))

                if vis1[j] == -1: vis1[j] = v1
                elif vis1[j] != v1: exit(print(0))

    mod = 10 ** 6 + 3
    ans = 1
    for x in vis0:
        if x == -1:
            ans = ans * 2 % mod

    for x in vis1:
        if x == -1:
            ans = ans * 2 % mod

    print(ans)