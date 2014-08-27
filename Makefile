llisttest: llisttest.c llist.c
	cc -O2 -pipe -g llist.c llisttest.c -o llisttest

treetest: treetest.c tree.c
	cc -O2 -pipe tree.c treetest.c -o treetest

treetest2: treetest2.c tree.c
	cc -O2 -pipe tree.c treetest2.c -o treetest2

debug2: treetest2.c tree.c
	cc -O2 -pipe -g tree.c treetest2.c -o treetest2

huff: tree.c main.c
	cc -O2 -pipe llist.c tree.c tlist.c main.c -o huff

dhuff: tree.c main.c
	cc -O2 -pipe -g llist.c tree.c tlist.c main.c -o huff

clean:
	rm -f tree llisttest treetest treetest2 huff
