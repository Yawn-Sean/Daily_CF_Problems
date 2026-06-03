import sys

input = lambda: sys.stdin.readline().rstrip()

ord_a = ord('a')
oe = ord('e') - ord_a
oz = ord('z') - ord_a
op = ord('p') - ord_a
oc = ord('c') - ord_a


def solve() -> str:
    pos = [0] * 26
    for i, c in enumerate(input()):
        pos[ord(c) - ord_a] = i
    pe = pos[oe]
    pz = pos[oz]
    pp = pos[op]
    pc = pos[oc]
    return "YES" if (pe < pc and pz < pp < pc) else "NO"


print('\n'.join(solve() for _ in range(int(input()))))
