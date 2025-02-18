import sys
import math
import heapq

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
I = lambda: input()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

sys.stdin = open('in.txt', 'r')

def solve():
    n = II()
    s = [int(x) for x in I()]

    ans = 0
    suc = [False] * (n + 1)
    cnt = [0] * n

    for i in range(1, n + 1):
        if n % i == 0:
            for j in range(n):
                cnt[j % i] ^= s[j]
            suc[i] = True
            for j in range(i):
                if cnt[j]:
                    suc[i] = False
                    cnt[j] = 0

        ans += suc[math.gcd(i, n)]

    print(ans)
    pass

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()