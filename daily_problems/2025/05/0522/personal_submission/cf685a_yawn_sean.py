# Submission link: https://codeforces.com/contest/685/submission/320703692
def main():
    def f(x):
        ans = [0] * 128
        
        tmp = x - 1
        length = 0
        
        while tmp:
            tmp //= 7
            length += 1
        
        length = fmax(length, 1)
        
        def dfs(idx, val, msk):
            if idx == length:
                if val < x:
                    ans[msk] += 1
                return
            
            for i in range(7):
                if msk >> i & 1: continue
                dfs(idx + 1, val * 7 + i, msk | (1 << i))
        
        dfs(0, 0, 0)
        return ans

    n, m = MII()

    cnt1 = f(n)
    cnt2 = f(m)

    ans = 0

    for i in range(128):
        for j in range(128):
            if i & j == 0:
                ans += cnt1[i] * cnt2[j]

    print(ans)