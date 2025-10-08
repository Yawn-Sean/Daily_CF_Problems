t = ix()
for i in range(t):
    a, b = il()
    if a & b != b:
        print(-1)
    else:
        if a.bit_count() == 1:
            if b == 0:
                print(-1)
            else:
                print(2)
                print(0, b)
        else:
            ans = [0] + [x for x in range(1, a + 1)  if x & a == x and x != b ]
            print(len(ans))
            print(*ans)
