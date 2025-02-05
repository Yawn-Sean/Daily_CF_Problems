def main():
    N,D,S = map(int, input().split())
    N //= S
    D //= S

    if N <= D + 1:
        print(N * S)
        
    else:
        N = min(N, 2 * D)
        for i in range(2, 10 ** 6 + 1):
            if N % i == 0 and N - N // i <= D:
                print(N * S)
                return
        print((N - 1) * S)
    

main()