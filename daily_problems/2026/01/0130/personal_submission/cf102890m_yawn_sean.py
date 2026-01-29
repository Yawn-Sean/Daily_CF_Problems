# Submission link: https://codeforces.com/gym/102890/submission/360468897
def main(): 
    s = [int(c) - 1 for c in I()]
    cnt = LII()
    
    n = len(s)
    acc = [[0] * (n + 1) for _ in range(9)]
    next_pos = [[n] * (n + 1) for _ in range(9)]
    
    for i in range(n - 1, -1, -1):
        for j in range(9):
            next_pos[j][i] = next_pos[j][i + 1]
            acc[j][i] = acc[j][i + 1]
        next_pos[s[i]][i] = i
        acc[s[i]][i] += 1
    
    for i in range(n):
        cnt[s[i]] -= 1
    
    for i in range(9):
        cnt[i] = -cnt[i]
    
    ans = []
    total = sum(cnt)
    
    pt = 0
    for _ in range(total):
        for i in range(8, -1, -1):
            npt = next_pos[i][pt]
            flg = True
            
            for j in range(9):
                if acc[j][npt] < cnt[j]:
                    flg = False
            
            if flg and cnt[i]:
                ans.append(i + 1)
                cnt[i] -= 1
                pt = npt + 1
                break
    
    print(''.join(map(str, ans)))