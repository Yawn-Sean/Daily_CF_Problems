n, m, k, q = MII()
inf = 2 * 10 ** 9
grid = [[inf] * (m + 1) for _ in range(n + 1)]

for _ in range(q):
    x, y, t = MII()
    grid[x][y] = t

pref = [[0] * (m + 1) for _ in range(n + 1)]

def is_broken(n, m, k, mid):
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            pref[i][j] = 1 if grid[i][j] <= mid else 0

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]

    for i in range(k, n + 1):
        for j in range(k, m + 1):
            total = (pref[i][j] 
                     - pref[i - k][j] 
                     - pref[i][j - k] 
                     + pref[i - k][j - k])
            if total == k * k:
                return True
    return False

left, right, result = 0, inf, -1
while left <= right:
    mid = (left + right) // 2
    if is_broken(n, m, k, mid):
        result = mid
        right = mid - 1
    else:
        left = mid + 1

print(result if result < inf else -1)
