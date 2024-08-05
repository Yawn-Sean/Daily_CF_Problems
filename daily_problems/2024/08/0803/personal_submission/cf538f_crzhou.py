    n = read()
    
    s = []
    for i in range(1, n + 1):
        a = read()
        s.append((a, i))
    
    s.sort()
    
    c = FenwickTree(n)
    ans = [0] * n
    
    for i in range(n):
        a, b = s[i]
        c.add(b, 1)
        for j in range(1, n):
            if b * j - j + 2 > n:
                break
            ans[j] += c.sum(min(n, b * j + 1)) - c.sum(b * j - j + 1)
    
    print(' '.join(map(str, ans[1:n])))
