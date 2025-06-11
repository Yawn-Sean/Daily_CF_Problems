'''
https://codeforces.com/problemset/submission/1118/286212437
1118E
2024/10/16 Y1
1700
permutations
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, k = map(int, input().split())
    return n, k

def enumAnswer(k: int):
    for d in range(1, k):
        for i in range(k):
            yield f"{i + 1} {(i + d) % k + 1}"

def solve(n: int, k: int):
    if n > k * (k - 1):
        return "NO"
    return "YES"

if __name__ == '__main__':
    n, k = init()
    ans = solve(n, k)
    print(ans)
    if ans == "YES":
        i = 0
        for s in enumAnswer(k):
            print(s)
            i += 1
            if i == n:
                break