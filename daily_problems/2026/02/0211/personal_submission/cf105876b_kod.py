n = ix()
if n % 4 == 3: print(-1)
else:    print(*[i + 1 if i % 4 == 3 else i - 1 if i % 4 == 0 else i for i in range(1, n + 1)])
