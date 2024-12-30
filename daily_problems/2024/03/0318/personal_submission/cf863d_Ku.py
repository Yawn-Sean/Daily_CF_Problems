n,q,m = map(int, input().split())
a = list(map(int, input().split()))
li = [range(n)]
ans = [0] + [1] *(n-1)
queries = []
for _ in range(q):
    t,l,r = map(lambda x: int(x) - 1, input().split())
    queries.append((t,l,r))
b = list(map(lambda x: int(x) - 1, input().split()))
#逆序，看b[i]是由数组中哪个位置操作后得到的，因此对b[i]逆序回去求初始位置的下标
for t,l,r in reversed(queries):
    if t:
        #进行第二个操作，反转
        for i in range(m):
            if l <= b[i] <= r:
                b[i] = l + r - b[i]
    else:
        #第一个操作，右移动
        for i in range(m):
            if l < b[i] <= r:
                b[i] -= 1
            elif b[i] == l:
                b[i] = r

print(' '.join(map(str,(a[p] for p in b))))
