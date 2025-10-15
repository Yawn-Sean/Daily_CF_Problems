'''
https://codeforces.com/problemset/submission/938/298380366
938C
2024/12/25 Y1
1700
constructive
'''
# ref, solve formula
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    x = int(input())
    return x

def solve(x: int):
    if x == 0:
        return 1, 1
    for i in range(1, x):
        if i * i >= x: 
            break
        if x % i == 0:
            a, b = x // i, i
            n = (a + b) // 2
            m = (a + b) // (a - b)
            if n * n - (n // m) * (n // m) == x:
                return n, m
    return -1, -1

if __name__ == '__main__':
    for _ in range(int(input())):
        x = init()
        n, m = solve(x)
        if n < 0:
            print(n)
        else:
            print(n, m)