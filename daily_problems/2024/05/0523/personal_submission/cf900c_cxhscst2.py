n = int(input())
first, second = 0, 0
f = [0] * (n + 2)

for x in input().split() :
    x = int(x)
    if x > first :
        first, second = x, first
    elif x > second :
        second = x

    if x == first :
        f[x] -= 1
    elif x == second :
        f[first] += 1

ans = 1
for i in range(2, n + 1) :
    if f[i] > f[ans] :
        ans = i

print(ans)
