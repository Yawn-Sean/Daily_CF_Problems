# Submission link: https://codeforces.com/gym/102791/submission/338206427
def main():
    n = II()
    s = [ord(c) - ord('a') for c in I()]
    
    inf = 10 ** 6
    
    saved_ans = [[-inf] * 26 for _ in range(26)]
    saved_pos = [[0] * 26 for _ in range(26)]
    
    dp = [-inf] * (n + 1)
    pre = [-1] * (n + 1)
    
    dp[0] = 0
    
    for i in range(1, n):
        if dp[i - 1] != -inf:
            if i == 1:
                for j in range(26):
                    saved_ans[j][s[i - 1]] = 0
            
            elif dp[i - 1] > saved_ans[s[i - 2]][s[i - 1]]:
                saved_ans[s[i - 2]][s[i - 1]] = dp[i - 1]
                saved_pos[s[i - 2]][s[i - 1]] = i - 1
        
        for j in range(26):
            if saved_ans[j][s[i]] != -inf and saved_ans[j][s[i]] + 1 > dp[i + 1]:
                dp[i + 1] = saved_ans[j][s[i]] + 1
                pre[i + 1] = saved_pos[j][s[i]]
    
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