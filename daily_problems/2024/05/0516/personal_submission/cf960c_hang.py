def main():
    x,d = map(int,input().split())
    t = -1
    a = []
    b = 1
    while x:
        t += 1
        c = pow(2,t)
        if x >= c:
            x -= c
            a.append(b)
        else:
            t = -1
            b += d
    print(len(a))
    print(*a)

if __name__ == '__main__':
    main()