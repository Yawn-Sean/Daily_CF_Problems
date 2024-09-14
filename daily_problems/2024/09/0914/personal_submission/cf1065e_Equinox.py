import sys

input = lambda: sys.stdin.readline().strip()
output = lambda: sys.stdout.write(str(x) + '\n')
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
I = lambda: input()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

# sys.stdin = open('in.txt', 'r')
P = 998244353

def solve():
    n, m, A = MII()
    b = LMI()

    res = 1
    pre = 0
    for x in b:
        t = pow(A, x - pre, P)
        res = res * t * (t + 1) // 2 % P
        pre = x
    print(res * pow(A, n - 2 * b[-1], P) % P)

    pass

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()