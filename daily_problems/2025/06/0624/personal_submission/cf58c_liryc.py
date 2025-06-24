'''
58C
2025/06/24 Y1
1800
array
'''
# counter
from sys import stdin
input = lambda: stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]) -> int:
    b = [0] * n
    i, j, k = 0, n - 1, 1
    while i <= j:
        b[i] = b[j] = k
        i, j, k = i + 1, j - 1, k + 1
    cn = [0] * n
    for i in range(n):
        d = a[i] - b[i]
        if d >= 0:
            cn[d] += 1
    return n - max(cn)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
