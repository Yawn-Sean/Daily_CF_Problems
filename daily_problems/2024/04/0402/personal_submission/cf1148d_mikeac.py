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

def solve() -> None:
    n = sint()
    A, B = [0] * n, [0] * n
    asc, dsc = [], []
    for i in range(n):
        A[i], B[i] = mint()
        if A[i] < B[i]:
            asc.append(i + 1)
        else:
            dsc.append(i + 1)
    
    if len(asc) >= len(dsc):
        asc.sort(key = lambda x: -B[x - 1])
        print(len(asc))
        print(*asc)
    else:
        dsc.sort(key = lambda x: A[x - 1])
        print(len(dsc))
        print(*dsc)


solve()
