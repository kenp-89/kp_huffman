struct lnode {
	char ch;
	int freq;
	struct lnode *next;
};

void displist(struct lnode*);
struct lnode* findlnode(struct lnode*, char);
void incfreq(struct lnode*);
struct lnode* mklnode(char, int);
struct lnode* inslnode(char,int,struct lnode*);
struct lnode* inslnode(char,int,struct lnode*);
void remlnode(struct lnode**);
