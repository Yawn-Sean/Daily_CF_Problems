# Submission link: https://codeforces.com/gym/105876/submission/362261812
def main(): 
    n = II()
    if n % 4 == 3: print(-1)
    else:
        ans = list(range(1, n + 1))
        
        for i in range(3, n, 4):
            ans[i - 1], ans[i] = ans[i], ans[i - 1]
        
        print(*ans)