# Submission link: https://codeforces.com/gym/106185/submission/348630279
def main(): 
    outs = []
    
    while True:
        n = II()
        if n == 0:
            break
        nums = LII()
        
        pos = [[] for _ in range(n + 1)]
        
        for i in range(2 * n):
            pos[nums[i]].append(i)
        
        to_pos = [-1] * (2 * n)
        
        for i in range(n + 1):
            k = len(pos[i]) // 2
            for j in range(k):
                to_pos[pos[i][j]] = pos[i][j + k]
        
        fen = FenwickTree(2 * n)
        
        ans = n * (n - 1) // 2
        
        for i in range(2 * n):
            if to_pos[i] >= 0:
                ans -= fen.rsum(i, to_pos[i])
                fen.add(to_pos[i], 1)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))