n, w = map(int, input().split())

a = [0] + sorted(list(map(int, input().split())))
s = [0] * (n + 1)

for i in range(1, n + 1):
    s[i] = s[i - 1] + a[i]

def query_sum(l, r):
    return s[r] - s[l - 1]

sum_d = 0
for i in range(1, n + 1):
    sum_d += i * a[i] - query_sum(1, i) + query_sum(i + 1, n) - (n - i) * a[i]

print(sum_d / n + w)

