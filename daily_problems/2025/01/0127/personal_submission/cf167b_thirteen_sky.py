def main():
    import sys
    from collections import defaultdict

    input = sys.stdin.read().split()
    n = int(input[0])
    l = int(input[1])
    k = int(input[2])
    p = list(map(int, input[3:3+n]))
    a = list(map(int, input[3+n:3+2*n]))

    sorted_tours = sorted(zip(p, a), key=lambda x: (0, -x[1]) if x[1] != -1 else (1, 0))
    p_sorted = [x[0] for x in sorted_tours]
    a_sorted = [x[1] for x in sorted_tours]

    prev_dp = defaultdict(float)
    r_initial = n  
    initial_d = k

    if initial_d > r_initial:
        initial_d = r_initial
    elif initial_d < -200:
        initial_d = -200
    prev_dp[(0, initial_d)] = 1.0

    for i in range(n):
        curr_dp = defaultdict(float)
        current_p = p_sorted[i]
        current_a = a_sorted[i]
        r_next = n - (i + 1)  

        for (j, d) in prev_dp:
            prob = prev_dp[(j, d)]
            if prob == 0:
                continue

            lose_prob = (100 - current_p) / 100.0
            new_j = j
            new_d = d
            if new_d > r_next:
                new_d = r_next
            elif new_d < -200:
                new_d = -200
            curr_dp[(new_j, new_d)] += prob * lose_prob

            win_prob = current_p / 100.0
            new_j_win = j + 1
            if current_a == -1:
                new_d_win = d - 1
            else:
                new_d_win = d + current_a
            if new_d_win > r_next:
                new_d_win = r_next
            elif new_d_win < -200:
                new_d_win = -200
            curr_dp[(new_j_win, new_d_win)] += prob * win_prob

        prev_dp = curr_dp

    result = 0.0
    for (j, d) in prev_dp:
        if j >= l and d >= 0:
            result += prev_dp[(j, d)]
    
    print("{0:.12f}".format(result))

if __name__ == "__main__":
    main()
