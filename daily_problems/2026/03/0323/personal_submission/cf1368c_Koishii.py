n = int(input())
print(12 + n * 3)

print(0, 0)
print(0, 1)
print(0, 2)
print(1, 0)
print(2, 0)

for i in range(2, 2 + n):
    print(i, i)
    print(i, i - 1)
    print(i - 1, i)

x = n + 1
print(x, x + 1)
print(x, x + 2)
print(x + 1, x)
print(x + 1, x + 2)
print(x + 2, x)
print(x + 2, x + 1)
print(x + 2, x + 2)

