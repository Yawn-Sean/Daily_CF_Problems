# Submission link: https://codeforces.com/contest/253/submission/321851781
def main():
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')
    input = lambda: fin.readline().strip()
    print = lambda x: fout.write(str(x))

    n, m, k = MII()
    grid = [[ord(c) - ord('a') for c in I()] for _ in range(n)]

    ans = 0

    for i in range(n):
        cnt = [0] * m
        for j in range(i, n):
            for a in range(m):
                if grid[j][a] == 0:
                    cnt[a] += 1
            
            if j > i:
                l = 0
                cur = 0
                
                tmp = [0] * 26
                
                for r in range(m):
                    cur += cnt[r]
                    
                    while cur > k:
                        if grid[i][l] == grid[j][l]:
                            tmp[grid[i][l]] -= 1
                        cur -= cnt[l]
                        l += 1
                    
                    if grid[i][r] == grid[j][r]:
                        if r > l:
                            ans += tmp[grid[i][r]]
                        tmp[grid[i][r]] += 1

    print(ans)