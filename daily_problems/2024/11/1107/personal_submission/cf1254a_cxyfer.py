t = int(input())
for _ in range(t):
    r, c, k = map(int, input().split())
    grid = [list(input()) for _ in range(r)]

    s = 0
    for i, row in enumerate(grid):
        for j, val in enumerate(row):
            if val == "R":
                s += 1
    q, rem = divmod(s, k)
    # print(q, rem)
    idx, cur = 0, 0
    ans = [[0] * c for _ in range(r)]
    for i in range(r):
        for j in range(c) if i & 1 else range(c - 1, -1, -1):
            ans[i][j] = idx
            if grid[i][j] == "R":
                cur += 1
                if idx + 1 < k and cur == (q + 1 if idx < rem else q):
                    idx += 1
                    cur = 0
    for i, row in enumerate(ans):
        for j, val in enumerate(row):
            if 0 <= val <= 9:
                print(ans[i][j], end = "")
            elif 10 <= val < 36:
                print(chr(ord('A') + (val - 10)), end = "")
            elif 36 <= val < 62:
                print(chr(ord('a') + (val - 36)), end = "")
        print()
