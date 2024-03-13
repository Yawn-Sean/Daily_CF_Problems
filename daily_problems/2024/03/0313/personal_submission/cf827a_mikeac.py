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

mx = 2 * 10 ** 6

def solve() -> None:
    n = sint()
    idx = [-1] * (mx + 1)
    s = []
    m = 0
    for i in range(n):
        t = input().split()
        s.append(t[0])
        l = len(t[0])
        for j in map(int, t[2:]):
            j -= 1
            if idx[j] == -1 or l > len(s[idx[j]]):
                idx[j] = i
                m = max(m, j + l)
    
    ans = ['a'] * m
    j = -1
    for i in range(m):
        if idx[i] != -1 and (j == -1 or i + len(s[idx[i]]) > j + len(s[idx[j]])):
            j = i
        if j != -1 and i - j < len(s[idx[j]]):
            ans[i] = s[idx[j]][i - j]
    print("".join(ans))


solve()
