import sys
from bisect import bisect

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
    prices = [[] for _ in range(n + 1)]
    person = set()
    for _ in range(n):
        a, b = mint()
        person.add(a)
        prices[a].append(b)
    
    person = sorted(person, key = lambda x: -prices[x][-1])
    for _ in range(sint()):
        exclude = set(ints()[1:])
        fst = snd = -1
        for x in person:
            if x in exclude:
                continue
            if fst == -1:
                fst = x
            else:
                snd = x
                break
        if fst == -1:
            print(0, 0)
        elif snd == -1:
            print(fst, prices[fst][0])
        else:
            p = bisect(prices[fst], prices[snd][-1])
            print(fst, prices[fst][p])


solve()
