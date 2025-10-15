'''
https://codeforces.com/contest/51/submission/299019489
'''

n = RI()
a = RILIST()
a.sort()
eps = 1e-6
l, r = 0, a[-1] - a[0]
def check(mid):
    i = 0
    for _ in range(3):
        i = bisect_right(a, a[i] + 2 * mid)
        if i >= n:
            return True
    return False

while l + eps < r:
    mid = (l + r) / 2
    if check(mid):
        r = mid
    else:
        l = mid

def conv(x):
    return '{:.6f}'.format(x)

print(conv(r))
ans = [a[0] + r]
i = bisect_right(a, a[0] + 2 * r)
if i >= n:
    ans.append(a[-1] + r)
    ans.append(a[-1] + r * 2)
else:
    ans.append(a[i] + r)
    if a[-1] - r == a[i] + r:
        ans.append(a[-1] - r + 0.1)
    else:
        ans.append(a[-1] - r)
print(' '.join(map(conv, ans)))

