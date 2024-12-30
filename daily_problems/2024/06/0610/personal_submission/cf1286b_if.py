import sys
input = sys.stdin.readline
n = int(input())
d = [[] for _ in range(n+1)]
x = [[] for _ in range(n+1)]
w = [0]*(n+1)
p = [0]*(n+1)
q = []
z = 0
for i in range(n):
    a, b = map(int, input().split())
    if a == 0:
        z = i+1
        q.append(z)
    else:
        d[i+1].append(a)
        d[a].append(i+1)
    w[i+1] = b
while q:
    a = q.pop()
    if a > 0:
        q.append(~a)
        for i in d[a]:
            if i != p[a]:
                p[i] = a
                q.append(i)
    else:
        a = ~a
        if len(x[a]) < w[a]:
            print('NO')
            exit()
        x[a].insert(w[a], a)
        if a != z:
            x[p[a]].extend(x[a])
ans = [0]*(n+1)
print('YES')
for i in range(n):
    ans[x[z][i]] = i+1
print(' '.join(map(str, ans[1:])))
