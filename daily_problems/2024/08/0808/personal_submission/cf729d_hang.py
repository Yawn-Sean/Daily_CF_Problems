def main():
    n,a,b,k = map(int,input().split())
    s = input()
    z = []
    cnt = 0
    for i,x in enumerate(s):
        if x == '0':
            cnt += 1
            if cnt == b:
                z.append(i)
                cnt = 0
        else:
            cnt = 0
    for i in range(a - 1):
        z.pop()
    print(len(z))
    z = [i + 1 for i in z]
    print(*z)
main()