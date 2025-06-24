# Submission link: https://codeforces.com/contest/1098/submission/325941169
def main():
    d = {}
    d['A'] = 0
    d['G'] = 1
    d['C'] = 2
    d['T'] = 3

    n, m = MII()
    grid = [[d[c] for c in I()] for _ in range(n)]

    ans = n * m + 5
    flg = False
    chosen_i, chosen_j = -1, -1

    for i in range(4):
        for j in range(i):
            cur = [0] * 4
            cur[i] = 1
            cur[j] = 1
            
            res = 0
            for x in range(n):
                c1 = 0
                c2 = 0
                
                cols = [i for i in range(4) if cur[i] == x % 2]
                
                for y in range(m):
                    if cur[grid[x][y]] == x % 2:
                        if (cols[1] == grid[x][y]) ^ (y % 2): c1 += 1
                        else: c2 += 1
                
                res += m - fmax(c1, c2)
            
            if res < ans:
                ans = res
                flg = True
                chosen_i = i
                chosen_j = j

            res = 0
            for y in range(m):
                c1 = 0
                c2 = 0
                
                cols = [i for i in range(4) if cur[i] == y % 2]
                
                for x in range(n):
                    if cur[grid[x][y]] == y % 2:
                        if (cols[1] == grid[x][y]) ^ (x % 2): c1 += 1
                        else: c2 += 1
                
                res += n - fmax(c1, c2)

            if res < ans:
                ans = res
                flg = False
                chosen_i = i
                chosen_j = j

    cur = [0] * 4
    cur[chosen_i] = 1
    cur[chosen_j] = 1

    if flg:
        for x in range(n):
            c1 = 0
            c2 = 0
            
            cols = [i for i in range(4) if cur[i] == x % 2]
            
            for y in range(m):
                if cur[grid[x][y]] == x % 2:
                    if (cols[1] == grid[x][y]) ^ (y % 2): c1 += 1
                    else: c2 += 1
            
            if c1 > c2:
                for y in range(m):
                    grid[x][y] = cols[1 - y % 2]
            else:
                for y in range(m):
                    grid[x][y] = cols[y % 2]
    else:
        for y in range(m):
            c1 = 0
            c2 = 0
            
            cols = [i for i in range(4) if cur[i] == y % 2]
            
            for x in range(n):
                if cur[grid[x][y]] == y % 2:
                    if (cols[1] == grid[x][y]) ^ (x % 2): c1 += 1
                    else: c2 += 1
            
            if c1 > c2:
                for x in range(n):
                    grid[x][y] = cols[1 - x % 2]
            else:
                for x in range(n):
                    grid[x][y] = cols[x % 2]

    print('\n'.join(''.join('AGCT'[y] for y in x) for x in grid))