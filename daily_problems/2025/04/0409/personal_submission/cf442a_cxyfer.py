mp = {ch: i for i, ch in enumerate('RGBYW')}

n = int(input())
cards = list(set(map(lambda x: (mp[x[0]], int(x[1]) - 1), input().split())))
n = len(cards)

ans = float('inf')
for msk in range(1 << 10):
    vis = set()
    for card in cards:
        mark = msk & (1 << card[0]) | msk & (1 << (card[1] + 5))
        vis.add(mark)
    if len(vis) == n:
        ans = min(ans, msk.bit_count())
print(ans)
