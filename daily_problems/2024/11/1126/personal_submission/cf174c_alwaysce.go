package main

import (
	"bufio"
	"fmt"
	"io"
)

func cf174C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		差分+贪心构造匹配
	*/

	var n int
	fmt.Fscan(in, &n)

	arr := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &arr[i])
	}
	arr[n] = 0

	diff := make([]int, n+1)
	diff[0] = arr[0]
	for i := 1; i <= n; i++ {
		diff[i] = arr[i] - arr[i-1]
	}

	ans := 0
	results := make([][]int, 0)
	j := 0
	//fmt.Fprintln(out, diff)

	for i := 0; i < n; i++ {
		for diff[i] > 0 {
			for ; j <= n && diff[j] >= 0; j++ {
			}

			// 匹配i和j多少次?
			if j <= n {
				match := min(-diff[j], diff[i])
				for r := 0; r < match; r++ {
					ans++
					results = append(results, []int{i, j - 1})
				}
				diff[i] -= match
				diff[j] += match
			}
			//fmt.Fprintln(out, diff)
		}
	}

	fmt.Fprintln(out, ans)
	for _, v := range results {
		fmt.Fprintf(out, "%d %d\n", v[0]+1, v[1]+1)
	}
}

//func main() {
//	cf174C(bufio.NewReader(os.Stdin), os.Stdout)
//}
