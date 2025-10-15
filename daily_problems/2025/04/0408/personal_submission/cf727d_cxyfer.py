from collections import defaultdict

sz = ['S', 'M', 'L', 'XL', 'XXL', 'XXXL']
mp = {s:i for i, s in enumerate(sz)}

A = list(map(int, input().split()))
n = int(input())

ans = [''] * n
cnt = defaultdict(list)
for idx in range(n):
    sizes = list(map(lambda x: mp[x], input().split(',')))
    if len(sizes) == 1:
        x = sizes[0]
        if A[x] > 0:
            A[x] -= 1
            ans[idx] = sz[x]
        else:
            exit(print('NO'))
    else:
        x, y = sizes
        cnt[(x, y)].append(idx)

for (x, y), lst in sorted(cnt.items(), key=lambda x: x[0]):
    for idx in lst:
        if A[x] > 0:
            A[x] -= 1
            ans[idx] = sz[x]
        elif A[y] > 0:
            A[y] -= 1
            ans[idx] = sz[y]
        else:
            exit(print('NO'))

print('YES')
print('\n'.join(ans))
