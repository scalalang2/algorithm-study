package main

import (
	"bufio"
	"fmt"
	"os"
)

var stack1 []int // [1, 3, 2, 1]
var stack2 []int // [3, 56, 7, 9] --> 3 567979 567979 567979 567979
var stack3 []int // [+. +. +. -]
var top int

func main() {
	var text, tmp string

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%s\n", &text)

	for i := 0; i < len(text); i++ {
		if string(text[i]) == "(" {

		}
	}
}