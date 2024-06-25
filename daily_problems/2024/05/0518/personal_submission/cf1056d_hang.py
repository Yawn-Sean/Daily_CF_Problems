
def main():
    n = int(input())
    p = [-1] + list(map(lambda x : int(x) - 1, input().split()))
    r = [1] * n

    for i in range(1, n):
        r[p[i]] = 0

    for i in range(n - 1, 0, -1):
        r[p[i]] += r[i]

    r.sort()
    print(*r)
main()