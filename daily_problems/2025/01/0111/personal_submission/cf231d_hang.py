def main():
    x,y,z = map(int, input().split())
    x1,y1,z1 = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    ans = 0
    if y < 0: 
        ans += a[0]
    if y > y1: 
        ans += a[1]
    if z < 0: 
        ans += a[2]
    if z > z1: 
        ans += a[3]
    if x < 0: 
        ans += a[4]
    if x > x1: 
        ans += a[5]
    print(ans)

main()