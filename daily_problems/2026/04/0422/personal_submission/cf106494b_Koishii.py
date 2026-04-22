n = int(input())
l = list(map(int, input().split()))
r = list(map(int, input().split()))

id = l.index(max(l))
sum_l = sum(l)
sum_r = sum(r)

if sum_r - r[id] < l[id]:
    exit(print(-1))

outs = []
for i in range(n):
    outs.append(min(r[i], l[id]))

print(' '.join(map(str, outs)))
