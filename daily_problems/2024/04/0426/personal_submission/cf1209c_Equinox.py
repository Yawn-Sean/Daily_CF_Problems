import sys
from math import inf
sys.stdin = open('in.txt', 'r')

input = lambda: sys.stdin.readline().strip()
write = lambda x: sys.stdout.write(str(x))

n = int(input())
lines = [tuple(map(int, input().split())) for _ in range(n)]

prel, prer = [-inf] * n, [inf] * n

for i in range(1, n):
    prel[i] = max(lines[i - 1][0], prel[i - 1])
    prer[i] = min(lines[i - 1][1], prer[i - 1])
sufl, sufr = -inf, inf

ans = 0

for i in range(n - 1, -1, -1):
    ans = max(ans, min(sufr, prer[i]) - max(sufl, prel[i]))
    sufl = max(sufl, lines[i][0])
    sufr = min(sufr, lines[i][1])
write(ans)