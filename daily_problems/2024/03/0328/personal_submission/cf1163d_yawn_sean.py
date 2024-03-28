def main():
    def prep(p):
        pi = [0] * len(p)
        j = 0
        for i in range(1, len(p)):
            while j != 0 and p[j] != p[i]:
                j = pi[j - 1]
            if p[j] == p[i]:
                j += 1
            pi[i] = j
        return pi
    
    c = I()
    
    s = I()
    t = I()
    
    def get_transition(string):
        n = len(string)
        kmp = prep(string)
        transition = [[-1] * 26 for _ in range(n + 1)]
        
        for i in range(n + 1):
            for c in range(26):
                if i < n and c == ord(string[i]) - ord('a'):
                    transition[i][c] = i
                else:
                    pt = i - 1
                    while pt > -1:
                        pt = kmp[pt]
                        if c == ord(string[pt]) - ord('a'):
                            transition[i][c] = pt
                            break
                        pt -= 1
        
        return transition
    
    a, b = len(s), len(t)
    
    transition_s = get_transition(s)
    transition_t = get_transition(t)
    
    dp = [[-inf] * (b + 1) for _ in range(a + 1)]
    dp[0][0] = 0
    for char in c:
        ndp = [[-inf] * (b + 1) for _ in range(a + 1)]
        tmp = ord(char) - ord('a')
        for i in range(a + 1):
            for j in range(b + 1):
                if dp[i][j] != -inf:
                    for char in (range(26) if tmp < 0 else [tmp]):
                        ni, nj = transition_s[i][char] + 1, transition_t[j][char] + 1
                        ndp[ni][nj] = max(ndp[ni][nj], dp[i][j])
        
        for i in range(a + 1):
            ndp[i][b] -= 1
        
        for i in range(b + 1):
            ndp[a][i] += 1
        
        dp = ndp
    
    print(max(max(x) for x in dp))
