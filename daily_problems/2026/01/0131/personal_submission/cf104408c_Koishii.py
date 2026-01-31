outs = []
def soviet():
    n, m = map(int, input().split())
    a = [list(map(int, input())) for _ in range(n)]

    flag = [0] * n
    ans = 0

    for j in range(m - 1, -1, -1):
        n0 = 0
        n1 = 0
        for i in range(n):
            a[i][j] ^= flag[i]
            if a[i][j] == 0:
                n0 += 1
            else:
                n1 += 1

        ans += min(n0, n1)

        for i in range(n):
            if n0 > n1:
                if a[i][j] == 1: flag[i] ^= 1
            else:
                if a[i][j] == 0: flag[i] ^= 1

    outs.append(str(ans))


MT = int(input())
for _ in range(MT):
    soviet()
print('\n'.join(outs))
