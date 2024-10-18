def main():
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    def check(s1, s2):
        xl = min(s2[i] for i in range(0,8,2))
        xr = max(s2[i] for i in range(0,8,2))
        yl = min(s2[i] for i in range(1,8,2))
        yr = max(s2[i] for i in range(1,8,2))
        for i in range(4):
            if xl <= s1[i * 2] <= xr and yl <= s1[i * 2 + 1] <= yr:
                return True
        if xl * 2 <= s1[0] + s1[4] <= xr * 2 and yl * 2 <= s1[1] + s1[5] <= yr * 2:
            return True
        return False
    if check(b,a):
        print("YES")
    else:
        for i in range(4):
            a[i * 2], a[i * 2 + 1] = a[i * 2] + a[i * 2 + 1], a[i * 2] - a[i * 2 + 1]
            b[i * 2], b[i * 2 + 1] = b[i * 2] + b[i * 2 + 1], b[i * 2] - b[i * 2 + 1]
        if check(a,b):
            print("YES")
        else:
            print("NO")
main()