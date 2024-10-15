import math
inf = float("inf")
fir = inf

x, y, n = map(int, input().split())

t = math.gcd(x, y)

while t != 1:
    x //= t
    y //= t
    t = math.gcd(x, y)

tar = x / y

if y <= n:
    print(str(x) + "/" + str(y))
else:
    for y in range(n, 0, -1):
        cur_x = y * tar
        if round(abs(math.ceil(cur_x) / y - tar), 15) <= fir:
            fir = round(abs(math.ceil(cur_x) / y - tar), 15)
            new_x = math.ceil(cur_x)
            new_y = y
        if round(abs(math.floor(cur_x) / y - tar), 15) <= fir:
            fir = round(abs(math.floor(cur_x) / y - tar), 15)
            new_x = math.floor(cur_x)
            new_y = y
            
    print(str(new_x) + "/" + str(new_y))
    
