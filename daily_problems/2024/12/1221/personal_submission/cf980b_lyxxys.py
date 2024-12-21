def main():
    n, k = map(int, input().split())
    ans = [['.']*n for _ in range(4)]
    if k%2 == 0:
        for i in range(k//2):
            ans[1][i+1] = ans[2][i+1] = '#'
    else:
        mid = n//2
        ans[1][mid] = '#'
        k -= 1
        for i in range(1, 3):
            j = 1
            while k > 0 and j < mid:
                ans[i][mid-j] = ans[i][mid+j] = '#'
                k -= 2
                j += 1
    print("YES")
    print('\n'.join(''.join(x) for x in ans))
