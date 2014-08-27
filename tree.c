#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

/*
 * struct kpnode {
 * 	char data;
 * 	struct kpnode *lnext;
 * 	struct kpnode *rnext;
 * };
 */

struct kpnode* mknode(char data)
{
	struct kpnode *node = (struct kpnode*)malloc(sizeof(struct kpnode));
	node->data = data;
	node->lnext = 0;
	node->rnext = 0;

	return node;
}

struct kpnode* insnode(char data, struct kpnode* childl, struct kpnode* childr)
{
	struct kpnode* node = mknode(data);
	node->lnext = childl;
	node->rnext = childr;

	return node;
}

void remnode(struct kpnode **node)
{
	if ((*node)->lnext != NULL)
		remnode(&(*node)->lnext);
	if ((*node)->rnext != NULL)
		remnode(&(*node)->rnext);

	free(*node);
	*node = NULL;

	return;
}

int find(char val, struct kpnode *node)
{
	if (node == NULL)
		return 0;
	if (val == node->data)
		return 1;
	else {
		int n;
		if(!(n = find(val, node->lnext)) && !(n = find(val,node->rnext)))
			return 0;
		else
			return 1;
	}
}

/*
int getpath(char val, struct kpnode *node)
{

}
*/

int disptree(struct kpnode* node)
{
	printf("node data: %c\n", node->data);

	if (node->lnext) {
		printf("child 1 ");
		disptree(node->lnext);
	}

	if (node->rnext) {
		printf("child 2 ");
		disptree(node->rnext);
	}

	return 0;
}

