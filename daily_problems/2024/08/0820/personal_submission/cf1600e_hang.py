def main():
    n = int(input())
    a = list(map(int, input().split()))
    l = 0
    while l < n - 1 and a[l+1] > a[l]:
        l += 1
    r = n - 1
    while r > 0 and a[r-1] > a[r]:
        r -= 1
    print('Alice' if ((l + 1) | (n - r)) & 1 else 'Bob')


main()