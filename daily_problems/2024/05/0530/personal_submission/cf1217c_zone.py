"""
question:   https://codeforces.com/contest/1217/problem/C
submission: https://codeforces.com/contest/1217/submission/263229843
"""
def solve():
    s = input() 
    lst = -1 
    n   = len(s)
    ans = 0
    for i in range(n):
        if s[i] == '1':
            j   = i
            cur = 0
            while j < n and (cur << 1) + (s[j] == '1') <= j - lst:
                cur = (cur << 1) + (s[j] == '1')
                ans += 1 
                j   += 1 
            lst = i 
    print(ans)    
    

for _ in range(int(input())):
    solve()
