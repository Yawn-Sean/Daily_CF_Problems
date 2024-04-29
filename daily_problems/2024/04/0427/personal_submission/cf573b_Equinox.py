import sys
import math
sys.stdin = open('in.txt', 'r')

input = lambda: sys.stdin.readline().strip()
write = lambda x: sys.stdout.write(str(x) + '\n')

n = int(input())

f = list(map(int, input().split()))

f[0] = 1
for i in range(1, n):
    f[i] = min(f[i], f[i - 1] + 1)
f[n - 1] = 1

for i in range(n - 2, -1, -1):
    f[i] = min(f[i], f[i + 1] + 1)

write(max(f))