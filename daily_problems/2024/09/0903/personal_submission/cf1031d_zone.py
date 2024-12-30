# submission url: https://codeforces.com/contest/1031/submission/279405631

def main():
    # 贪心: 前k个字符全为'a'
    # 从初始位置对于不是'a'的字符经过k次操作变成'a'后能达到的最远位置，并从这些位置出发，取路径最小值
    n, k = map(int, input().split()) 
    
    a = [input() for _ in range(n)]
    
    fins = [(0, 0)]
    
    cnt = [[n ** 2] * n for _ in range(n)]
    
    cnt[0][0] = a[0][0] != 'a'
    for i in range(n):
        for j in range(n): 
            if i + 1 < n: 
                cnt[i + 1][j] = min(cnt[i + 1][j], (a[i + 1][j] != 'a') + cnt[i][j])
            if j + 1 < n:
                cnt[i][j + 1] = min(cnt[i][j + 1], (a[i][j + 1] != 'a') + cnt[i][j])
    
    for i in range(n):
        for j in range(n):
            if cnt[i][j] == k:
                if i + 1 < n and cnt[i + 1][j] == k + 1: 
                    if i + j + 1 > sum(fins[-1]):
                        fins = [(i + 1, j)]
                    elif i + j + 1 == sum(fins[-1]): 
                        fins.append((i + 1, j))
                if j + 1 < n and cnt[i][j + 1] == k + 1: 
                    if i + j + 1 > sum(fins[-1]):
                        fins = [(i, j + 1)]
                    elif i + j + 1 == sum(fins[-1]): 
                        fins.append((i, j + 1))
    if cnt[-1][-1] <= k: 
        print('a' * (2 * n - 1))
        exit()
    ans = []
    while len(fins): 
        nfins = set() 
        fin = min(a[i][j] for i, j in fins)
        for i, j in fins: 
            if a[i][j] == fin: 
                if i + 1 < n: nfins.add((i + 1, j))        
                if j + 1 < n: nfins.add((i, j + 1))
        ans.append(fin)
        fins = nfins
    
    print('a' * (2 * n - 1 - len(ans)) + ''.join(ans))
