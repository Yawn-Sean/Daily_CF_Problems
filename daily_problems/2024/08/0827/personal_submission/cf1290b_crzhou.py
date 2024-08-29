s = input().strip()
n = len(s)
a = [[0] * 26 for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(26):
        a[i][j] = a[i-1][j]
    a[i][ord(s[i-1]) - ord('a')] += 1

t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    if s[l-1] != s[r-1] or l == r:
        print("Yes")
    else:
        cnt = 0
        for i in range(26):
            if a[r][i] - a[l-1][i] > 0:
                cnt += 1
        if cnt > 2:
            print("Yes")
        else:
            print("No")
