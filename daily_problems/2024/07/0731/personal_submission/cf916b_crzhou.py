
def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    n = int(data[0])
    k = int(data[1])
    
    nn = []
    for i in range(61, -1, -1):
        if n >> i & 1:
            nn.append(i)
    
    for i in range(-61, 62):
        ans = []
        flg = False
        for j in nn:
            if j > i:
                if (1 << (j - i)) > k:
                    flg = True
                    break
                for _ in range(1 << (j - i)):
                    ans.append(i)
            else:
                ans.append(j)
            if len(ans) > k:
                flg = True
                break
        if flg:
            continue
        while len(ans) < k:
            x = ans.pop()
            ans.append(x - 1)
            ans.append(x - 1)
        print("Yes")
        print(" ".join(map(str, ans)))
        return
    
    print("No")

if __name__ == "__main__":
    main()
