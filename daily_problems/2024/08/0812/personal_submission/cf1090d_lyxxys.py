from collections import Counter

def main():
    n, m = map(int, input().split())

    din = [0] * (n+1)
    mp = Counter()

    while m != 0:
        m -= 1
        a, b = map(int, input().split())
        if a > b:
            a, b = b, a
        if mp.get((a, b)) != None:
            continue
        din[a] += 1
        din[b] += 1
        mp[(a, b)] += 1

    p = -1
    for i in range(1, n+1):
        if din[i] < n-1:
            p = i
            break

    if p == -1:
        print("NO\n")
        return

    nums1 = [0 for _ in range(n+1)]
    nums2 = [0 for _ in range(n+1)]

    aim = -1
    for i in range(1, p):
        if mp.get((i,p)) == None:
            aim = i
            break
    if aim == -1:
        for i in range(p+1, n+1):
            if mp.get((p,i)) == None:
                aim = i
                break

    nums1[p], nums1[aim] = 1, 2
    nums2[p] = nums2[aim] = 1
    tot = 2
    for i in range(1, n+1):
        if i == p or i == aim:
            continue
        tot += 1
        nums1[i] = nums2[i] = tot

    print("YES")
    for i in range(1, n+1):
        print(nums1[i], end = ' ')
    print()
    for i in range(1, n+1):
        print(nums2[i], end = ' ')
    print()

if __name__ == '__main__':
    _ = 1
    while _ != 0:
        _ -= 1
        main()
