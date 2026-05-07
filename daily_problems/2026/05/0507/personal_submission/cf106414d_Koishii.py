outs = []
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    ans = [k, n]
    a[k - 1], a[n - 1] = a[n - 1], a[k - 1]
    mex = 0
    se = set()
    for i in range(n):
        if i == n - 1:
            if a[i] >= mex:
                outs.append(f'-1 -1')
            else:
                outs.append(' '.join(map(str, ans)))
        se.add(a[i])
        while mex in se:
            mex += 1

print('\n'.join(map(str, outs)))
