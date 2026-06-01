import sys

input = lambda: sys.stdin.readline().rstrip()


n, K = map(int, input().split())
a = list(map(lambda s: int(s) % K, input().split()))
m = n - a.count(0)
if m == 0:
    print("Rami")
elif m == 2:
    print("Oussama")
else:
    print("Rami" if n & 1 else "Oussama")
