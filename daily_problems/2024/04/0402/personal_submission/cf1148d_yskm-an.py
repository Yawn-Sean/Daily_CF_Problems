n = int(input())
arr = []
brr = []
for i in range(n):
    a, b = map(int, input().split())
    if a < b:
        arr.append((a, b, i + 1))
    else:
        brr.append((a, b, i + 1))
arr.sort(key=lambda x: x[1], reverse=True)
brr.sort(key=lambda x: x[1])
if len(arr) >= len(brr):
    print(len(arr))
    for a, b, c in arr:
        print(c, end = ' ')
else:
    print(len(brr))
    for a, b, c in brr:
        print(c, end = ' ')
