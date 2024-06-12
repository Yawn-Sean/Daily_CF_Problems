N, d = map(int, input().split())

op = list(map(int, input().split()))

l = r = res = 0

for x in op:
    if not x:
        l = max(l, 0)
        if r < 0:
            r = d
            res += 1
    else:
        l += x
        r += x
        r = min(r, d)
        if l > d:
            print(-1)
            exit()
print(res)