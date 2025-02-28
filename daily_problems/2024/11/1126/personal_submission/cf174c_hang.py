def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.append(0)
    for i in range(n, 0, -1):
        a[i] -= a[i - 1]
    l = []
    r = []
    for i in range(n + 1):
        if a[i] > 0:
            l.extend(i + 1 for _ in range(a[i]))
        elif a[i] < 0:
            r.extend(i for _ in range(-a[i]))
    print(len(l))
    for i in range(len(l)):
        print(l[i], r[i])
main()