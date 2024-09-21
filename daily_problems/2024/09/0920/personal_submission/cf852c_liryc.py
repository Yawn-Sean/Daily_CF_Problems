'''
852C
2024/9/20 Y2
ref
'''
if __name__ == '__main__':
    n = int(input())
    pts = list(map(int, input().split()))

    st_range = sorted(range(n), key=lambda x: pts[(x + 1) % n] + pts[x])
    ans = [-1] * n

    for i in range(n):
        ans[st_range[i]] = i

    print(' '.join(map(str, ans)))