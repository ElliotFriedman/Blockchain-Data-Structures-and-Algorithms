/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictTrie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 23:35:31 by efriedma          #+#    #+#             */
/*   Updated: 2018/12/17 23:47:17 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_node {
	char			*value;
	struct s_node	*right;
	struct s_node	*left;
};

//traverse trie, can easily traverse k-arr tree with addition of a while loop on final condition check
int		isInDict(struct s_node *root, char *word)
{
	//check for invalid input or end of traversal, in either case fail
	if (!root || !word)
		return 0;
	//check for null terminator, means successful search
	if (*word == 0)
		return 1;
	if (*word != *root->value)
		return 0;
	
	else if (*word == *root->value)
	{
		word++;
		return isInDict(root->left, word) || isInDict(root->right, word);
	}

}

int main()
{
	struct s_node *root = malloc(sizeof(struct s_node));
	struct s_node *root1 = malloc(sizeof(struct s_node));
	struct s_node *root2 = malloc(sizeof(struct s_node));
	struct s_node *root3 = malloc(sizeof(struct s_node));
	struct s_node *root4 = malloc(sizeof(struct s_node));
	struct s_node *root5 = malloc(sizeof(struct s_node));
	struct s_node *root6 = malloc(sizeof(struct s_node));
	struct s_node *root7 = malloc(sizeof(struct s_node));
	struct s_node *root8 = malloc(sizeof(struct s_node));
	struct s_node *root9 = malloc(sizeof(struct s_node));
	struct s_node *root10 = malloc(sizeof(struct s_node));
	struct s_node *root11 = malloc(sizeof(struct s_node));

	bzero((void*)root, sizeof(struct s_node));
	bzero((void*)root1, sizeof(struct s_node));
	bzero((void*)root2, sizeof(struct s_node));
	bzero((void*)root3, sizeof(struct s_node));
	bzero((void*)root4, sizeof(struct s_node));
	bzero((void*)root5, sizeof(struct s_node));
	bzero((void*)root6, sizeof(struct s_node));
	bzero((void*)root7, sizeof(struct s_node));
	bzero((void*)root8, sizeof(struct s_node));
	bzero((void*)root9, sizeof(struct s_node));
	bzero((void*)root10, sizeof(struct s_node));
	bzero((void*)root11, sizeof(struct s_node));
	
	root->left = root1;
	root1->left = root2;

	root->right = root3;
	root3->right = root4;
	root4->right = root5;
	root5->right = root6;
	root6->right = root7;
	root7->right = root8;
	root8->right = root9;
	root9->right = root10;
	root10->right = root11;

	root->value = strdup("h");
	root1->value = strdup("e");
	//go right at this val
	root2->value = strdup("a");

	//this is all left
	root3->value = strdup("l");
	root4->value = strdup("e");
	root5->value = strdup("l");
	root6->value = strdup("u");
	root7->value = strdup("j");
	root8->value = strdup("a");
	root9->value = strdup("h");
	root10->value = strdup("!");
	root11->value = strdup("!");

	printf("is he in dict: %s\n", isInDict(root, "he") == 1 ? "yes" : "no");
	printf("is hello in dict: %s\n", isInDict(root, "hello") == 1 ? "yes" : "no");
	printf("is hlelujah! in dict: %s\n", isInDict(root, "hlelujah!") == 1 ? "yes" : "no");

	return 0;
}
