

from itertools import permutations
def main():
    def q(s):
        print(s,flush=True)
        x,y = map(int,input().split())
        if x == 4:
            exit()
        return x,y
    pe = []
    for i in range(10):
        x,y = q(str(i) * 4)
        if x:
            pe.append(str(i))
    for v in permutations(pe,4):
        x,y = q(''.join(v))


main()