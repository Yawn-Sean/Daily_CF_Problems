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
    n, p = MII()
    s = [ord(c) - ord('a') for c in I()]

    for i in range(n - 1, -1, -1):
        for c in range(s[i] + 1, p):
            flag = True
            for j in range(1, 3):
                if i >= j and s[i - j] == c:
                    flag = False
                    break

            if flag == False:
                continue

            s[i] = c
            for j in range(i + 1, n):
                for v in range(p):
                    flag = True
                    for k in range(1, 3):
                        if j >= k and s[j - k] == v:
                            flag = False

                    if flag:
                        s[j] = v
                        break

            print(''.join(chr(x + ord('a')) for x in s))
            return

    print('NO')
    pass

if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()