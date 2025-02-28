
def main():
    n = int(input())
    a = list(map(int, input().split()))
    neg = []
    pos = []
    zero = []
    for i,x in enumerate(a):
        if x < 0:
            neg.append(i)
        elif x > 0:
            pos.append(i)
        else:
            zero.append(i)
    neg.sort(key=lambda x: -a[x])

    while len(neg) > 1:
        i,j = neg.pop(), neg.pop()
        print(1,i+1,j+1)
        pos.append(j)
    while len(pos) > 1:
        i,j = pos.pop(), pos.pop()
        print(1,i+1,j+1)
        pos.append(j)
    while len(zero) > 1:
        i,j = zero.pop(), zero.pop()
        print(1,i+1,j+1)
        zero.append(j)
    if len(neg) == 0:
        if len(zero) and len(pos):
            print(2, zero.pop()+1)
    else:
        if len(zero):
            j = zero.pop()
            print(1, neg.pop()+1, j+1)
            if len(pos):
                print(2,j+1)
        else:
            print(2, neg.pop()+1)





main()