import sys

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
I = lambda: input()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 1_000_000_007

sys.stdin = open('in.txt', 'r')

def solve():
    n = II()
    s = I()

    f = [[0] * (n + 1) for _ in range(26)]

    for i in range(26):
        for j in range(1, n + 1):
            l = t = 0
            ma = 0
            for r in range(n):
                t += 1 if ord(s[r]) - ord('a') != i else 0
                while t > j:
                    t -= 1 if ord(s[l]) - ord('a') != i else 0
                    l += 1
                ma = fmax(ma, r - l + 1)
            f[i][j] = ma

    q = II()

    ans = []

    for _ in range(q):
        m, c = I().split()
        ans.append(f[ord(c) - ord('a')][int(m)])
    print('\n'.join(map(str, ans)))
    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()