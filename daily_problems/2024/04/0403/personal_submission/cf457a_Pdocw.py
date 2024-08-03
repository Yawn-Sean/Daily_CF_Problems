# A. Golden System
def main():
    a = I()
    b = I()
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)
    x, y = 0, 0
    for i in range(n):
        # x 和 y kq + b 的 k 和 b
        x, y = x + y, x + int(a[i]) - int(b[i])
        # print(x, y)
        if x > 1:
            print(">")
            return
        if x < -1:
            print("<")
            return
    if x == y == 0:
        print("=")
        return
    while abs(x) < 2:
        x, y = x + y, x
    print(">" if x > 0 else "<")
    return
