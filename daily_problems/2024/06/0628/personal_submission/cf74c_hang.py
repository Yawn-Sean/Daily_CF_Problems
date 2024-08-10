from math import gcd
def  main():
    n,m = map(int,input().split())
    print(gcd(n-1,m-1) + 1)
main()