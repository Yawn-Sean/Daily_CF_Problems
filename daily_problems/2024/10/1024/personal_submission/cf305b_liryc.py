'''
https://codeforces.com/problemset/submission/305/287634773
CF305 B
2024/10/24 Y1
1700
math
'''
# ref
p, q = map(int, input().split())

n = int(input())
a = list(map(int, input().split()))

b = []
while q:
    b.append(p // q)
    p %= q
    p, q = q, p

if n >= 2 and a[-1] == 1:
    a.append(a.pop() + a.pop())

if b == a:
    print("YES")
else:
    print("NO")