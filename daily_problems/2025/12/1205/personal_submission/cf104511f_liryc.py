'''
GYM104511F
2025/12/5 Y1
1800
dijkstra
'''
# dijkstra
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m, v = map(int, input().split())
    s = input()
    trades = [[0, 0, 0, 0, 0, 0] for _ in range(m)]
    for i in range(m):
        a, x, b, y, c, z = map(int, input().split())
        trades[i][:] = (a, x, b, y, c, z)
    return n, m, v, s, trades

def solve(n: int, m: int, v: int, s: str, trades: list[list[int]]) -> float:
    sm = int("0b" + s[::-1], 2)
    def hs(i: int) -> bool:
        pass
    return n, s

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
