def check(mid, mid_):
    print(f"1 {mid} {mid_}")
    sys.stdout.flush()
    s = input().strip()
    return s[0] == 'T'

def bin_search(l, r):
    while l < r:
        mid = (l + r) // 2
        if check(mid, mid + 1):
            r = mid
        else:
            l = mid + 1
    return l

n, k = map(int, input().split())

x = bin_search(1, n)
y = bin_search(1, x - 1)

if x == y or not check(y, x):
    y = bin_search(x + 1, n)

print(f"2 {x} {y}")
sys.stdout.flush()
