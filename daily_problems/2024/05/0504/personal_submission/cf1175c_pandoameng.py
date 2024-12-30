# submission: https://codeforces.com/problemset/submission/1175/259486658
def main():
    nn = II()
    out = []
    for _ in range(nn):
        n, k = LII()
        arr = LII()
        s = inf
        ans = (arr[k] + arr[0]) // 2
        for i in range(k, n):
            new_s = arr[i] - arr[i - k]
            if new_s < s:
                s = new_s
                ans = (arr[i] + arr[i - k]) // 2
        out.append(ans)
        
    print(*out, sep='\n') 

main()