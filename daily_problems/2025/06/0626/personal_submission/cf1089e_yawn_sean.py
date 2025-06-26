# Submission link: https://codeforces.com/contest/1089/submission/326065238
def main():
    n = II()
    cnt = [0] * 8
    cnt[0] = 1
    cnt[7] = 2
    
    n -= 2
    
    for i in range(8):
        x = fmin(8 - cnt[i], n)
        n -= x
        cnt[i] += x
    
    cur = 1
    ans = []
    
    for i in range(7):
        if cnt[i]:
            tmp = [cur] + [j for j in range(1, 9) if j != cur]
            if cnt[i] == 8:
                tmp[-1], tmp[-2] = tmp[-2], tmp[-1]
            tmp = tmp[:cnt[i]]
            
            for x in tmp:
                ans.append(chr(ord('a') + i) + str(x))
            cur = tmp[-1]
    
    tmp = [cur] + [j for j in range(1, 9) if j != cur]
    tmp[-1], tmp[cnt[7] - 1] = tmp[cnt[7] - 1], tmp[-1]
    tmp = tmp[:cnt[7]]
    
    for x in tmp:
        ans.append('h' + str(x))
    
    print(' '.join(ans))