def main():
    n = int(input())
    arr = [0] + list(map(int, input().split(" ")))
    ret = [0] * (n + 1)
    w = 0
    for i in range(1, n + 1):
        w = min(w, arr[i] - i)
        ret[i] = i + w
    w = n + 1
    for i in range(n, 0, -1):
        w = min(w, arr[i] + i)
        ret[i] = min(ret[i], w - i)

    ans = max(ret[1:])
    print(ans)

main()
