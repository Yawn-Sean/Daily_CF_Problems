# Submission link: https://codeforces.com/gym/105613/submission/345830210
def main(): 
    n = II()
    k = II()
    
    if n * (n - 1) // 2 < k: exit(print(-1))
    
    for i in range(1, n + 1):
        if i * (i + 1) // 2 > k:
            ans = [3] * i
            k -= i * (i - 1) // 2
            for i in range(k):
                ans[i] = 6
            if k: ans.append(2)
            break
    
    for i in range(999997, 0, -6):
        if len(ans) < n: ans.append(i)
        if len(ans) < n: ans.append(i - 2)
    
    print(' '.join(map(str, ans)))