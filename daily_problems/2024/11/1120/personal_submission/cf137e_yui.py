def op(a, b):
    # min
    return a if a < b else b

a = input().lower()
n = len(a)

s = [0] * (n + 1)
for i in range(n):
    if a[i] in 'aeiou':
        s[i + 1] = s[i] - 1
    else:
        s[i + 1] = s[i] + 2

tr = SegTree(op, 10**9, s)

# v <= 2c
# 2c - v >= 0
cnt = [0] * (2 * n + 10)

for i in range(1, n + 1):
    l = tr.max_right(0, lambda premi: premi > s[i])
    
    if i == l and (a[i - 1] in 'aeiou'):
        continue

    leng = i - l
    cnt[leng] += 1

for j in range(n, -1, -1):
    if cnt[j] > 0:
        print(f'{j} {cnt[j]}')
        exit(0)

print("No solution")
