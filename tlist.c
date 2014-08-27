/*
 * Linked-list of trees which need to be merged into the main Huffman tree.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tlist.h"
#include "tree.h"

void disptlist(struct tlist *list)
{
	static int cnt = 0;

	if (list != 0) {
		printf("%d | tree address: %p; tree contents: %d; char: %c; freq: %d\n", ++cnt, list->tree, list->tree->data, list->tree->data, list->freq);

		if (list->next != 0)
			disptlist(list->next);
	}

	cnt = 0;
	return;
}

/* sort from smallest to largest */
struct tlist* sorttlist(struct tlist *list)
{
	if (list == 0)
		return list;

	if (list->next != 0 && list->freq < list->next->freq)
		list = swaptlist(list, list->next);

	list->next = sorttlist(list->next);

	if (list->next != 0 && list->freq < list->next->freq) {
		list = swaptlist(list, list->next);
		list->next = sorttlist(list->next);
	}

	return list;
}

struct tlist* swaptlist(struct tlist *src, struct tlist *dst)
{
	src->next = dst->next;
	dst->next = src;
	
	return dst;
}

struct tlist* mktlist(char ch)
{
	struct tlist *list = (struct tlist*)malloc(sizeof(struct tlist));
	list->tree = mknode(ch);
	list->next = 0;

	return list;
}

