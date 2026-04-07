def II():
    return int(input())
def I():
    return input().strip()
n=II()
while True:
    for i in range(1,n):
        print(i,i+1,flush=True)
        res=I()
        if res =='WIN':
            exit()

    for i in range(n - 1, 0, -1):
        print(i, i + 1, flush=True)
        res = input().strip()
        if res == "WIN":
            exit()
    