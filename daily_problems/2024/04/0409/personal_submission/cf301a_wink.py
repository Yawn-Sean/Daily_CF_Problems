import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))

odd = sum(1 for v in a if v < 0)
ans = sum(abs(v) for v in a)

if odd % 2 == 0:
    print(ans)
    exit()
if n % 2 or a.count(0):
    print(ans)
    exit()
res = min(abs(v) for v in a)
print(ans - 2 * res)
