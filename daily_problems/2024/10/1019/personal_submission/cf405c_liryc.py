'''
https://codeforces.com/problemset/submission/405/286648453
405C
2024/10/19 Y1
1600
脑筋急转弯
'''

import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
ans = 0
r = []

for i in range(n):
    a = list(map(int, input().split()))
    ans ^= a[i]

q = int(input())
for _ in range(q):
    s = input()
    if s[0] == '3': 
        r.append(ans)
    else: 
        ans ^= 1

print(''.join(map(str, r)))
