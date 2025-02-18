def main():
    k = int(input())
    if k & 1:
        print(-1)
        return
    z = []
    u = []
    for _ in range(k// 2):
        z.append(''.join( 'ww' if i % 2 == 0 else 'bb' for i in range(k // 2)))
        z.append(''.join( 'bb' if i % 2 == 0 else 'ww' for i in range(k // 2)))

        u.append(''.join( 'bb' if i % 2 == 0 else 'ww' for i in range(k // 2)))
        u.append(''.join( 'ww' if i % 2 == 0 else 'bb' for i in range(k // 2)))
    for i in range(k // 2):
        if i % 2 == 0:
            print('\n'.join(z))
            print()
            print('\n'.join(z))
        else:
            print('\n'.join(u))
            print()
            print('\n'.join(u))
        print()
main()