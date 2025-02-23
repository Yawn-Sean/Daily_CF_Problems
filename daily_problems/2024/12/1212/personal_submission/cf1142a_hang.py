import math
def main():
    n,k = map(int,input().split())
    a,b = map(int,input().split())
    v = n * k
    c, d = n * k, 0
    for i in range(n):
        x = i * k + a - b
        res = v // math.gcd(v, x)
        if res < c: 
            c = res
        if res > d: 
            d = res
        x = i * k + a + b
        res = v // math.gcd(v, x)
        if res < c: 
            c = res
        if res > d: 
            d = res

    print(c, d)

main()