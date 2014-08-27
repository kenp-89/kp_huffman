struct tlist {
	struct kpnode *tree;
	struct tlist *next;

	int freq;
};

void disptlist(struct tlist*);
struct tlist* sorttlist(struct tlist*);
struct tlist* swaptlist(struct tlist*, struct tlist*);
struct tlist* mktlist(char);
