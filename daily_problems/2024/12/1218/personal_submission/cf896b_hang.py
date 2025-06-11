def main():
    n,m,c = map(int, input().split())
    mid = c // 2
    ans = [-1] * n
    n_v = n

    while n_v:
        v = int(input())
        if v <= mid:
            for i in range(n):
                if ans[i] == -1 or ans[i] > v:
                    print(i+1,flush=True)
                    if ans[i] == -1: n_v -= 1
                    ans[i] = v
                    break
        else:
            for i in range(n-1,-1,-1):
                if ans[i] == -1 or ans[i] < v:
                    print(i+1,flush=True)
                    if ans[i] == -1: n_v -= 1
                    ans[i] = v
                    break
    
main()