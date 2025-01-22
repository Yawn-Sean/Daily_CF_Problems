# Submission link: https://codeforces.com/contest/1254/submission/290312098
def main():
    t = II()
    outs = []

    chars = digits + ascii_letters

    for _ in range(t):
        n, m, k = MII()
        grid = [[1 if c == 'R' else 0 for c in I()] for _ in range(n)]
        
        total = sum(sum(x) for x in grid)
        a, b = divmod(total, k)
        
        cnt = Counter()
        cnt[a + 1] = b
        cnt[a] = k - b
        
        ans = [[-1] * m for _ in range(n)]
        
        x, y = 0, 0
        dy = 1
        
        def op():
            nonlocal x, y, dy
            if 0 <= y + dy < m:
                y += dy
            else:
                x += 1
                dy = -dy

        for i in range(k):
            c = grid[x][y]
            ans[x][y] = i
            op()
            while cnt[c] == 0:
                c += grid[x][y]
                ans[x][y] = i
                op()
            cnt[c] -= 1
        
        for i in range(n):
            for j in range(m):
                if ans[i][j] == - 1:
                    ans[i][j] = k - 1
        
            outs.append(''.join(chars[x] for x in ans[i]))

    print('\n'.join(outs))