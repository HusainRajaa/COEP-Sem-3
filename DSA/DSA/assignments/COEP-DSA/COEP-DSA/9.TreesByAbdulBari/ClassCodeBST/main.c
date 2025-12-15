#include"bst.h"
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int main(){
	BST t;
	init_BST(&t);
	insert_bstree(&t,23);
	insert_bstree(&t,13);
	insert_bstree(&t,25);
	insert_bstree(&t,34);
	insert_bstree(&t,3);
	preorder(t);
	non_recursive_preorder(t);
	return 0;
}
