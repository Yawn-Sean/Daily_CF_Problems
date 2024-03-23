
def query(x1, y1, x2, y2):
    print('?',x1, y1, x2, y2,flush=True)
    return int(input())
def main():
    n = int(input())
    xl,xr = -1,-1
    for i in range(1,n):
        if query(1,1,i,n) % 2:
            if xl == -1: 
                xl = i
            xr = i + 1

    yl, yr = -1, -1
    for i in range(1, n):
        if query(1, 1, n, i) % 2:
            if yl == -1: 
                yl = i
            yr = i + 1
    if xl == -1:
        l, r = 1, n
        while l <= r:
            m = (l + r) // 2
            if query(1, yl, m, yl) % 2:
                r = m - 1
            else:
                l = m + 1
        xl = xr = l
    
    elif yl == -1:
        l, r = 1, n
        while l <= r:
            m = (l + r) // 2
            if query(xl, 1, xl, m) % 2:
                r = m - 1
            else:
                l = m + 1
        yl = yr = l
    
    if query(xl, yl, xl, yl) % 2:
        print('!',xl, yl, xr, yr,flush=True)
    else:
        print('!',xl, yr, xr, yl,flush=True)
main()
