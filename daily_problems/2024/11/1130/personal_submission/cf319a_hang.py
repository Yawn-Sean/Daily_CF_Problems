def main():
    s = [int(x) for x in input()]
    mod = 10 ** 9 + 7
    n = len(s)
    ans = 0
    cur = 1
    for i in range(n - 1, -1, -1):
        ans = (ans + ans) % mod
        if s[i]:
            ans = (ans + cur * cur) % mod
        cur = (cur + cur) % mod
    print(ans)


main()