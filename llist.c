#include <stdlib.h>
#include <stdio.h>

#include "llist.h"

/*
 * linked-list routines
 */

void displist(struct lnode *root)
{
	static int cnt = 0;

	if (root != 0) {
		printf("%d | ", ++cnt);

		if (root->ch == '\n')
			printf("node: char: \"%s\"; freq: %d\n", "\\n", root->freq);
		else
			printf("node: char: \"%c\"; freq: %d\n", root->ch, root->freq);


		if (root->next != 0)
			displist(root->next);
	}

	cnt = 0;
	return;
}

struct lnode* findlnode(struct lnode *node, char ch)
{
	if (node->ch == ch)
		return node;

	if (node->next != 0)
		return findlnode(node->next, ch);

	return 0;
}

void incfreq(struct lnode* node)
{
	node->freq++;
	return;
}

struct lnode* mklnode(char ch, int freq)
{
	struct lnode *node = (struct lnode*)malloc(sizeof(struct lnode));
	node->ch = ch;
	node->freq = freq;
	node->next = 0;

	return node;
}

struct lnode* applnode(char ch, int freq, struct lnode *root)
{
	if (root->next != 0)
		return applnode(ch, freq, root->next);

	struct lnode *node = mklnode(ch, freq);

	root->next = node;

	return node;
}

struct lnode* inslnode(char ch, int freq, struct lnode *parent)
{
	struct lnode *node = mklnode(ch, freq);
	node->next = parent->next;
	parent->next = node;

	return node;
}

void remlnode(struct lnode **node)
{
	if ((*node)->next != NULL) {
		remlnode(&(*node)->next);
	}

	free(*node);
	*node = NULL;

	return;
}
