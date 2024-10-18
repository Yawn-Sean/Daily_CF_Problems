import bisect
# 题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/09/0919/solution/cf309a.md
def main():
    n,l,t = map(int,input().split())
    a = list(map(int,input().split()))
    t = t*2
    ans = 0
    k, d = divmod(t,l)
    ans = n * (n - 1) * k
    for i in range(n):
        a.append(a[i] + l)
    for i in range(n):
        ans += bisect.bisect_right(a, a[i] + d) - i - 1
    print(ans / 4) # c(2,1) * c(2,1)

main()