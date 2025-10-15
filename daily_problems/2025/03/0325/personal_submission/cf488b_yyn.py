def main():
    n = II()
    arr = []
    for i in range(n):
        arr.append(II())
    arr.sort()
    if n == 0:
        print("YES\n1\n1\n3\n3")
    elif n == 1:
        x = arr[0]
        print(f"YES\n{x}\n{3*x}\n{3*x}")
    elif n == 2:
        [x,y] = arr
        if 3 * x >= y:
            print(f"YES\n{4 * x - y}\n{3 * x}")
        else:
            print("NO")
    elif n == 3:
        [x,y,z] = arr
        if z == 3 * x:
            print(f"YES\n{x + z - y}")
        elif 3 * x >= z and y + z == 4 * x:
            print(f"YES\n{3 * x}")
        elif z % 3 == 0 and x + y == z // 3 * 4:
            print(f"YES\n{z // 3}")
        else:
            print("NO")
    else:
        [x,y,z,d] = arr
        if x * 3 == d and y + z == x + d:
            print("YES")
        else:
            print("NO")

