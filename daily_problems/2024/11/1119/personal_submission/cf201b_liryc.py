'''
https://codeforces.com/problemset/submission/201/292321931
201B
20241119 Y1
1800
Math
'''

# ref

n, m = map(int, input().split())
a, b1, b2, c = 0, 0, 0, 0

for i in range(n):
    x = (i << 2) + 2
    for j, t in enumerate(list(map(int, input().split()))):
        a += t
        y = (j << 2) + 2
        b1 += (t << 1) * x
        b2 += (t << 1) * y
        c += t * (x * x + y * y)

def search(a, b):
    if a == 0: return 0
    x = b // (a << 3)
    return x if abs((x * a << 3) - b) <= abs(((x + 1) * a << 3) - b) else x + 1

e = search(a, b1) << 2
f = search(a, b2) << 2

print(a * (e * e + f * f) - b1 * e - b2 * f + c)
print(e >> 2, f >> 2)