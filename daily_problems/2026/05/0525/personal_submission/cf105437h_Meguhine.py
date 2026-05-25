import sys

input = lambda: sys.stdin.readline().rstrip()

n = int(input())
s = input()

a = [0] * n
sp = []
l, r = 0, 0
base = 0
while l < n:
    while r + 1 < n and s[l] == s[r + 1]:
        r += 1
    a[l] = a[r] = r - l + 1
    base += (r - l + 1)**2
    sp.append(r)
    l = r + 1
sp.pop()

# print(a, file=sys.stderr)
# print(sp, file=sys.stderr)

ans = 0
for i in sp:
    res = base - a[i]**2 - a[i + 1]**2
    o, v = [], []
    if i != 0:
        o += [i - 1]
        if a[i] == 1:
            v += [a[i - 1]]
            res -= a[i - 1]**2
        else:
            v += [a[i] - 1]
    o += [i + 1, i]
    v += [1, 1]
    if i + 2 < n:
        o += [i + 2]
        if a[i + 1] == 1:
            v += [a[i + 2]]
            res -= a[i + 2]**2
        else:
            v += [a[i + 1] - 1]
    # print(f"{i=} {o=} {v=}", file=sys.stderr)
    while len(o) >= 2:
        if s[o[-1]] == s[o[-2]]:
            v[-2] += v[-1]
            o.pop()
            v.pop()
        else:
            res += v.pop()**2
            o.pop()
    res += v.pop()**2
    # print(f"\t{res=}", file=sys.stderr)
    ans = max(ans, res)
print(ans)
