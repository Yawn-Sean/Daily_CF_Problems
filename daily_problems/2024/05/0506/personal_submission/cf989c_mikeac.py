import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

s = "ABCD"

def solve() -> None:
    cnt = ints()
    ans = []
    for i, c in enumerate(s):
        cnt[i] -= 1
        line = [c] * 50
        for _ in range(9):
            ans.append(line[:])

    for k, (c, v) in enumerate(zip(s, cnt)):
        if v == 0:
            continue
        k = (k + 1) % 4
        for i in range(k * 9 + 1, (k + 1) * 9, 2):
            for j in range(0, 50, 2):
                ans[i][j] = c
                v -= 1
                if v == 0:
                    break
            if v == 0:
                break

    print(36, 50)
    for row in ans:
        print("".join(row))

solve()
