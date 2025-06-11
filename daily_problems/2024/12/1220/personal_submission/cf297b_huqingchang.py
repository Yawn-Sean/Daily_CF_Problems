def main():
    n, m, k = MII()
    A = LII()
    B = LII()
    if n > m:
        return 'YES'
    A.sort()
    B.sort()
    for i in range(1, n + 1):  # n <= m
        if A[-i] > B[-i]:
            return 'YES'
    return 'NO'


tt = 1
for ii in range(tt):
    print(main())
