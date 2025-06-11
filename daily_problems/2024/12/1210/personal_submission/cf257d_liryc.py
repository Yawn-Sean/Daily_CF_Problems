'''
https://codeforces.com/problemset/submission/257/295879780
257D
2024/12/10 Y2
1900
Greedy, constructive
'''
# 逆向思维，从后往前计算
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]) -> str:
    c, b = a[-1], [1]
    for x in a[-2::-1]:
        if abs(c + x) < abs(c - x):
            b.append(1)
            c += x
        else:
            b.append(0)
            c -= x
    flip = c < 0
    return ''.join('+' if x ^ flip else '-' for x in b[::-1])

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
