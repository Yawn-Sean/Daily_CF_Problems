def main():
    A,B,n = map(int,input().split())
    g = []
    for _ in range(n):
        l,t,m = map(int,input().split())
        al = A + B * (l - 1)
        if t < al:
            g.append(-1)
        else:
            left = l
            right = t
            while left < right:
                mid = (left + right + 1) // 2
                ar = A + B * (mid - 1)
                tot = (al + ar) * (mid - l + 1) // 2
                if ar > t or tot > t * m:
                    right = mid - 1
                else:
                    left = mid
            g.append(left)
    print(*g,sep='\n')



if __name__ == '__main__':
    main()