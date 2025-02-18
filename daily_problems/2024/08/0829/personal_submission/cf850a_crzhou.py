n = int(input())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))

good = []

for i in range(n):
    for j in range(n):
        if j != i:
            for k in range(j + 1, n):
                if k != i:
                    ans = 0
                    for l in range(5):
                        ans += (a[j][l] - a[i][l]) * (a[k][l] - a[i][l])
                    if ans > 0:
                        break
            else:
                continue
            break
    else:
        good.append(i + 1)  # Adjust index to be 1-based like in the original code

print(len(good))
for g in good:
    print(g)
