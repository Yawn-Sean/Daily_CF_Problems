def main():
    n = int(input())
    f = [0] * n
    for i in range(n):
        s = input()
        for j in range(n):
            if s[j] == '1':
                f[(i - j) % n] += 1
    print(sum(f) + n - max(f) * 2)
     

t = int(input())
for _ in range(t):
    c = input()
    main()

