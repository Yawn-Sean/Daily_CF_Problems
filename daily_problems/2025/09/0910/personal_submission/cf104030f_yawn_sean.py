# Submission link: https://codeforces.com/gym/104030/submission/337742313
def main():
    n = II()
    grid = [LI() for _ in range(n)]
    grid_len = [[len(c) for c in x] for x in grid]
    
    if n >= 3:
        c01 = grid_len[0][1]
        c02 = grid_len[0][2]
        c12 = grid_len[1][2]
        
        c012 = (c01 + c02 + c12) // 2
        
        cnt = [0] * n
        cnt[0] = c012 - c12
        cnt[1] = c012 - c02
        cnt[2] = c012 - c01
        
        for i in range(3, n):
            cnt[i] = grid_len[0][i] - cnt[0]
        
        for i in range(n):
            if cnt[i] <= 0:
                exit(print('NONE'))
        
        ans = [''] * n
        
        for i in range(n):
            ans[i] = grid[i][0 if i else 1][:cnt[i]]
        
        for i in range(n):
            for j in range(n):
                if i != j and ans[i] + ans[j] != grid[i][j]:
                    exit(print('NONE'))
        
        print('UNIQUE')
        print('\n'.join(ans))
    
    else:
        s01 = grid[0][1]
        s10 = grid[1][0]
        
        if len(s01) != len(s10):
            exit(print('NONE'))
        
        k = len(s01)
        
        tmp = s10 + '#' + s01 * 2
        kmp = prep(tmp)
        
        idxs = []
        
        for i in range(2 * k + 1, 3 * k):
            if kmp[i] == k:
                idxs.append(i - 2 * k)
        
        if len(idxs) > 1: print('MANY')
        elif len(idxs) == 0: print('NONE')
        else:
            idx = idxs[0]
            print('UNIQUE')
            print(s01[:idx])
            print(s01[idx:])