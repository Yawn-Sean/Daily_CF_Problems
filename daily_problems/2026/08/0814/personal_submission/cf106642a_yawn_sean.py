# Submission link: https://codeforces.com/gym/106642/submission/386847371
def main():
    n = II()
    strs = [[ord(c) - ord('a') for c in I()] for _ in range(n)]
    pattern = [ord(c) - ord('a') for c in I()]
    
    k = len(pattern)
    transition = [[0] * 26 for _ in range(k + 1)]
    
    for i in range(k + 1):
        for j in range(26):
            tmp = []
            for idx in range(i):
                tmp.append(pattern[idx])
            tmp.append(j)
            
            l = len(tmp)
            for cur_len in range(fmin(l, k), -1, -1):
                flg = True
                
                for idx in range(cur_len):
                    if pattern[idx] != tmp[l - cur_len + idx]:
                        flg = False
                
                if flg:
                    transition[i][j] = cur_len
                    break
    
    transition_string = [[None] * (k + 1) for _ in range(n)]
    
    for i in range(n):
        for j in range(k + 1):
            cur = j
            cnt = 0
            
            for c in strs[i]:
                cur = transition[cur][c]
                if cur == k: cnt += 1
            
            transition_string[i][j] = (cur, cnt)
    
    def f(x, y):
        return x * (k + 1) + y
    
    dp = [[-1] * (1 << n) for _ in range((k + 1) * (k + 1))]
    
    for i in range(k + 1): dp[f(i, i)][0] = 0
    
    for msk in range(1 << n):
        for i in range(k + 1):
            for j in range(k + 1):
                if dp[f(i, j)][msk] != -1:
                    for bit in range(n):
                        if msk >> bit & 1: continue
                        nmsk = msk | (1 << bit)
                        nj, ncnt = transition_string[bit][j]
                        dp[f(i, nj)][nmsk] = fmax(dp[f(i, nj)][nmsk], dp[f(i, j)][msk] + ncnt)
    
    ans = 0
    
    for i in range(n):
        l = len(strs[i])
        
        for j in range(l):
            cur, cnt = 0, 0
            
            for idx in range(j, l):
                cur = transition[cur][strs[i][idx]]
                if cur == k: cnt += 1
            
            msk = (1 << n) - 1 - (1 << i)
            for ncur in range(k + 1):
                if dp[f(cur, ncur)][msk] != -1:
                    ncnt = cnt + dp[f(cur, ncur)][msk]
                    
                    for idx in range(j):
                        ncur = transition[ncur][strs[i][idx]]
                        if ncur == k: ncnt += 1
                    
                    ans = fmax(ans, ncnt)
    
    print(ans)