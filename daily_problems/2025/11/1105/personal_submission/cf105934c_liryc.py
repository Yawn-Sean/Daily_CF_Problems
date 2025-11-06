'''
https://codeforces.com/gym/105934/submission/347550696
'''
# greedy
from sys import stdin
input = lambda: stdin.readline().strip()

# s: 1 or -1, means compare bigger or smaller
def solve(n: int, a: list[int], s: int) -> int: 
    p = (a[0] * s - 1) * s
    ans = 0
    for x in a:
        if x * s > p * s:
            p = x
        else:
            p = (p * s + 1) * s
            ans += abs(p - x)
        s = -s
    return ans

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    print(min(solve(n, a, 1), solve(n, a, -1)))

