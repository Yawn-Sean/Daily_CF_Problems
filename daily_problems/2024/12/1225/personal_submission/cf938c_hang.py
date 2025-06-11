def main():
    x = int(input())
    if x == 0:
        print(1, 1)
        return
    for i in range(1,x):
        if i * i >= x:
            break
        if x % i == 0:
            a, b = x // i, i
            n = (a + b) // 2
            m = (a + b) // (a - b)
            if n * n - (n // m) * (n // m) == x:
                print(n, m)
                return
    print(-1)
t = int(input())
for _ in range(t):
    main()