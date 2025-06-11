"""
question: https://codeforces.com/contest/1083/problem/B
submission: https://codeforces.com/contest/1083/submission/263208980
"""

def solve():
    n, k = map(int, input().split())
    l, r = input(), input()
    ans = 0 
    cur = 1  
    for i in range(n):
        if cur < k: cur = cur * 2 - (l[i] == 'b') - (r[i] == 'a')
        cur = min(cur, k)
        ans += cur
    print(ans)

solve()
