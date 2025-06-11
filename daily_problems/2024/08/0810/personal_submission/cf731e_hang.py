def main():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(1, n):
        a[i] += a[i - 1]
    for i in range(n - 2, 0, -1):
        a[i] = max(a[i + 1], a[i] - a[i + 1])
    print(a[1])

main()