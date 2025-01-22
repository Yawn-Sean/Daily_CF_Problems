n = (int)(input())
a = []
b = []
s = input()
for i, ch in enumerate(s):
    if ch == '*':
        a.append(i)
    if ch == 'P':
        b.append(i)
l = 0
r = 2 * 10 ** 5 + 5
while l < r:
    mid = (l+r)//2
    pos = 0
    for x in b:
        if abs(a[pos]-x) > mid:
            continue
        t1 = max(0, x - a[pos])
        right = x + max((mid-t1) // 2, mid-t1 * 2)
        while pos < len(a) and right >= a[pos]:
            pos += 1
        if pos == len(a):
            break
    if pos == len(a):
        r = mid
    else:
        l = mid+1
print(l)
