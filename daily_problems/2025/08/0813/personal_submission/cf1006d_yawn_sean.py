# Submission link: https://codeforces.com/contest/1006/submission/333645213
def main():
    n = II()
    s1 = [ord(c) for c in I()]
    s2 = [ord(c) for c in I()]
    
    ans = 0
    
    for i in range(n // 2):
        a, b, c, d = s1[i], s1[n - 1 - i], s2[i], s2[n - 1 - i]
        if (a == b and c == d) or (a == c and b == d) or (a == d and b == c):
            ans += 0
        elif a == c or a == d or b == c or b == d or c == d:
            ans += 1
        else:
            ans += 2
    
    if n % 2: ans += s1[n // 2] != s2[n // 2]
    
    print(ans)