def main():
    b1,q,l,m = map(int, input().split())
    a = set(list(map(int, input().split())))
    if b1 == 0 or q == 0:
        if abs(b1) <= l and 0 not in a:
            print('inf')
            return
        if abs(b1) <= l and  b1 not in a:
            print('1')
            return
        print(0)
        return
    if q == 1:
        if abs(b1) <= l and b1 not in a:
            print('inf')
            return
        else:
            print(0)
            return
    if q == -1:
        if abs(b1) <= l and (b1 not in a or -b1 not in a):
            print('inf')
            return
        else:
            print(0)
            return
    ans = 0
    while abs(b1) <= l:
        if b1 not in a:
            ans += 1
        b1 *= q
    print(ans)
main()