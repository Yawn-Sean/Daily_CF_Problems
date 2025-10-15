def main():
    n = int(input())
    A = list(map(int, input().split()))

    vis = [0]*(n)
    i = 0
    while i < n-1:
        while i < n-1 and A[i] == A[i+1]:
            vis[i] = vis[i+1] = 1
            i += 1
        else: i += 1

    res = 0

    i = 1
    while i < n-1:
        if vis[i]:
            i += 1
            continue
        j = i
        while j < n-1 and not vis[j]:
            j += 1
        record = j
        j -= 1
        res = max(res, (j-i+2) // 2)
        x, y = A[i-1], A[j+1]
        while i <= j:
            A[i] = x
            A[j] = y
            i += 1
            j -= 1
        i = record

    print(res)
    print(*A)
