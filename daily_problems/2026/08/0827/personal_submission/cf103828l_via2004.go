package main

import (
	"bufio"
	"fmt"
	"os"
)

func beautiful(n int) []int {
	if n == 1 {
		return []int{1}
	}
	result := make([]int, 0, n)
	s1, s2 := beautiful((n+1)/2), beautiful(n/2)
	for i := 0; i < (n+1)/2; i++ {
		result = append(result, 2*s1[i]-1)
	}

	for i := 0; i < n/2; i++ {
		result = append(result, 2*s2[i])
	}

	return result
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var t int
	fmt.Fscan(in, &t)
	for ; t != 0; t-- {
		var n int
		fmt.Fscan(in, &n)

		p := beautiful(n)

		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				value := (p[i]-1)*n + p[j]
				fmt.Fprint(out, value, " ")
			}
			fmt.Fprintln(out)
		}
	}
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	solve(in, out)
}
