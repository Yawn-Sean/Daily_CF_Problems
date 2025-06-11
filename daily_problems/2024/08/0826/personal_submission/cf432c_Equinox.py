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

N = 100_005
primes = []
minp = [0] * (N + 1)

for i in range(2, N + 1):
    if not minp[i]:
        minp[i] = i
        primes.append(i)
    for j in primes:
        if i * j > N:
            break
        minp[i * j] = j
        if minp[i] == j:
            break

def solve():
    n = II()
    a = LMI()
    pos = [-1] * n
    for i in range(n):
        a[i] -= 1
        pos[a[i]] = i

    d = [-1] * (n + 1)

    for i in range(4, n + 1, 2):
        for p in primes:
            if minp[i - p] == i - p:
                d[i] = p
                break

    ans = []

    def f(i: int, j: int) -> None:
        a[i], a[j] = a[j], a[i]
        pos[a[i]], pos[a[j]] = pos[a[j]], pos[a[i]]
        ans.append((i, j))

    def swap(i: int, j: int) -> None:
        if minp[j - i + 1] == j - i + 1:
            f(i, j)
        elif (j - i) % 2 == 0:
            sz = j - i + 2
            f(i + d[sz] - 1, j)
            f(i, i + d[sz] - 1)
        else:
            i += 1
            sz = j - i + 2
            f(i + d[sz] - 1, j)
            f(i, i + d[sz] - 1)
            f(i - 1, i)



    for i in range(n):
        if pos[i] != i:
            swap(i, pos[i])

    print(len(ans))
    for x, y in ans:
        if x > y:
            x, y = y, x
        print(x + 1, y + 1)
    pass

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()