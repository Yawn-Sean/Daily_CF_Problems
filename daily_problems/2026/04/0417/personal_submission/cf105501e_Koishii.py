n, m = map(int, input().split())
a = input()

for i in range(n):
    b = input()
    if a in b + ' ' + b:
        exit(print(i + 1))

print(-1)
