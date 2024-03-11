from collections import Counter

import math


def main():
    n = int(input())
    s, t = input(), input()
    if Counter(s) != Counter(t):
        return -1

    ans = math.inf
    for i, c in enumerate(t):
        match = 0
        k = 0
        for j in range(i, n):
            while k < n and s[k] != t[j]:
                k += 1
            if k == n:
                break
            match += 1
            k += 1
        ans = min(ans, n - match)
    return ans


for _ in range(int(input())):
    print(main())
