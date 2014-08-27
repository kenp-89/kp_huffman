#include <stdio.h>

#include "llist.h"

int main(void)
{
	struct lnode *root = mklnode('a', 8);
	struct lnode *c2 = inslnode('c', 2, root);

	displist(root);
	printf("\n");

	struct lnode *c1 = inslnode('b', 5, root);

	incfreq(c2);

	displist(root);
	printf("\n");

	printf("a exists? %p\n", findlnode(root, 'a'));
	printf("b exists? %p\n", findlnode(root, 'b'));
	printf("c exists? %p\n", findlnode(root, 'c'));
	printf("k exists? %p\n", findlnode(root, 'k'));
	printf("\n");

	remlnode(&c2);
	remlnode(&c1);
	remlnode(&root);

	printf("after free():\n");
	printf("root: %x\n", root);
	printf("c1  : %x\n", c1);
	printf("c2  : %x\n", c2);

	return 0;
}
