def solve():
    a, b = MII()
    mul = a * b
    low = 1
    high = 10 ** 6
    while low <= high:
        mid = (low + high) // 2
        if mid ** 3 > mul:
            high = mid - 1
        else:
            low = mid + 1
    found = False
    if a * b == high ** 3 and a % high == 0 and b % high == 0:
        found = True
    if found == True:
        print("Yes")
    else:
        print("No")

def solve():
    n, s = MII()
    a = [0] * n
    for i in range(n - 1):
        u, v = GMI()
        a[u] += 1
        a[v] += 1
    print(2 * s / a.count(1))
def main():
    t = 1
    while t:
        solve()
        t -= 1
main()