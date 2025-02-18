def main():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    l,r = 0, 2 * 10 ** 9
    dp = [1] * (n)
    while l < r:
        mid = (l + r) // 2
        for i in range(n):
            dp[i] = 1
        for i in range(n):
            for j in range(i):
                if abs(a[i] - a[j]) <= mid * (i - j):
                    dp[i] = max(dp[i], dp[j] + 1)
            
        if max(dp) + k >= n:
            r = mid
        else:
            l = mid + 1
    print(l)
main()