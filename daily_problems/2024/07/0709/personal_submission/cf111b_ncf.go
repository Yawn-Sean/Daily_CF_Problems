package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF111B(os.Stdin, os.Stdout) }

func CF111B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, x, y int
	fmt.Fscan(in, &t)
	m := map[int]int{}
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &x, &y)
		count := 0
		i := 1
		for ; i*i < x; i++ {
			if x%i == 0 {
				idx, exist := m[i]
				if !exist || idx-t > y {
					count++
				}
				idx, exist = m[x/i]
				if !exist || idx-t > y {
					count++
				}
				m[i], m[x/i] = t, t
			}
		}
		if i*i == x {
			idx, exist := m[i]
			if !exist || idx-t > y {
				count++
			}
			m[i] = t
		}
		fmt.Fprintf(out, "%d\n", count)
	}
}
