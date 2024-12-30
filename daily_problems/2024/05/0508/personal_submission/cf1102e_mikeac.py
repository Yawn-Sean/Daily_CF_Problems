import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n = sint()
    nums = ints()
    pos = dict()
    for i, a in enumerate(nums):
        pos[a] = i
    
    k = last = 0
    for i, a in enumerate(nums):
        last = max(last, pos[a])
        if last == i:
            k += 1
    
    print(pow(2, k - 1, MOD))

solve()
