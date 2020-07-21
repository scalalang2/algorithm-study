package main

import (
	"bufio"
	"fmt"
	"os"
)

type node struct {
	left 	*node
	right 	*node
	value	string
}

var tree map[string]*node

func preorder(root *node) {
	if root != nil && root.value != "." {
		fmt.Printf("%s", root.value)
		preorder(root.left)
		preorder(root.right)
	}
}

func inorder(root *node) {
	if root != nil && root.value != "." {
		inorder(root.left)
		fmt.Printf("%s", root.value)
		inorder(root.right)
	}
}

func postorder(root *node) {
	if root != nil && root.value != "." {
		postorder(root.left)
		postorder(root.right)
		fmt.Printf("%s", root.value)
	}
}

func main() {
	var N int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &N)
	tree = make(map[string]*node)
	var _root *node

	for i := 0; i < N; i++ {
		var root, left, right string
		fmt.Fscanf(reader, "%s %s %s\n", &root, &left, &right)

		if i == 0 {
			tree[root] = &node {value: root}
			_root = tree[root]
		}

		tree[root].left = &node { value: left }
		tree[root].right = &node { value: right }
		tree[left] = tree[root].left
		tree[right] = tree[root].right
	}

	preorder(_root)
	fmt.Printf("\n")
	inorder(_root)
	fmt.Printf("\n")
	postorder(_root)
}