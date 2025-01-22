def main():
    n = int(input())
    a = list(map(int, input().split()))
    s = input()
    tot = sum(a)
    ans = 0
    for i in range(n - 1, - 1, -1):
        tot -= a[i]
        if s[i] == '1':
            ans = max(ans, tot)
            tot += a[i]
    print(max(ans, tot))


main()