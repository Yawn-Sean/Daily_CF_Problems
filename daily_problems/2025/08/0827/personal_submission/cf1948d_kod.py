t = ix()
for _ in range(t):
    s = input()
    n = len(s)
    lcp = [0] * (n + 1)
    ans = 0
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            if s[j] == s[i] or s[j] == '?' or s[i] == "?":
                lcp[j] = lcp[j + 1] + 1
            else:
                lcp[j] = 0
            if lcp[j] == j - i:
                ans = max(ans, j - i)
    print(ans * 2)
