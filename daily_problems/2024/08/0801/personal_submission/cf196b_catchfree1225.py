import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

# def expand_matrix(mat):
#     new_mat = []
#     for _ in range(3):
#         for row in mat:
#             new_mat.append(row * 3)
#     return new_mat

def solve():
    sx = sy = -1
    for i in range(n):
        for j in range(m):
            if a[i][j] == 'S':
                sx, sy = i, j
                break
    
    def ent(x, y):
        return x * m + y
    
    dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    vis = [[0] * m for _ in range(n)]
    vis[sx][sy] = ent(sx, sy)
    st = [(sx, sy)]
    
    while st: # infinite_path: loop(用dfs)
        x, y = st.pop()
        for dx, dy in dirs:
            nx, ny = x + dx, y + dy
            px, py = nx % n, ny % m
            if a[px][py] == '#':
                continue
            if vis[px][py]:
                if vis[px][py] != ent(nx, ny):
                    print('Yes')
                    return
            else:
                vis[px][py] = ent(nx, ny)
                st.append((nx, ny))               
    print('No')
               
for _ in range(1):
    n, m = MII()
    a = [input() for _ in range(n)]
    solve()