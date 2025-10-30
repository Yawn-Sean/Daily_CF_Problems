n, m = il()
x = []
y = []
for i in range(1, m + 1):
    a, b = il()
    if a < b:
        x += i,
    else:
        y += i,
print('YES')
if len(x) > len(y):
    print(len(x))
    print(*x)
else:
    print(len(y))
    print(*y)
