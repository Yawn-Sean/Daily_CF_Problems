def main():
    # 实际上求b增大多少次达到x(c-a)
    a,b,w,x,c = map(int, input().split())
    if c <= a: 
        print(0)
    else: 
        print(((c - a) * w - b + w - x - 1) // (w - x))


main()