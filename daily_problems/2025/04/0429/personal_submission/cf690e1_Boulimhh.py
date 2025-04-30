"""
来学一手吧，对灰度还没了解， 现在了解了
"""
# python
for _ in range(int(input())):
    h, w = map(int, input().split())
    g = [list(map(int, input().split())) for _ in range(h)]

    d1, d2 = 0, 0
    for j in range(w):
        d1 += abs(g[0][j] - g[-1][j])
        d2 += abs(g[h // 2][j] - g[h // 2 - 1][j])
    if d1 > d2: print("No", end = ' ')
    else: print("Yes", end = ' ')
