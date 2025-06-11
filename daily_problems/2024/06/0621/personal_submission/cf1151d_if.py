n = int(input())
arr = []
for i in range(n):
    s = list(map(int, input().split()))
    arr += [[s[0],s[1],s[0]-s[1]]]
arr = sorted(arr, key = lambda x : x[2], reverse = True)
ans = 0
for i in range(n):
    ans += (i+1)*arr[i][2] - arr[i][0] + arr[i][1]*n
print(ans)
