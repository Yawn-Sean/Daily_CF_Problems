# Submission link: https://codeforces.com/contest/1948/submission/335602406
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        s = [ord(c) - ord('a') + 1 if c != '?' else 0 for c in I()]
        n = len(s)
        lcp = [0] * (n + 1)
        
        ans = 0
        
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if s[j] == s[i] or s[j] == 0 or s[i] == 0:
                    lcp[j] = lcp[j + 1] + 1
                else:
                    lcp[j] = 0
                if lcp[j] >= j - i:
                    ans = fmax(ans, j - i)
        
        outs.append(ans * 2)
    
    print('\n'.join(map(str, outs)))