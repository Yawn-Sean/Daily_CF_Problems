mii = lambda: map(int, input().split())
MOD = 10**9+7

m, n, k, r, c = mii()
x1, y1, x2, y2 = mii()
ans = pow(k, m*n - r*c*(not (x1==x2 and y1==y2)), MOD)
print(ans)