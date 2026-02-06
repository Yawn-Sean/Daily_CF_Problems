fin = open("dotak.in", "r")

t = int(fin.readline())
for _ in range(t):
    n, k = map(int, fin.readline().split())
    v = (n * k) % (k + 1)
    if (v & 1) or (v == k):
        print("Omda")
    else:
        print("Teemo")
