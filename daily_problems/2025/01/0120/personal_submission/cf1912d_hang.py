def main():
    b,n = map(int, input().split())
    c = 1
    for i in range(1, n + 1):
        c = c * b % n
        if c == 0:
            print(f'1 {i}')
            break
        if c == 1:
            print(f'2 {i}')
            break
        if c == n - 1:
            print(f'3 {i}')
            break
    else:
        print('0')

t = int(input())
for _ in range(t):
    main()