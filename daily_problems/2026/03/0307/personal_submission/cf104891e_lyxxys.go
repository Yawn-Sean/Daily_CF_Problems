func main() {
	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var n int
	// 0-index-base
	fmt.Fscan(in, &n)
	A, B, posA, posB := make([]int, n), make([]int, n), make([]int, n), make([]int, n)
	edges := make(map[[2]int]struct{}, 0)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &A[i])
		A[i] -= 1
		posA[A[i]] = i
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &B[i])
		B[i] -= 1
		posB[B[i]] = i
	}

	bl := bits.Len(uint(n))
	stA, stB := make([][]int, n), make([][]int, n)
	// 构建 st 表，需要查找，在 A 位置 [l, r] 的数字中，在 B 的位置最前面的数字是多少
	for i := 0; i < n; i++ {
		stA[i] = make([]int, bl)
		stB[i] = make([]int, bl)
		stA[i][0], stB[i][0] = A[i], B[i]
	}
	for j := 1; 1<<j <= n; j++ {
		for i := 0; i+(1<<j)-1 < n; i++ {
			u, v := stA[i][j-1], stA[i+(1<<(j-1))][j-1]
			if posB[u] < posB[v] {
				stA[i][j] = u
			} else {
				stA[i][j] = v
			}
			u, v = stB[i][j-1], stB[i+(1<<(j-1))][j-1]
			if posA[u] < posA[v] {
				stB[i][j] = u
			} else {
				stB[i][j] = v
			}
		}
	}
	query := func(f [][]int, pos []int, l, r int) int {
		k := bits.Len(uint(r-l+1)) - 1
		i, j := f[l][k], f[r-(1<<k)+1][k]
		if pos[i] < pos[j] {
			return i
		} else {
			return j
		}
	}

	// 单调栈，左边第一个比它大/小的 连边
	stk, limitA, limitB := make([]int, 0), make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		limitA[i], limitB[i] = -1, -1
	}
	for i, v := range A {
		for len(stk) > 0 && v > A[stk[len(stk)-1]] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			limitA[i] = stk[len(stk)-1]
			edges[[2]int{A[limitA[i]], v}] = struct{}{}
		}
		stk = append(stk, i)
	}
	stk = make([]int, 0)
	for i, v := range B {
		for len(stk) > 0 && v < B[stk[len(stk)-1]] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			limitB[i] = stk[len(stk)-1]
			edges[[2]int{B[limitB[i]], v}] = struct{}{}
		}
		stk = append(stk, i)
	}

	// 考虑每个位置的限制
	pass := true
	for i := 0; i < n; i++ {
		if limitA[i] != -1 {
			u, v := query(stA, posB, limitA[i], i-1), A[i]
			if posB[u] >= posB[v] {
				pass = false
				break
			}
			edges[[2]int{u, v}] = struct{}{}
		}
		if limitB[i] != -1 {
			u, v := query(stB, posA, limitB[i], i-1), B[i]
			if posA[u] >= posA[v] {
				pass = false
				break
			}
			edges[[2]int{u, v}] = struct{}{}
		}
	}
	if !pass {
		fmt.Fprintln(out, "No")
		return
	}
	fmt.Fprintln(out, "Yes")
	fmt.Fprintln(out, len(edges))
	for k := range edges {
		fmt.Fprintln(out, k[0]+1, k[1]+1)
	}
}
