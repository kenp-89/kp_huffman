#include <stdio.h>

#include "tree.h"

int main(void)
{
	struct kpnode* root = mknode((char)100);
	struct kpnode** rootp = &root;

	printf("root:     %x\n", root);
	printf("root:data=%d\n", root->data);

	remnode(rootp);

	printf("root:     %x\n", root);

	root = mknode((char)40);
	root->lnext = mknode((char)30);
	root->rnext = mknode((char)50);
	root->rnext->rnext = mknode((char)70);

	int n = find((char)40, root);
	int m = find((char)70, root);

	printf("n: %d\n", n);
	printf("m: %d\n", m);

	remnode(&(root)->rnext);
	root->rnext = mknode((char)100);

	return 0;
}
