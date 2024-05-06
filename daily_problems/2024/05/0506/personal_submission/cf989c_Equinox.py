import sys
# sys.stdin = open('in.txt', 'r')
cnt = list(map(int, input().split()))

n, m = 50, 50
st = 'ABCD'

g = [[''] * 50 for _ in range(50)]

for i in range(50):
    for j in range(50):
        g[i][j] = st[i // 25 * 2 + j // 25]
for i in range(4):
    cnt[i] -= 1
    dx, dy = divmod((i + 1) % 4, 2)
    for x in range(1,25,2):
        for y in range(1, 25, 2):
            if not cnt[i]:
                break
            g[x + dx * 25][y + dy * 25] = st[i]
            cnt[i] -= 1
        else:
            continue
        break
print(n, m)
for x in g:
    print(''.join(x))