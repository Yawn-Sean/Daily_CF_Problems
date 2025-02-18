def main():
    x,y = map(int, input().split())
    a,b = y,y
    ans = 0
    while a < x:
        a,b = a+b - 1, a
        ans += 1
    print(ans + 2)
    

main()