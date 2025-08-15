# Submission link: https://codeforces.com/contest/518/submission/334071759
def main():
    n, m, k = MII()
    cur = LGMI()
    pos = [0] * n
    
    for i in range(n):
        pos[cur[i]] = i
    
    ans = 0
    for i in GMI():
        ans += pos[i] // k + 1
        
        if pos[i]:
            p = pos[i]
            pos[cur[p]], pos[cur[p - 1]] = pos[cur[p - 1]], pos[cur[p]]
            cur[p], cur[p - 1] = cur[p - 1], cur[p]
    
    print(ans)