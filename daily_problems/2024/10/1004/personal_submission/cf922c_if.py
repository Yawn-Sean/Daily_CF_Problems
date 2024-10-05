def check():
    global k, n
    for i in range(1, k  + 1):
        if n % i != i - 1:
            
            return "NO"
    return "YES"
n, k = map(int, input().split())
if k > 43:
    print("NO")
else:
    print(check())
