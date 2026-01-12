n, p = il()
w = [il() for _ in range(n)]

def fun(w1, w2):
    a, b, c = w1
    d, e, f = w2
    v1 = b + a * e
    v2 = e + d * b
    return 1 if v1 > v2 else -1 if v1 < v2 else 0

w.sort(key = cmp_to_key(fun))
dp = [0] * (p + 1)
for a, b, c in w:
    for i in range(b, p + 1):
        dp[(i - b) // a] = max(dp[(i - b) // a], dp[i] + c)
print(max(dp))
