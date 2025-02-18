def query(x, y):
    print(x, y, flush=True)
    color = input()
    return color == 'black'

n = int(input())
l, r = 0, 10 ** 9 
init = query(r, r)
for _ in range(n - 1):
    x = l + r >> 1   
    if query(x, x) == init: 
        r = x
    else:
        l = x
print(l, r, r, l)
