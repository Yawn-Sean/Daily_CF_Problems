n, m, k = MII()
grid = [LII() for _ in range(n)]\

def mi(pattern):
    total_changes = 0
    for row in grid:
        ma = sum(1 for j in range(m) if row[j] == pattern[j])
        changes= min(ma, m - ma)
        total_changes += changes
    return total_changes

ans = float('inf')

if m <= k:
    for mask in range(1 << m):
        pattern = [(mask >> j) & 1 for j in range(m)]
        changes = mi(pattern)
        ans = min(ans, changes)
else:
    for col in range(m):
        changes = 0
        for j in range(m):
            ma = sum(1 for i in range(n) if grid[i][j] == grid[i][col])
            changes += min(ma, n - ma)
        ans = min(ans, changes)

print(ans if ans <= k else -1)
