t = ix()
for i in range(t):
    a, b, n = il()
    if n > a + 2 * (2 * b - 1):
        print('Bob')
    elif a + 2* (b - 1) < n < 3 * a:
        print('Bob')
    else:
        print('Alice')
