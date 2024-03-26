import sys
input = lambda: sys.stdin.readline().strip()
n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))

circle = 0
for i in range(n):
    if a[i] == -1:
        continue
    k = i
    while a[k] != -1:
        a[k], k = -1, a[k]
    circle += 1

if circle & 1:
    print('Um_nik')
else:
    print('Petr')
