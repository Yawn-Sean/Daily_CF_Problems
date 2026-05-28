import sys
from array import array

input = lambda: sys.stdin.readline().rstrip()

B = 32
vis = [[array('b', [0] * 125) for _ in range(B * 2)] for _ in range(B * 2)]
dx = (-1, 1, 0, 0,)
dy = (0, 0, -1, 1,)
str_dir = (
    "MOVE UP",
    "MOVE DOWN",
    "MOVE LEFT",
    "MOVE RIGHT",
)
p = [4, 4, 4]


def dfs(x: int, y: int) -> bool:
    for d in range(4):
        if d == p[-1] ^ 1:
            continue
        nx, ny = x + dx[d], y + dy[d]
        s = (p[-2] * 5 + p[-1]) * 5 + d
        if vis[nx][ny][s] == 0:
            p.append(d)
            print(str_dir[d], flush=True)
            match input():
                case "FAIL":
                    p.pop()
                case "OK":
                    vis[nx][ny][s] = 1
                    if dfs(nx, ny):
                        return True
                    else:
                        p.pop()
                        print("BACK", flush=True)
                        assert input() == "OK"
                case "EXIT":
                    return True
                case _:
                    assert False, "Unreachable"
    return False


n, m = map(int, input().split())
sys.setrecursionlimit(300000)
assert dfs(B, B), "Algo doesn't find an answer"
