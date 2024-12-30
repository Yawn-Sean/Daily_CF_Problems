n, m, k = RII()
if k > (n - 1) + (m - 1):
    print(-1)
    exit()
ans = 0
def f(x):
    y = k - n //x + 1
    return x * (m // max(1,y+1))
for length_x in range(1,min(n,40000) + 1):
    ans = max(ans,f(length_x))
    ans = max(ans,f(n // length_x))
print(ans if ans else -1)
