package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1185D(os.Stdin, os.Stdout) }

func CF1185D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	b := make([]int, n)

	m := map[int]int{}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b[i])
		m[b[i]] = i + 1
	}
	if n <= 3 {
		fmt.Fprintf(out, "%d ", 1)
	} else {
		sort.Ints(b)
		count := 0
		idx := 0
		diff := b[1] - b[0]
		last := 1
		for i := 2; i < n; i++ {
			if b[i]-b[last] != diff {
				count++
				idx = i
				if count > 1 {
					break
				}
			} else {
				last = i
			}
		}
		if count < 2 {
			fmt.Fprintf(out, "%d\n", m[b[idx]])
		} else if b[3]-b[2] != diff {
			diff := b[3] - b[2]
			flag := false
			for i := 3; i < n; i++ {
				if b[i]-b[i-1] != diff {
					fmt.Fprintf(out, "%d\n", -1)
					flag = true
					break
				}
			}
			if !flag {
				if b[2]-b[0] == diff {
					fmt.Fprintf(out, "%d\n", m[b[1]])
				} else if b[2]-b[1] == diff {
					fmt.Fprintf(out, "%d\n", m[b[0]])
				} else {
					fmt.Fprintf(out, "%d\n", -1)
				}
			}
		} else {
			fmt.Fprintf(out, "%d\n", -1)
		}
	}
}
