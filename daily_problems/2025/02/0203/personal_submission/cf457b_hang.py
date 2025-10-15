def main():
    m,n = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    sum1 = sum(a)
    sum2 = sum(b)
    res1 = 0
    for x in a:
        res1 += min(x, sum2)
    res1 += sum2 - min(max(a), sum2)
    res2 = 0
    for x in b:
        res2 += min(x, sum1)
    res2 += sum1 - min(max(b), sum1)
    print(min(res1, res2))


main()