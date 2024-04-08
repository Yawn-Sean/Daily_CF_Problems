n, x, y = map(int, input().split())

lst = ['Both']
nx = ny = 0
while True:
    if (nx + 1) * y == (ny + 1) * x:
        lst.append('Both')
        break
    elif (nx + 1) * y > (ny + 1) * x:
        lst.append('Vova')
        ny += 1
    else:
        lst.append('Vanya')
        nx += 1

m = len(lst)
for _ in range(n):
    now = int(input())
    print(lst[now % m])
