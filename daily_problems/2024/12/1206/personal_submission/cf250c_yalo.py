n, k = map(int, input().split())
genres = list(map(int, input().split()))

min_stress = float('inf')
ans_genre = 0
for exclude_genre in range(1, k + 1):
    stress = 0
    prev_genre = None
    temp_genres = [g for g in genres if g!= exclude_genre]
    for g in temp_genres:
        if prev_genre is None:
            prev_genre = g
            continue
        if g!= prev_genre:
            stress += 1
            prev_genre = g
    if stress < min_stress:
        min_stress = stress
        ans_genre = exclude_genre
    elif stress == min_stress:
        ans_genre = min(ans_genre, exclude_genre)
print(ans_genre)
    
