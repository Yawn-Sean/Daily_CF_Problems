mod = 10 ** 9 + 7
N = 200005

fact = [0] * N
infact = [0] * N
fact[1] = infact[1] = 1

for i in range(2, N):
    fact[i] = fact[i - 1] * i % mod
infact[N - 1] = pow(fact[N - 1], mod - 2, mod)
for i in range(N - 2, 1, -1):
    infact[i] = infact[i + 1] * (i + 1) % mod


outs = []
def soviet():
    n, k = map(int, input().split())

    arr = [0] + sorted(list(map(int, input().split()))) + [n]

    ans = fact[n]

    for i in range(len(arr)):
        if i and arr[i] > arr[i - 1] + 1:
            ans = ans * infact[arr[i] - arr[i - 1]] % mod

    outs.append(ans)


MT = int(input())
for _ in range(MT):
    soviet()
print('\n'.join(map(str, outs)))
