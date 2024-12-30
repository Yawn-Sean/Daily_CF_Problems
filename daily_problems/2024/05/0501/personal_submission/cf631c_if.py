n, m = map(int, input().split())
a = list(map(int, input().split()))
t = []
for i in range(m):
    d, r = map(int, input().split())
    while t and t[-1][1] <= r:
        t.pop()
    t.append([d, r])
t.append([0, 0])
x = 0
y = t[0][1] - 1
sor = sorted(a[:t[0][1]])
for i in range(1, len(t)):
    for j in range(t[i-1][1], t[i][1], -1):
        if t[i-1][0] == 1:
            a[j-1] = sor[y]
            y -= 1
        else:
            a[j-1] = sor[x]
            x += 1
 
for i in a:
    print(i,end=' ')
