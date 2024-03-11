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
    p = ints()
    root = 0
    core = None
    col = [-1] * (n + 1)
    odd = False
    for i, x in enumerate(p, 1):
        if i == x:
            root = x
            break
        cnt = 0
        while col[x] == -1:
            col[x] = cnt & 1
            cnt += 1
            x = p[x - 1]
        if not odd and cnt & 1:
            odd = True
        if cnt == 2 and not core:
            core = [i, x]

    if root:
        print("YES")
        for i in range(1, n + 1):
            if i == root:
                continue
            print(root, i)
        return

    if odd or not core:
        print("NO")
        return
    
    print("YES")
    print(core[0], core[1])
    for i in range(1, n + 1):
        if i == core[0] or i == core[1]:
            continue
        print(core[col[i] & 1], i)

solve()
