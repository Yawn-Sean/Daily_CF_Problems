n,r = map(int,input().split())
x = list(map(int,input().split()))
pos = [r] * n
for i in range(n):
    for j in range(i):
        if abs(x[j] - x[i]) <= 2 * r:
            pos[i] = max(pos[i],pos[j] + (4 * r * r - (x[j] - x[i]) ** 2) ** 0.5)
print(' '.join(map(str,pos)))
