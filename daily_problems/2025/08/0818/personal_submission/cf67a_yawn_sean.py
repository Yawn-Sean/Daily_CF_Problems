# Submission link: https://codeforces.com/contest/67/submission/334231467
def main():
    n = II()
    s = I()
    
    ans = [1] * n
    
    for i in range(n - 1):
        if s[i] == 'R': ans[i + 1] = ans[i] + 1
        elif s[i] == '=': ans[i + 1] = ans[i]
    
    for i in range(n - 2, -1, -1):
        if s[i] == 'L': ans[i] = fmax(ans[i], ans[i + 1] + 1)
        elif s[i] == '=': ans[i] = ans[i + 1]
    
    print(*ans)