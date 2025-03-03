t, w, b = map(int, input().split())

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

# print(lcm(w, b))
cnt = t // lcm(w, b)
# print(cnt)
x = min(w, b)
mx = cnt * lcm(w, b)
res = 0
if cnt > 0:
    res += (cnt - 1) * x

if mx != 0:
    res += min(x, t - mx + 1)
res += min(t, min(w, b) - 1)
g = gcd(res, t)
res //= g
t //= g
print(res, end='/')
print(t)
