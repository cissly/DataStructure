#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* right;
	struct Node* left;
	int key;
}Node;

typedef struct Tree
{
	Node* Root;
	Node* current;
	Node* parent;
	Node* child;
}Tree;

int Search(Tree* tree, int data)
{
	tree->current = tree->Root;
	tree->parent = NULL;
	while (1)
	{
		if (tree->current->key == data)
		{
			return 1;
		}
		else if (tree->current->key < data)
		{
			tree->parent = tree->current;
			if (tree->current->right == NULL)
			{
				return 0;
			}
			tree->current = tree->current->right;
		}
		else if (tree->current->key > data)
		{
			tree->parent = tree->current;
			if (tree->current->left == NULL)
			{
				return 0;
			}
			tree->current = tree->current->left;
		}
	}
}

void Insert(Tree* tree, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = data;
	newnode->left = NULL;
	newnode->right = NULL;

	if (tree->Root == NULL)
	{
		tree->Root = newnode;
		return;
	}
	if (Search(tree, data))
	{
		printf("중복 \n");
	}
	else
	{
		if (tree->current->key < data)
		{
			tree->parent->right = newnode;
		}
		else
		{
			tree->parent->left = newnode;
		}
	}
	
}

void Ch_No(Tree* tree)
{
	if (tree->Root == tree->current)
	{
		tree->Root = NULL;
	}
	if (tree->parent->left == tree->current)
	{
		tree->parent->left = NULL;
	}
	else if (tree->parent->right == tree->current)
	{
		tree->parent->right = NULL;
	}
	free(tree->current);
}

void Ch_One(Tree* tree)
{
	Node* oneChild = NULL;
	if (tree->current->left != NULL)
	{
		oneChild = tree->current->left;
	}
	else if (tree->current->right != NULL)
	{
		oneChild = tree->current->right;
	}
	if (tree->parent->right == tree->current)
	{
		tree->parent->right = oneChild;
	}
	else if (tree->parent->left == tree->current)
	{
		tree->parent->left = oneChild;
	}

	free(tree->current);
}

void Ch_Two(Tree* tree)
{
	Node* Min_parent = tree->current;
	Node* Min = tree->current->right;
	while (Min->left != NULL)
	{
		Min_parent = Min;
		Min = Min->left;
	}
	tree->current->key = Min->key;
	Min_parent = Min->right;
	free(Min);

}
void Delete(Tree* tree, int data)
{
	if (Search(tree,data))
	{
		tree->parent = NULL;
		tree->current = tree->Root;
		while (tree->current->key != data)
		{
			tree->parent = tree->current;
			if (tree->current->key > data)
			{
				tree->current = tree->current->left;
			}
			else
			{
				tree->current = tree->current->right;
			}
		}

		if ((tree->current->left == NULL) && (tree->current->right==NULL))
		{
			Ch_No(tree);
		}
		else if ((tree->current->left == NULL) || (tree->current->right == NULL))
		{
			Ch_One(tree);
		}
		else if ((tree->current->left != NULL) && (tree->current->right != NULL))
		{
			Ch_Two(tree);
		}
	}
	else
	{
		printf("존재하지 않습니다.");
	}
}

void Display(Node* root)
{
	if (root != NULL)
	{
		Display(root->left);
		printf("%d ->",root->key);
		Display(root->right);
	}
}
int main(void)
{
	Tree tree = { NULL,NULL,NULL,NULL };
	Insert(&tree, 15);
	Insert(&tree, 18);
	Insert(&tree, 10);
	Insert(&tree, 11);
	Insert(&tree, 8);
	Insert(&tree, 19);
	Insert(&tree, 16);
	Insert(&tree, 3);
	Insert(&tree, 9);
	Display(tree.Root);

	Delete(&tree, 10);
	return 0;
}