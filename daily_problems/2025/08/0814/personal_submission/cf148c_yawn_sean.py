# Submission link: https://codeforces.com/contest/148/submission/333804304
def main():
    n, a, b = MII()
    
    if a and a == n - 1: print(-1)
    elif n == 1: print(1)
    else:
        ans = [1, 2]
        if b == 0: ans = [2, 1]
        else: b -= 1
        
        cur = 3
        for i in range(2, n):
            if b:
                b -= 1
                ans.append(cur + 1)
                cur = cur * 2 + 1
            elif a:
                a -= 1
                ans.append(fmax(ans[0], ans[-1]) + 1)
            else:
                ans.append(1)
        
        print(*ans)