n = int(input())
a = list(map(int, input().split()))
pos = []
neg = []

for x in a:
    x *= 2
    if x > 0:
        pos.append(x)
    else:
        neg.append(x)

pos.sort()
neg.sort()

def mid(neg):
    m = len(neg)
    if m == 0:
        return 0
    if m & 1:
        return neg[m // 2]
    return (neg[m // 2] + neg[(m - 1) // 2]) // 2

now = sum(pos)
ans = now + mid(neg)

for x in pos:
    neg.append(x)
    now -= x
    ans = max(ans, now + mid(neg))

print(ans)
