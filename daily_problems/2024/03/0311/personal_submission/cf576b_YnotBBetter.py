def main():
    n = int(input())
    perm = list(map(int, input().split()))

    seen = [False] * n
    circles = []
    starter = []
    meet_odd = False
    for i in range(n):
        if seen[i]:
            continue
        tmp = []
        while not seen[i]:
            tmp.append(i)
            seen[i] = True
            i = perm[i] - 1

        if len(tmp) == 1:
            print("YES")
            for j in range(n):
                if i != j:
                    print(i+1, j+1)
            return

        if len(tmp) & 1:
            meet_odd = True

        if len(tmp) == 2:
            starter = tmp

        circles.append(tmp)

    if meet_odd or not starter:
        print("NO")
        return

    print("YES")
    print(starter[0]+1, starter[1]+1)
    for c in circles:
        if c[0] == starter[0]:
            continue
        for i, node in enumerate(c):
            print(starter[i & 1]+1, node+1)


main()
