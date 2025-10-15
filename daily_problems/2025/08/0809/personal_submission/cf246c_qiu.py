def solve():
    import sys

    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort(reverse=True)

    for i in range(n):
        for j in range(i, n):
            print(i + 1, end=" ")
            for x in range(i):
                print(a[x], end=" ")
            print(a[j])
            k -= 1
            if k == 0:
                return


if __name__ == "__main__":
    solve()
