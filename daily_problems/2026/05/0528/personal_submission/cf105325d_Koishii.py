outs = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = [0] * (n + 1)
    for x in a:
        b[0] += 1
        b[min(x, n)] -= 1

    cnt = 0
    for i in range(n):
        b[i + 1] += b[i]
        cnt += min(b[i], a[i])

    outs.append(sum(a) - cnt)

print('\n'.join(map(str, outs)))
