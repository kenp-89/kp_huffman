typedef enum tside {LEFT, RIGHT} tside;

struct kpnode {
	char data;
	struct kpnode *lnext;
	struct kpnode *rnext;
};

struct kpnode* mknode(char);
struct kpnode* insnode(char, struct kpnode*, struct kpnode*);
void remnode(struct kpnode**);
int find(char, struct kpnode*);
int disptree(struct kpnode*);
