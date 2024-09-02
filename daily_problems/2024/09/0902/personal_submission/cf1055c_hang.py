# 裴蜀定理 
import math
def main():
    la,ra,ta = map(int,input().split())
    lb,rb,tb = map(int,input().split())
    a = ra - la + 1
    b = rb - lb + 1

    g = math.gcd(ta, tb)
    x = la - lb
    x %= g
    print(max(0, min(x + a, b) - x, min(x - g + a, b)))

main()