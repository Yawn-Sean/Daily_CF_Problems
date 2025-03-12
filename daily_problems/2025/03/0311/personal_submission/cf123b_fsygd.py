[a, b, x1, y1, x2, y2] = list(map(int, input().split(" ")))
print(max(abs((x1 + y1) // (a * 2) - (x2 + y2) // (a * 2)), abs((x1 - y1) // (b * 2) - (x2 - y2) // (b * 2))))