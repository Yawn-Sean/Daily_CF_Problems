# Submission link: https://codeforces.com/gym/102791/submission/338219044
def main():
    n = II()
    s = [ord(c) - ord('a') for c in I()]
    
    inf = 10 ** 6
    
    saved_ans = [-inf] * 26
    saved_pos = [-1] * 26
    
    dp = [-inf] * (n + 1)
    pre = [-1] * (n + 1)
    
    dp[0] = 0
    
    for i in range(1, n):
        if dp[i - 1] > saved_ans[s[i - 1]]:
            saved_ans[s[i - 1]] = dp[i - 1]
            saved_pos[s[i - 1]] = i - 1
        
        if saved_ans[s[i]] >= 0:
            dp[i + 1] = saved_ans[s[i]] + 1
            pre[i + 1] = saved_pos[s[i]]
    
    if dp[n] < 0: print(-1)
    else:
        print(dp[n])
        
        tmp = []
        cur = n
        
        while cur:
            tmp.append(cur - pre[cur])
            cur = pre[cur]
        
        tmp.reverse()
        
        print(' '.join(map(str, tmp)))