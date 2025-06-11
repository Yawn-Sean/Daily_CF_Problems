def main():
    x1, y1, x2, y2 = map(int, input().split())
    x = x2 - x1 + 1
    y = y2 - y1 + 1
    print(((x + 1) // 2) * ((y + 1) // 2) + ((x - 1) // 2) * ((y - 1) // 2))

main()