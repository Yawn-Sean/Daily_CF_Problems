#题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2025/01/0121/solution/cf553b.md
def main():
    n, k = map(int, input().split())

    f = [1, 1]
    while len(f) < 53:
        f.append(f[-1] + f[-2])

    k -= 1
    ans = []
    while len(ans) < n:
        l = len(ans)
        if k >= f[n - l - 1]:
            ans.append(l + 2)
            ans.append(l + 1)

            k -= f[n - l - 1]
        else:
            ans.append(l + 1)

    print(*ans)
main()