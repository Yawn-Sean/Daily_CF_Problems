import math
def is_prime(x):
    for i in range(2, x):
        if i * i > x: break
        if x % i == 0: return False
    return True
def main():
    n = int(input())
    l = n
    while not is_prime(l): l -= 1
    r = n + 1
    while not is_prime(r): r += 1
    a = r * l - 2 * r + 2 * (n - l + 1)
    b = 2 * r * l
    g = math.gcd(a, b)
    a //= g
    b //= g
    print(f'{a}/{b}')
t = int(input())
for _ in range(t):
    main()