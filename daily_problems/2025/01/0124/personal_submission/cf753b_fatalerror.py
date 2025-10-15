def ask(s):
    print(s, flush=True)
    return map(int, input().split())

digits = []
for x in map(str, range(10)):
    a, b = ask(x*4)
    if a:
        digits.append(x)

from itertools import permutations
for chs in permutations(digits):
    a, b = ask(''.join(chs))
    if a == 4:
        break