def main():
    n = II()
    c = defaultdict(int)
    v1 = set()
    v2 = set()
    g = []
    for _ in range(n):
        s = list(map(str,I()))
        g.append(s)
        m = len(s)
        for i in range(m):
            c[s[i]] += 10 ** (m - i - 1)
            if i == 0:
                v1.add(s[i])
            v2.add(s[i])
    a = []
    b = []
    for x in 'abcdefghij':
        if x in v2:
            if x not in v1:
                b.append(x)
            else:
                a.append(x)
    a = sorted(a,key=lambda x:-c[x])
    b = sorted(b,key=lambda x:-c[x])
    l,r = 0,1
    cost = [0] * 10
    n,m = len(a),len(b)
    k = 1
    if b != []:
        i = ord(b[0]) - ord('a')
        cost[i] = 0
    while l < n or r < m:
        if l >= n:
            t = b[r]
            r += 1
        elif r >= m:
            t = a[l]
            l += 1
        else:
            if c[a[l]] >= c[b[r]]:
                t = a[l]
                l += 1
            else:
                t = b[r]
                r += 1
        cost[ord(t) - ord('a')] = k
        k += 1
    ans = 0
    # print(cost)
    for s in g:
        m = len(s)
        r = 0
        for i,x in enumerate(s):
            d = cost[ord(x) - ord('a')]
            r += d * 10 ** (m - i - 1)
        ans += r
    print(ans)
