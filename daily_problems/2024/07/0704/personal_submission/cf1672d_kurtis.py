import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# Hint: The operation is only about moving one element.
# 必须要相等才能移动
# 太难想了，不用急着先操作完，可以观察操作的性质

outs = []
for _ in range(II()):
    n = II()
    a, b = LGMI(), LGMI()
    saved = [0] * n

    pt = 0
    for x in a:
        if x == b[pt]:
            pt += 1
        else:
            saved[x] += 1
        while pt < n and pt > 0 and b[pt] == b[pt - 1] and saved[b[pt]]: # 可以操作
            saved[b[pt]] -= 1
            pt += 1
    outs.append('YES' if pt == n else 'NO')

print(*outs, sep='\n')