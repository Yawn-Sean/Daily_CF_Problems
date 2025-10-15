
def main():
    l,r = map(int, input().split())
    p = 10 ** len(str(r)) - 1
    mid = p // 2
    if l > mid:
        print(l * (p - l))
    elif r < mid:
        print(r * (p - r))
    else:
        print(mid * (p - mid))



main()