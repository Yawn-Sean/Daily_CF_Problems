n = int(input())
res = 1
for i in range(n):
    res *= i // 2 + 1

print(res)
