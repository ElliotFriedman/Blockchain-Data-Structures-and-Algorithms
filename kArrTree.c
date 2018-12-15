#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	t_tree
{
	int		val;
	int		childNum;
	struct t_tree	*nodes;

}		k_tree;

void	traverseKArrTree(k_tree *root)
{
	int	i;

	i = 0;
	printf("%p\n", root);
	if (root)
		printf("val: %d\n", root->val);
	//not sure why we have to increment the address here to dereference the proper node
	//
	//only way I could get this to work... I'll figure it out later, or never
	root->nodes++;
	//this looks very similar to the engine of ls unix command, start at base directory, print and then recurse
	while (i < root->childNum && root->nodes)
	{
		traverseKArrTree(root->nodes);
		root->nodes++;
		i++;
	}
}

int main()
{
	k_tree *karrTree;

	karrTree = malloc(sizeof(k_tree));
	karrTree->nodes = malloc(8 * 2);
	karrTree->childNum = 2;
	karrTree->val = 174;
	printf("%p\n", karrTree);

	k_tree *arrTree1;
	arrTree1 =  malloc(sizeof(k_tree));
	//	arrTree1->nodes = 0;//malloc(8);
	arrTree1->childNum = 0;
	arrTree1->val = 112;

	k_tree *arrTree2;
	arrTree2 =  malloc(sizeof(k_tree));
	//	arrTree2->nodes = 0;//malloc(8);
	arrTree2->childNum = 0;
	arrTree2->val = 1300;
	printf("arrTree2: %p\n", arrTree2);

	k_tree *tmp;
	tmp = karrTree->nodes;
	tmp = arrTree1;
	printf("tmp: %p\n", tmp);
	tmp++;
	printf("tmp: %p\n", tmp);
	tmp = arrTree2;
	printf("tmp: %p\n", tmp);
	
	traverseKArrTree(karrTree);
	//	printf("%p\n", arrTree2);
	//	printf("val: %d\n", arrTree2->val);

	return 0;
}
