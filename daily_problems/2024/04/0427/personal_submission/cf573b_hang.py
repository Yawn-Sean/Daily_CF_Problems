def main():
    n = int(input())
    h = list(map(int, input().split()))
    h[0] = h[-1] = 1
    for i in range(1, n):
        if h[i] > h[i-1]:
            h[i] = h[i-1] + 1
    for i in range(n - 2, 0, -1):
        if h[i] > h[i + 1]:
            h[i] = h[i + 1] + 1

    print(max(h))
main()