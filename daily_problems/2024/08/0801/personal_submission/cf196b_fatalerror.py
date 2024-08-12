import sys
input = lambda: sys.stdin.readline().rstrip()

dir4 = [(1, 0), (0, 1), (-1, 0), (0, -1)]
unvis = -1<<16
m, n = map(int, input().split())
grid = [input() for _ in range(m)]
sr, sc = next((r, c) for r, row in enumerate(grid) for c, ch in enumerate(row) if ch == 'S')
rowvis = [[unvis] * n for _ in range(m)]
colvis = [[unvis] * n for _ in range(m)]
rowvis[sr][sc] = sr
colvis[sr][sc] = sc

def dfs():
    stk = [(sr, sc)]
    while stk:
        r, c = stk.pop()
        for dr, dc in dir4:
            nr, nc = r+dr, c+dc
            br, bc = nr%m, nc%n
            if rowvis[br][bc] != unvis and (rowvis[br][bc] != nr or colvis[br][bc] != nc):
                return True
            if grid[br][bc] == '#' or rowvis[br][bc] != unvis:
                continue
            rowvis[br][bc] = nr
            colvis[br][bc] = nc
            stk.append((nr, nc))
    return False

print('Yes' if dfs() else 'No')