import sys
from collections import Counter
from itertools import permutations

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

saved = [''] * 7
for p in permutations('1689'):
    s_p = ''.join(p)
    saved[int(s_p) % 7] = s_p

def solve() -> None:
    s = input()
    cnt = Counter(s)
    cnt['1'] -= 1
    cnt['6'] -= 1
    cnt['8'] -= 1
    cnt['9'] -= 1
    
    ans = []
    for x in cnt:
        if x != '0':
            ans.append(x * cnt[x])
    
    ans = ''.join(ans)
    mod = 0
    for x in ans:
        mod = (mod * 10 + int(x)) % 7
    
    print(ans + saved[(-mod * 10000) % 7] + '0' * cnt['0'])

solve()
