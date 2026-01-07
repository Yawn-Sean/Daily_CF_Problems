# Submission link: https://codeforces.com/gym/104294/submission/356579239
def main(): 
    n, q = MII()
    grid = [LII() for _ in range(n)]
    
    saved = [[n * n + 1] * (n * n + 1) for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if i + k >= n or j + k >= n:
                    break
                saved[k][grid[i][j]] = fmin(saved[k][grid[i][j]], grid[i + k][j + k])
    
    for i in range(n):
        for j in range(n * n - 1, -1, -1):
            saved[i][j] = fmin(saved[i][j], saved[i][j + 1])
    
    outs = []
    
    for _ in range(q):
        a, b = MII()
        
        for i in range(n - 1, -1, -1):
            if saved[i][a] <= b:
                outs.append((i + 1) ** 2)
                break
    
    print('\n'.join(map(str, outs)))