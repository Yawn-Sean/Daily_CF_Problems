def main():
    n, k = map(int, input().split())

    a,b = divmod(n - 1, k)
    print(2*a + min(b, 2))

    
    for i in range(1, k + 1):
        print(n,i)
    for i in range(k + 1, n):
        print(i-k,i)


main()