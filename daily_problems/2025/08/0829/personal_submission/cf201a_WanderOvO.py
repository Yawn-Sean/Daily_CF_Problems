x = int(input())

if x == 1:
    print(1)
elif x == 2:
    print(3)
elif x == 3:
    print(5)
else:
    for i in range(3, 100, 2):
        if (i * i + 1) // 2 >= x:
            print(i)
            exit(0)
    print(-1)
