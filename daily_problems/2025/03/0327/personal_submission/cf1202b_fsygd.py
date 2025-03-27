s = input()
s = [int(c) for c in s]
for x in range(10):
    for y in range(10):
        dist = [[100 for i in range(10)] for j in range(10)]
        for i in range(10):
            dist[i][(i + x) % 10] = 1
            dist[i][(i + y) % 10] = 1
        for k in range(10):
            for i in range(10):
                for j in range(10):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
        if y != 0:
            print(' ', end='')
        flag = True
        ans = 0
        for i in range(len(s) - 1):
            if dist[s[i]][s[i + 1]] == 100:
                flag = False
                break
            else:
                ans += dist[s[i]][s[i + 1]] - 1
        if flag:
            print(ans, end='')
        else:
            print('-1', end='')

    print()