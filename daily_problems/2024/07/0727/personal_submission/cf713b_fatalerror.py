n = int(input())

def query(*coords):
    print('?', *coords, flush=True)
    return int(input())

def hor_split():
    t, b = 1, n
    while t < b:
        mid = (t + b) // 2
        if query(1, 1, mid, n):
            b = mid
        else:
            t = mid + 1
    if b < n and query(b+1, 1, n, n):
        return (1, 1, b, n), (b+1, 1, n, n)
    return None, None

def ver_split():
    l, r = 1, n
    while l < r:
        mid = (l + r) // 2
        if query(1, 1, n, mid):
            r = mid
        else:
            l = mid + 1
    if r < n and query(1, r+1, n, n):
        return (1, 1, n, r), (1, r+1, n, n)
    return None, None

def find_rect(top, left, bottom, right):
    t, b = top, bottom
    while t < b:
        mid = (t + b + 1) // 2
        if query(mid, left, bottom, right):
            t = mid
        else:
            b = mid - 1
    top = t

    t, b = top, bottom
    while t < b:
        mid = (t + b) // 2
        if query(top, left, mid, right):
            b = mid
        else:
            t = mid + 1
    bottom = b

    l, r = left, right
    while l < r:
        mid = (l + r + 1) // 2
        if query(top, mid, bottom, right):
            l = mid
        else:
            r = mid - 1
    left = l

    l, r = left, right
    while l < r:
        mid = (l + r) // 2
        if query(top, left, bottom, mid):
            r = mid
        else:
            l = mid + 1
    right = r

    return top, left, bottom, right


area1, area2 = hor_split()
if not area1:
    area1, area2 = ver_split()
print('!', *find_rect(*area1), *find_rect(*area2), flush=True)
