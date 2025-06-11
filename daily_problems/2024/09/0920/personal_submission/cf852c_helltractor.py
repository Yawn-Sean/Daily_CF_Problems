# s = sum(b[i] * (n - a[i] - a[(i + 1) % n]) for i in range(n))
def CF852C():
    n = II()
    a = LII()
    tmp = [(n - a[i] - a[(i + 1) % n], i) for i in range(n)]
    tmp.sort(reverse=True)
    b = [0] * n
    for i in range(n):
        b[tmp[i][1]] = i
    print(' '.join(map(str, b)))
