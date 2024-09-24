n = int(input())
a = list(map(int, input().split()))

m = 2 * 10 ** 5
acc = [0] * (m + 2)

for x in a:
  acc[x + 1] += 1

for i in range(m + 1):
  acc[i + 1] += acc[i]

res = [0] * (m + 1)

for i in range(1, m + 1):
  for j in range(0, m + 1, i):
    res[i] += j * (acc[min(m + 1, j + i)] - acc[j])

print(max(res[x] for x in a))
