def main():
    x = int(input())
    ans = []

    for j in range(1, 2*10 **6 + 1):
        a = j * (j + 1) * (2 * j + 1) // 6
        b = j * (j + 1) // 2
        if x >= a and (x - a) % b == 0:
            w, h = j, j + (x - a) // b
            ans.append((w, h))
            if w != h:
                ans.append((h, w))

    ans.sort()
    print(len(ans))
    for x,y in ans:
        print(x, y)
main()