package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type node struct{ color, cnt int }

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var s string
	fmt.Fscan(in, &s)
	n := len(s)
	nodes := []node{}
	for i := 0; i < n; i++ {
		if len(nodes) != 0 && nodes[len(nodes)-1].color == int(s[i]) {
			nodes[len(nodes)-1].cnt++
		} else {
			nodes = append(nodes, node{int(s[i]), 1})
		}
	}
	ops := 0
	for len(nodes) > 1 {
		ops++
		nnodes := []node{}
		if nodes[0].cnt > 1 {
			nnodes = append(nnodes, node{nodes[0].color, nodes[0].cnt - 1})
		}
		for i := 1; i < len(nodes)-1; i++ {
			if nodes[i].cnt > 2 {
				if len(nnodes) != 0 && nnodes[len(nnodes)-1].color == nodes[i].color {
					nnodes[len(nnodes)-1].cnt += nodes[i].cnt - 2
				} else {
					nnodes = append(nnodes, node{nodes[i].color, nodes[i].cnt - 2})
				}
			}
		}
		if nodes[len(nodes)-1].cnt > 1 {
			if len(nnodes) != 0 && nnodes[len(nnodes)-1].color == nodes[len(nodes)-1].color {
				nnodes[len(nnodes)-1].cnt += nodes[len(nodes)-1].cnt - 1
			} else {
				nnodes = append(nnodes, node{nodes[len(nodes)-1].color, nodes[len(nodes)-1].cnt - 1})
			}
		}
		nodes = nnodes
	}
	fmt.Fprintln(out, ops)
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
