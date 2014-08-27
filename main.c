#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "huff.h"
#include "llist.h"
#include "tlist.h"
#include "tree.h"

struct lnode* mklist(int fd)
{
	int nr, i;
	char buf[BUFSIZE];

	struct lnode *root = 0;
	struct lnode *result = 0;

	while ((nr = read(fd, buf, BUFSIZE)) != -1 && nr != 0) {
		/* count characters */
		printf("Read %d bytes.\n", nr);
		for(i = 0; i < nr; i++) {

			if (i == 0)
				root = mklnode(buf[i], 1);

			else if ((result = findlnode(root, buf[i])))
				incfreq(result);

			else
				applnode(buf[i], 1, root);

		}

	}

	return root;
}

struct tlist* unite(struct tlist *list)
{
	struct tlist *tmp = 0;

	if (list == 0)
		return list;

	while (list->next != 0) {
		tmp = list;
		list->tree = insnode(0, list->tree, list->next->tree);
		list->next = unite(list->next->next);
		
	}

	return list;
}

struct kpnode* mktree(struct lnode *list)
{
	struct kpnode *root = 0;
	struct tlist *tlp = mktlist(0);
	struct tlist *tlroot = tlp;

	/* make leaves */
	for (; list != 0; list = list->next) {
		tlp->tree = mknode(list->ch);
		tlp->freq = list->freq;

		if (list->next != 0) {
			tlp->next = mktlist(0);
			tlp = tlp->next;
		}
	}

	tlroot = sorttlist(tlroot);

	disptlist(tlroot);

	/* connect leaves to form whole tree */
	tlroot = unite(tlroot);

	disptlist(tlroot);

	root = tlroot->tree;

	return root;
}

int encode(void)
{

	return 0;
}

int main(int argc, char **argv)
{
	int fd1, fd2;

	struct lnode *clist;
	struct kpnode *tree;

	if (argc < 1) {
		fprintf(stderr, "Error: not enough arguments.\n");
		return 1;
	}

	if ((fd1 = open(argv[1], O_RDONLY)) < 0) {
		fprintf(stderr, "Error: cannot open file.\n");
		return 1;
	}

	if ((clist = mklist(fd1)) == 0) {
		fprintf(stderr, "Error while compiling frequencies.\n");
		return 1;
	}

	displist(clist);

	tree = mktree(clist);

	disptree(tree);

	encode();

	/*save(fd2);*/

	remlnode(&clist);
	/*remnode(&tree);*/

	close(fd1);

	return 0;
}
