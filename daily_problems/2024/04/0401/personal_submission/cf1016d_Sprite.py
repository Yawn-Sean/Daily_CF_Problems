from functools import reduce
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

x = reduce(lambda x,y: x^y, a)
y = reduce(lambda x,y: x^y, b)
if x != y:
    print('NO')
else:
    print('YES')
    ans = [[0] * m for _ in range(n)]
    first = a[0]
    for i in range(1, m):
        first ^= b[i]
        ans[0][i] = b[i]
    ans[0][0] = first
    for i in range(1, n):
        ans[i][0] = a[i]
    for i in ans:
        print(' '.join(map(str, i)))
