'''
https://codeforces.com/problemset/submission/185/295760683
185B
20241209 Y1
1800
math (最优化问题)
'''
# ref
s = int(input())
a, b, c = map(int, input().split())
x, y, z = s, 0, 0
if a != 0 or b != 0 or c != 0:
    sm = a + b + c
    x, y, z = s * a / sm, s * b / sm, s * c / sm
print(x, y, z)
