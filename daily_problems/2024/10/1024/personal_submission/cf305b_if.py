def check(i, j, m):
    return i - m * j, j
p, q = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))
for i in a:
    p, q = check(p, q, i)
    p, q = q, p
if q == 0:
    print("YES")
else:
    print("NO")
