def main():
    n = int(input())
    g = []
    ans = []
    for _ in range(n):
        x = int(input())
        if x == 1:
            g.append(1)
        else:
            while g[-1] != x - 1:
                g.pop()
            g[-1] = x
        ans.append('.'.join(map(str, g)))
    print('\n'.join(ans))
    

t = int(input())
for _ in range(t):
    main()