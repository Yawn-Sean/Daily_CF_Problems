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
    op = []
    for _ in range(n * 2):
        op.append(input())
    
    op.reverse()
    stk = []
    ans = []
    for s in op:
        if s[0] == "+":
            if not stk:
                print("NO")
                return
            ans.append(stk.pop())
        else:
            price = int(s.split()[1])
            if stk and price > stk[-1]:
                print("NO")
                return
            stk.append(price)
    print("YES")
    print(*reversed(ans))

solve()
