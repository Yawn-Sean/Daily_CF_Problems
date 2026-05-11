outs = []
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if a[0] <= 2 and a[-1] <= 2:
        outs.append('YES')
    else:
        outs.append('NO')

print('\n'.join(outs))
