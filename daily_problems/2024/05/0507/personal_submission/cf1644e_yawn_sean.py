# Submission link: https://codeforces.com/contest/1644/submission/259817052
def main():
    n = II()
    s = I()
    
    k = len(s)
    
    pos = -1
    for i in range(k):
        if s[i] != s[0]:
            pos = i
            break
    
    if pos == -1:
        outs.append(n)
    else:
        ans = pos + (n - pos) * n
        
        dx, dy = 1, 1
        for i in range(pos, k):
            if s[i] == 'R': dy += 1
            else: dx += 1
        
        ans -= dx * dy - (k - pos + 1)
        outs.append(ans)