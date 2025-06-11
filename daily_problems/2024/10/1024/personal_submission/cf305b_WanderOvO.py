p, q = map(int, input().split())
n = int(input())
a = [0] + list(map(int, input().split()))
for i in range(1, n):
    new_p = q
    new_q = p - a[i] * q
    p = new_p
    q = new_q
if a[n] * q == p:
    print("YES")
else:
    print("NO")
