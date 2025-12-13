mod = 10 ** 9 + 7
N = 10 ** 6 + 6

inv = [1] * N
h = [1] * N

for i in range(2, N):
    inv[i] = mod - mod // i * inv[mod % i] % mod
    h[i] = (h[i - 1] + inv[i]) % mod

def soviet():
    n = int(input())
    print((h[n] + inv[n] - 1) % mod)


MT = int(input())
for _ in range(MT):
    soviet()
