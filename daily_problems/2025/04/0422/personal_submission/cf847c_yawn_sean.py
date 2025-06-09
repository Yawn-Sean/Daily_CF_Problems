# Submission link: https://codeforces.com/contest/847/submission/316619783
def main():
    n, k = MII()
    if n * (n - 1) // 2 < k: print('Impossible')
    else:
        ans = []
        cur = 0
        
        for i in range(n):
            if k - (n - 1 - i) >= 0:
                ans.append('(')
                cur += 1
                k -= n - 1 - i
            else:
                ans.append('()')
        
        for _ in range(cur):
            ans.append(')')
        
        print(''.join(ans))