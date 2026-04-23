n = int(input())
a = list(map(int, input().split()))
pos = []
neg = []
for x in a:
    if x > 0:
        pos.append(x)
    else:
        neg.append(x)

pos.sort()
neg.sort(reverse = True)

m = len(pos)
for i in range(m):
    if neg:
        neg.pop()

ans = sum(pos)

if neg:
    ans += neg[(len(neg) - 1) // 2]

print(ans)
