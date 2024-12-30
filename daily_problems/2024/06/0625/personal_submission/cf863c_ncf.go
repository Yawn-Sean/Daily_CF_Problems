package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF863C(os.Stdin, os.Stdout) }

func CF863C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, x, y int
	fmt.Fscan(in, &n, &x, &y)
	type pair struct{ a, b int }
	next := map[pair]pair{}
	var matrix [6][3]int
	for i := 0; i < 6; i++ {
		fmt.Fscan(in, &matrix[i][0], &matrix[i][1], &matrix[i][2])
	}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			next[pair{i + 1, j + 1}] = pair{matrix[i][j], matrix[i+3][j]}
		}
	}
	m := map[pair][3]int{}
	cur := pair{x, y}
	value := [2]int{0, 0}
	var arr [][2]int
	for i := 0; i < n; i++ {
		if cur.a == 1 && cur.b == 3 {
			value[0] += 1
		} else if cur.a == 3 && cur.b == 1 {
			value[1] += 1
		} else if cur.a > cur.b {
			value[0] += 1
		} else if cur.a < cur.b {
			value[1] += 1
		}
		v, exist := m[cur]
		if exist {
			offset := i - v[0]
			offsetValue := [2]int{value[0] - v[1], value[1] - v[2]}
			ans := [2]int{0, 0}
			idx := v[0]
			circle := (n - idx - 1) / offset
			ans[0] += circle * offsetValue[0]
			ans[1] += circle * offsetValue[1]
			remainder := (n - idx - 1) % offset
			ans[0] += arr[v[0]+remainder][0]
			ans[1] += arr[v[0]+remainder][1]

			fmt.Fprintf(out, "%d %d", ans[0], ans[1])
			return
		}
		m[pair{cur.a, cur.b}] = [3]int{i, value[0], value[1]}
		arr = append(arr, [2]int{value[0], value[1]})
		cur = next[cur]
	}

	fmt.Fprintf(out, "%d %d", value[0], value[1])
}
