import sys
from array import array
from typing import List, Optional

input = lambda: sys.stdin.readline().rstrip()
de = "--LOCAL_LEETCODE" in sys.argv

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
        if de:
            _nx, _ny = _sx + nx - B, _sy + ny - B
            _x = _nx - dx[d]
            _y = _ny - dy[d]
            print(f"* FUCK {_nx} {_ny} {s}", file=sys.stderr)
        if vis[nx][ny][s] == 0:
            p.append(d)
            if not de:
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
            else:
                _nx, _ny = _sx + nx - B, _sy + ny - B
                if _nx < 0 or _ny < 0 or _nx >= n or _ny >= m:
                    p.pop()  # FAIL
                else:
                    _x = _nx - dx[d]
                    _y = _ny - dy[d]
                    _c: Optional[str] = None
                    if d <= 1:
                        _c = _cs[_x - int(d == 0)][_y]
                    else:
                        _c = _rs[_x][_y - int(d == 2)]
                    assert _c is not None
                    _str_p = ''.join(_p[-3:])
                    print(
                        f"{_x=} {_y=} {d=} '{_str_p}' {_c=} {str_dir[d]}",
                        file=sys.stderr
                    )
                    if _c in _p[-3:]:
                        print(f"\tFailed due to duplicate col", file=sys.stderr)
                        p.pop()  # FAIL
                    else:
                        if _nx == _tx and _ny == _ty:
                            return True
                        _p.append(_c)
                        vis[nx][ny][s] = 1
                        if dfs(nx, ny):
                            return True
                        else:
                            print("MOVE BACK", file=sys.stderr)
                            _p.pop()
                            p.pop()
        else:
            if de:
                _nx, _ny = _sx + nx - B, _sy + ny - B
                _x = _nx - dx[d]
                _y = _ny - dy[d]
                _str_p = ''.join(_p[-3:])
                print(
                    f"\t{_x=} {_y=} {d=} '{_str_p}' Failed due to duplicate state",
                    file=sys.stderr
                )
    return False


n, m = map(int, input().split())
sys.setrecursionlimit(300000)
if de:
    _rs = list(input() for _ in range(n))
    _cs = list(input() for _ in range(n - 1))
    _sx, _sy = map(int, input().split())
    _tx, _ty = map(int, input().split())
    _p = ["*", "*", "*"]
    sys.setrecursionlimit(1000000)
assert dfs(B, B), "Algo doesn't find an answer"


"""
虽然题目很复杂, 但是不要被他唬住
考虑到达某一个格子的最后三步的状态:
4*3*3 (因为不可能走往返, 所以后两部各 *3)
4*3*3*30*30 = 32400
于是 dfs+记忆化 即可
对于刚开始的几步, 没有最后三个状态怎么办?
- 因为少状态肯定比多状态优, 不妨暴力枚举全部的多状态然后记忆
"""
