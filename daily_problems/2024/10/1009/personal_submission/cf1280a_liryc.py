'''
https://codeforces.com/contest/1280/submission/285031418
1280 A
2024/10/9 Y1
1700
math + BF
'''
# TLE, ref solution for tuning
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    x = int(input())
    s = input()
    return x, s

# solve TLE:
# convert s into int array
# int array max len is x
def solve(x: int, s: str) -> int:
    n = len(s)
    for i in range(x):
        if s[i] == '2':
            if len(s) < x:
                s += s[i + 1:]
            n = ((n << 1) - 1 - i) % 1000000007
        elif s[i] == '3':
            if len(s) < x:
                s += s[i + 1:] * 2
            n = (n + (n - 1 - i << 1)) % 1000000007
    return n % 1000000007

if __name__ == '__main__':
    ans = []
    for _ in range(int(input())):
        args = init()
        ans.append(str(solve(*args)))
    print('\n'.join(ans))
