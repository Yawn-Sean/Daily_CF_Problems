'''
https://codeforces.com/problemset/submission/1252/288463013
1252H
2024/10/28 Y1
1800
'''
# ref
n = int(input())
a, b = [], []

ans = 0
for _ in range(n):
    w, l = map(int, input().split())
    if w > l:
        w, l = l, w
    a.append(w)
    b.append(l)
    ans = max(ans, w * l)

ma_l = 0
for i in sorted(range(n), key=lambda x: -a[x]):
    ans = max(ans, 2 * a[i] * min(b[i], ma_l))
    ma_l = max(ma_l, b[i])

print(f'{ans >> 1}.{(ans & 1) * 5}')