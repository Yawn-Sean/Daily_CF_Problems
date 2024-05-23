s = input()
n = len(s)
from array import array
valid = [array('b', [0] * n) for _ in range(n)]

for l in range(n):
    left = 0
    for r in range(l, n):
        left += 1 if s[r] != ')' else -1
        if left >= 0:
            valid[l][r] = True
        else:
            break

ans = 0
for r in range(n-1, -1, -1):
    right = 0
    for l in range(r, -1, -1):
        right += 1 if s[l] != '(' else -1
        if right >= 0:
            if valid[l][r] and (r-l+1) % 2 == 0:
                ans += 1
        else:
            break

print(ans)