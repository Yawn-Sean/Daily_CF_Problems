import sys
from sortedcontainers import SortedList
from bisect import bisect_left
from bisect import bisect_right
from string import ascii_uppercase
from math import inf

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 10**9 + 7

sys.stdin = open('in.txt', 'r')

def solve():
    f = [[0] * 2501 for _ in range(101)]
    f[0][0] = 1

    acc = [0] * 2502

    for i in range(1, 101):
        for j in range(i * 25 + 1):
            acc[j + 1] = (acc[j] + f[i - 1][j]) % P
            f[i][j] = ((acc[j + 1] - acc[j - 25]) % P + P) %P

    t = II()
    res = []
    for _ in range(t):
        s = input()
        n = len(s)
        tot = sum(ord(x) - ord('a') for x in s)
        res.append((f[n][tot] - 1 % P))
    print('\n'.join(map(str, res)))

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()