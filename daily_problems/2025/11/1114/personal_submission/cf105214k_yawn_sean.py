# Submission link: https://codeforces.com/gym/105214/submission/348741199
def main(): 
    d = {}
    
    d[1] = ['.']
    
    d[2] = ['#.',
            '#.']
    
    d[3] = ['#.#',
            '#.#',
            '...']
    
    d[4] = ['#.##',
            '#...',
            '...#',
            '##.#']
    
    d[5] = ['##.##',
            '.....',
            '##.##',
            '.....',
            '##.##']
    
    d[6] = ['##.#.#',
            '...#.#',
            '##....',
            '....##',
            '#.#...',
            '#.#.##']
    
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        
        v = (n - 1) % 6 + 1
        
        ans = [['.'] * n for _ in range(n)]
        
        for i in range(n - v, n):
            for j in range(n - v, n):
                ans[i][j] = d[v][i - (n - v)][j - (n - v)]
        
        if n % 2:
            for i in range(0, n - v, 3):
                for j in range(0, n, 2):
                    ans[i][j] = '#'
                    ans[i + 1][j] = '#'
        
        else:
            for i in range(0, n - v, 2):
                ans[i][0] = '#'
                ans[i][1] = '#'
            
            for i in range(0, n - v, 3):
                for j in range(3, n, 2):
                    ans[i][j] = '#'
                    ans[i + 1][j] = '#'
        
        if v % 2:
            for i in range(n - v, n, 2):
                for j in range(0, n - v, 3):
                    ans[i][j] = '#'
                    ans[i][j + 1] = '#'
        else:
            for j in range(0, n - v, 2):
                ans[n - v][j] = '#'
                ans[n - v + 1][j] = '#'
            
            for i in range(n - v + 3, n, 2):
                for j in range(0, n - v, 3):
                    ans[i][j] = '#'
                    ans[i][j + 1] = '#'
        
        outs.append('\n'.join(''.join(x) for x in ans))
    
    print('\n'.join(outs))