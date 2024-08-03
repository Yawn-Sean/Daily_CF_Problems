# problem link:https://codeforces.com/problemset/problem/1903/E
# submission link: https://codeforces.com/contest/1903/submission/256181438 
def solve():
    n = int(input())
    points = [map(int, input().split()) for _ in range(n + 1)]
    first_p_even_odd = sum(points[0]) % 2
    same_as_first_idxes = []
    diff_as_first_idxes = []
    for i in range(1, n + 1):
        if sum(points[i]) % 2 == first_p_even_odd:
            same_as_first_idxes.append(i)
        else:
            diff_as_first_idxes.append(i)
    used = [False] * (n + 1)

    def lazy_delete():
        while same_as_first_idxes and used[same_as_first_idxes[-1]]:
            same_as_first_idxes.pop()
        while diff_as_first_idxes and used[diff_as_first_idxes[-1]]:
            diff_as_first_idxes.pop()

    if len(same_as_first_idxes) >= len(diff_as_first_idxes):
        print("First")
        for i in range(1, n + 1):
            if i % 2 == 0:
                other_side_idx = int(input())
                used[other_side_idx] = True
                continue
            lazy_delete()
            if diff_as_first_idxes:
                print(diff_as_first_idxes.pop(), flush=True)
            else:
                print(same_as_first_idxes.pop(), flush=True)
    else:
        print("Second")
        for i in range(1, n + 1):
            if i % 2 == 1:
                other_side_idx = int(input())
                used[other_side_idx] = True
                continue
            lazy_delete()
            if same_as_first_idxes:
                print(same_as_first_idxes.pop(), flush=True)
            else:
                print(diff_as_first_idxes.pop(), flush=True)


t = int(input())
for _ in range(t):
    solve()
