n = II()
songs = []

for _ in range(n):
    songs.append(LII())

songs.sort(key=lambda x: -(x[0] * x[1]) / ((100 - x[1]) if x[1] < 100 else 0.000001))

ans = 0
pre = 0
for i in range(n):
    ans += songs[i][0]     # 喜欢
    ans += pre * (1 - songs[i][1] / 100)    # 不喜欢
    pre += songs[i][0] * songs[i][1] / 100  # 不喜欢

print(ans)
