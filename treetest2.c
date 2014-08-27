#include <stdio.h>

#include "tree.h"


/*
 * Build tree from leaves to root
 */
int main(void)
{
	struct kpnode* l1 = mknode('a');
	struct kpnode* l2 = mknode('x');
	struct kpnode* l3 = mknode('$');
	struct kpnode* l4 = mknode(' ');

	struct kpnode* p1 = insnode(0, l1, l2);
	struct kpnode* p2 = insnode(0, l3, l4);

	struct kpnode* root = insnode(0, p1, p2);

	/*
	 * Display tree structure
	 */

	disptree(root);

/*
	struct kpnode *n[300];
	int i;
	for (i = 0; i < 300; i++) {
		if (i == 29)
			((*n+i))->data = 0;
		else
			((*n+i))->data = i+1;
	}
*/
/*
	size_t size = sizeof(num)/sizeof(num[0]);
	printf("%d\n",size);
*/
/*
	int smallest = getsmall(n, 300);

	printf("smallest: %d\n",smallest);
*/
	return 0;
}
