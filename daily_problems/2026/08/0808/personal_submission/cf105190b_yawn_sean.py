# Submission link: https://codeforces.com/gym/105190/submission/386028547
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
    
    n, x, y, z = MII()
    s = [ord(c) for c in I()]
    
    v1 = prep(s)
    
    s.reverse()
    v2 = prep(s)
    v2.reverse()
    
    ans = 0
    cur = -inf
    
    for i in range(n - 2, -1, -1):
        cur += z
        if v2[i + 1] > 0:
            cur = fmax(cur, y * v2[i + 1])
        if v1[i] > 0:
            ans = fmax(ans, cur + x * v1[i])
    
    print(ans)