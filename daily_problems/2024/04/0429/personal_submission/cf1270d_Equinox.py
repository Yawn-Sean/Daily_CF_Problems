import sys
from collections import Counter

# sys.stdin = open('in.txt', 'r')

n, k = map(int, input().split())

st = Counter()

for i in range(1, k + 2):
    print('?', *(j for j in range(1, k + 2) if j != i), flush=True)
    idx, val = map(int, input().split())
    st[val] += 1

print('!', st[max(st)])