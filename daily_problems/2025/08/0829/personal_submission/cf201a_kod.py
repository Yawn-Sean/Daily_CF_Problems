x = ix()
if x == 3: exit(print(5))
for n in range(1,101,2):
    if n * n + 1 >= 2 * x:
        print(n)
        break
