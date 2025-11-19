import sys
input = lambda: sys.stdin.readline().rstrip()

def soviet():
    n = int(input())
    e = [[] for _ in range(n)]
    for i in range(n):
        s = input()
        for j in range(n):
            if s[j] != '0':
                e[i].append(j)

    ans = []
    que = [0]
    vis = [False] * n
    vis[0] = True
    while len(que):
        x = que.pop()
        for y in e[x]:
            if not vis[y]:
                que.append(y)
                vis[y] = True
                ans.append((x, y))

    if False in vis:
        print("No")
    else:
        print("Yes")

    for x, y in ans[::-1]:
        print(x + 1, y + 1)
    print()

MT = int(input())
for _ in range(MT):
    soviet()
