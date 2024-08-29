def main():

    n = int(input())
    y = list(map(int, input().split()))
    for i in range(3):
        for j in range(i):
            k = (y[i] - y[j]) * 2 // (i - j)
            used = set()
            for d in range(n):
                used.add(y[d] * 2 - k * d)
                if len(used) > 2:
                    break
            if len(used) == 2:
                print("YES")
                return
    print("NO")
main()
