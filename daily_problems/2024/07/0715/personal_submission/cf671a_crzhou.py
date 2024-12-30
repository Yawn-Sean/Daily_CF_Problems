def main():
    ax, ay, bx, by, tx, ty = map(int, input().split())

    def d(x1, y1, x2, y2):
        return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

    ans = 0
    maxa = maxb = maxab = -float('inf')
    
    n = int(input())
    for _ in range(n):
        x, y = map(int, input().split())
        to_bin = d(x, y, tx, ty)
        to_adil = d(x, y, ax, ay)
        to_bera = d(x, y, bx, by)
        
        ans += 2 * to_bin
        maxa, maxb, maxab = max(maxa, to_bin - to_adil), max(maxb, to_bin - to_bera), max(maxab, maxa + to_bin - to_bera, maxb + to_bin - to_adil)

    print(ans - max(maxa, maxb, maxab))

if __name__ == "__main__":
    main()
