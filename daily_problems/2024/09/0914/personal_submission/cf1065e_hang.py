#题解： https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/09/0914/solution/cf1065e.md
def main():
    n,m,A = map(int,input().split())
    b = list(map(int,input().split()))
    mod = 998244353
    ans = 1
    
    cur = 0
    for x in b:
        v = pow(A, x - cur, mod)
        ans *= v * (v + 1) // 2 % mod
        ans %= mod
        cur = x
    ans *= pow(A, n - cur * 2, mod) 
    ans %= mod
    print(ans)
main()