def main():
    n,k = map(int,input().split())
    if n >k * (k - 1):
        print("NO")
        return
    print("YES")
    ans = []
    for i in range(1, k + 1):
        for j in range(1 , i):
            ans.append(f'{i} {j}')
            ans.append(f'{j} {i}')
            if len(ans) >= n:
                print("\n".join(ans[:n]))
                return
    

main()