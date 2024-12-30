def main():
    n,m,k = map(int, input().split())
    alice = list(map(int, input().split()))
    bob = list(map(int, input().split()))
    alice.sort(reverse=True)
    bob.sort(reverse=True)
    if n > m:
        print("YES")
        return
    for i in range(n):
        if alice[i] > bob[i]:
            print("YES")
            return
    print("NO")
main()