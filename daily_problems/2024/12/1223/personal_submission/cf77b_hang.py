def main():
    a,b = map(int,input().split())
    if b == 0:
        print(1)
    elif a == 0:
        print(0.5)
    elif a < 4 * b:
        print(0.5 + a / 16 / b)
    else:
        print(1 - b / a)

t = int(input())
for _ in range(t):
    main()