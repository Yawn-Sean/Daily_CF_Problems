import os
import random
import sys
from collections import defaultdict, Counter, deque
from functools import cache, reduce
from itertools import pairwise, combinations, permutations, groupby

input = sys.stdin.readline
print = sys.stdout.write


I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))


def solve():
    n, m = MII()
    dp = [0] * (n + 1)
    s = [0] * (n + 1)
    diff = [0] * (n + 2)
    for i in range(1, n + 1):
        diff[i] += diff[i - 1]
        dp[i] = (s[i - 1] + diff[i]) % m
        dp[1] = 1;
        for j in range(2, n // i + 1):
            diff[i * j] += dp[i];
            diff[min(n + 1, i * j + j)] -= dp[i];
        s[i] = (s[i - 1] + dp[i]) % m
    print(f"{dp[n]}\n")


TC = 1

def main():
    for _ in range(TC):
        solve()

main()
