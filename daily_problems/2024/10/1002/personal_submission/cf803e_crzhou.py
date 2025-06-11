def dfs(x, y):
    if x == n and abs(y) == k:
        return True
    if x == n or abs(y) >= k:
        return False
    if dp[x][y + offset]:
        return False
    dp[x][y + offset] = 1

    if s[x] == 'W':
        return dfs(x + 1, y + 1)
    if s[x] == 'D':
        return dfs(x + 1, y)
    if s[x] == 'L':
        return dfs(x + 1, y - 1)

    if dfs(x + 1, y + 1):
        s[x] = 'W'
        return True
    if dfs(x + 1, y):
        s[x] = 'D'
        return True
    if dfs(x + 1, y - 1):
        s[x] = 'L'
        return True
    
n, k = MII()
s = list(I())
offset = 1000
dp = [[0] * (2 * offset) for _ in range(n + 1)]

if dfs(0, 0):
    print(''.join(s))
else:
    print("NO")
