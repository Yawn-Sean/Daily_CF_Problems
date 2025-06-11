m, n = map(int, input().split())
s = list(map(int, input().split()))
a = [s[0]]
for i in s[1::]:
    if i != a[-1]:
        a.append(i)
n = len(a)
ans = 0
temp = dict()
for i in range(1, n):
    if a[i] not in temp:
        temp[a[i]] = []
    if a[i - 1] not in temp:
        temp[a[i - 1]] = []
    temp[a[i]].append(a[i - 1])
    temp[a[i - 1]].append(a[i])
    ans += abs(a[i] - a[i - 1])
ch = 0
for i in temp:
    temp[i].sort()
    cur = temp[i][len(temp[i]) // 2]
    pre = 0
    aft = 0
    for j in temp[i]:
        pre += abs(i - j)
        aft += abs(cur - j)
    ch = max(ch, pre - aft)
print(ans - ch)
