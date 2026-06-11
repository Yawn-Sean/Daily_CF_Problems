# Submission link: https://codeforces.com/gym/103102/submission/378142095
def main():
    n = II()
    nums = LII()
    
    ans = 0
    
    cnt = [[0] * 3 for _ in range(3)]
    cnt[0][0] = 1
    
    cur1 = 0
    cur2 = 0
    
    for x in nums:
        x %= 3
        cur1 = (cur1 + x) % 3
        cur2 = (cur2 + x * x) % 3
        
        for i in range(3):
            for j in range(3):
                v1 = (cur1 - i) % 3
                v2 = (cur2 - j) % 3
                
                if v1 * v1 % 3 == v2:
                    ans += cnt[i][j]
        
        cnt[cur1][cur2] += 1
    
    print(ans)