import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    s = list(input().strip())
    l = list(map(int, input().split()))
    r = list(map(int, input().split()))
    for i in range(k):
        l[i], r[i] = l[i] - 1, r[i] - 1
    f = [0 for __ in range(n)]
    input()
    x = list(map(int, input().split()))
    for xi in x:
        f[xi - 1] ^= 1
    
    for i in range(k):
        mid, j = 0, l[i]
        while j <= l[i] + r[i] - j:
            mid ^= f[j] ^ f[l[i] + r[i] - j]
            if mid:
                s[j], s[l[i] + r[i] - j] = s[l[i] + r[i] - j], s[j]
            j += 1
    
    s = ''.join(s)
    print(s)
