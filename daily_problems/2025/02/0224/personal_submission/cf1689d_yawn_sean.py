# Submission link: https://codeforces.com/contest/1689/submission/307472344
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m = MII()
        grid = [I() for _ in range(n)]
        
        mx1, mi1 = -5000, 5000
        mx2, mi2 = -5000, 5000
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 'B':
                    mx1 = fmax(mx1, i + j)
                    mi1 = fmin(mi1, i + j)
                    mx2 = fmax(mx2, i - j)
                    mi2 = fmin(mi2, i - j)
        
        ans = 5000
        x, y = -1, -1
        
        for i in range(n):
            for j in range(m):
                res = max(mx1 - i - j, i + j - mi1, mx2 - i + j, i - j - mi2)
                if res < ans:
                    ans = res
                    x, y = i, j
        
        outs.append(f'{x + 1} {y + 1}')

    print('\n'.join(outs))