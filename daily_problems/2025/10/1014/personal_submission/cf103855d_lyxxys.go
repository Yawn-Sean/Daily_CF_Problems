func solve(xys [][3]int) int {
	n := len(xys)
	var ans1, ans2 int
	maps, mapY := make(map[int]int), make(map[int][]int)

	pq := MaxHeap{}
	heap.Init(&pq)
	for i, v := range xys {
		maps[v[0]] += v[2]
		mapY[v[1]] = append(mapY[v[1]], i)
	}

	values := make([]int, 0, n)
	for x_dir, v := range maps {
		values = append(values, v)
		heap.Push(&pq, [3]int{v, x_dir, -1}) // [value, x-dir, version]
	}
	sort.Slice(values, func(i, j int) bool {
		return values[i] > values[j]
	})
	for i := 0; i < min(3, len(values)); i++ {
		ans1 += values[i]
	}

	version := -1
	for _, arr := range mapY {
		version += 1
		has_used := make(map[int]int)
		has_pop := make(map[int]bool)

		var v int
		for _, idx := range arr { // 标记该行已选的横坐标
			v += xys[idx][2]
			has_used[xys[idx][0]] = idx
		}
		chose1 := -1
		v1, v2 := 0, 0
		for len(pq) > 0 {
			pop := (heap.Pop(&pq)).([3]int)
			if chose1 == pop[1] { // 选过
				continue
			}
			if pop[2] != -1 && pop[2] < version { // 旧版本
				continue
			}
			has_pop[pop[1]] = true

			if i, exi := has_used[pop[1]]; exi && pop[2] == -1 { // 被标记过，需要更新
				heap.Push(&pq, [3]int{pop[0] - xys[i][2], pop[1], version})
				continue
			}

			if chose1 == -1 {
				v1, chose1 = pop[0], pop[1]
			} else {
				v2 = pop[0]
				break
			}
		}

		for key := range has_pop { // 添回弹出的值
			heap.Push(&pq, [3]int{maps[key], key, -1})
		}

		ans2 = max(ans2, v+v1+v2)
	}

	return max(ans1, ans2)
}

func cf103855d(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	xys := make([][3]int, n)
	for i := range xys {
		fmt.Fscan(in, &xys[i][0], &xys[i][1], &xys[i][2])
	}

	ans1 := solve(xys)
	for i := range xys {
		xys[i][0], xys[i][1] = xys[i][1], xys[i][0]
	}
	ans2 := solve(xys)

	fmt.Fprintln(out, max(ans1, ans2))
}
