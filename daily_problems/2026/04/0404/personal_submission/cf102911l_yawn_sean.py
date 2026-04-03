# Submission link: https://codeforces.com/gym/102911/submission/369457611
def main(): 
    n = II()
    x, y = GMI()
    
    k = 1 << n
    
    ans = [['.'] * k for _ in range(k)]
    ans[x][y] = '#'
    
    def f(lx, rx, ly, ry, x, y):
        if lx + 2 == rx:
            ch = chr(ord('B') + (lx // 2 + ly // 2) % 2)
            for i in range(lx, rx):
                for j in range(ly, ry):
                    if ans[i][j] == '.':
                        ans[i][j] = ch
            return
        
        mx = (lx + rx) // 2
        my = (ly + ry) // 2
        
        if x < mx:
            if y < my:
                ans[mx - 1][my] = 'A'
                ans[mx][my - 1] = 'A'
                ans[mx][my] = 'A'
                f(lx, mx, ly, my, x, y)
                f(lx, mx, my, ry, mx - 1, my)
                f(mx, rx, ly, my, mx, my - 1)
                f(mx, rx, my, ry, mx, my)
            else:
                ans[mx - 1][my - 1] = 'A'
                ans[mx][my - 1] = 'A'
                ans[mx][my] = 'A'
                f(lx, mx, ly, my, mx - 1, my - 1)
                f(lx, mx, my, ry, x, y)
                f(mx, rx, ly, my, mx, my - 1)
                f(mx, rx, my, ry, mx, my)
        else:
            if y < my:
                ans[mx - 1][my - 1] = 'A'
                ans[mx - 1][my] = 'A'
                ans[mx][my] = 'A'
                f(lx, mx, ly, my, mx - 1, my - 1)
                f(lx, mx, my, ry, mx - 1, my)
                f(mx, rx, ly, my, x, y)
                f(mx, rx, my, ry, mx, my)
            else:
                ans[mx - 1][my - 1] = 'A'
                ans[mx - 1][my] = 'A'
                ans[mx][my - 1] = 'A'
                f(lx, mx, ly, my, mx - 1, my - 1)
                f(lx, mx, my, ry, mx - 1, my)
                f(mx, rx, ly, my, mx, my - 1)
                f(mx, rx, my, ry, x, y)
    
    f(0, k, 0, k, x, y)
    
    print('YES')
    print('\n'.join(''.join(x) for x in ans))