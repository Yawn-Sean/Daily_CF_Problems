import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

n = II()
kid = [0] * (n + 1)
for i in range(1, n + 1):
    kid[i] = LMII()

ans = [1]
t = 1
while True:
    if kid[t][0] in kid[kid[t][1]]:
        ans.append(kid[t][1])
        ans.append(kid[t][0])
        t = kid[t][0]
    else:
        ans.append(kid[t][0])
        ans.append(kid[t][1])
        t = kid[t][1]
    if len(ans) > n: break

print(*ans[:n]) # 直接取最后前n个点即可