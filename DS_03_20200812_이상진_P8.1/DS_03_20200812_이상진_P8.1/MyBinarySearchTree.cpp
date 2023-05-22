#include "MyBinarySearchTree.h"

BT_Node* BT_Create_Node(int newData)
{
	BT_Node* newnode = (BT_Node*)malloc(sizeof(BT_Node));
	newnode->data = newData;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void BT_Destroy_Node(BT_Node* node)
{
	if (node != NULL)
	{
		free(node);
	}
}


//BST 관련 함수
int BST_Min(BT_Node* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	BT_Node* iter = root;
	while (iter->left != NULL)
	{
		iter = iter->left;
	}
	return iter->data;
}

int BST_Max(BT_Node* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	BT_Node* iter = root;
	while (iter->right != NULL)
	{
		iter = iter->right;
	}
	return iter->data;
}
BT_Node* BST_Search(BT_Node* root, int target)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (target == root->data)
	{
		return root;
	}
	else if (target < root->data)
	{
		return BST_Search(root->left, target);
	}
	else
	{
		return BST_Search(root->right, target);
	}
}

void BST_Insert(BT_Node** root, int key)
{
	if (*root == NULL)
	{
		*root = BT_Create_Node(key);
	}
	else
	{
		BT_Node* parent= NULL;
		BT_Node* iter = *root;
		while (iter != NULL)
		{
			parent = iter;
			if (key == iter->data)
			{
				return;
			}
			else if (key < iter->data)
			{
				iter = iter->left;
			}
			else
			{
				iter = iter->right;
			}
		}
		if (key < parent->data)
		{
			parent->left = BT_Create_Node(key);
		}
		else
		{
			parent->right = BT_Create_Node(key);
		}
	}
}
void BST_Delete(BT_Node** root, int key)
{
	BT_Node* vRoot = BT_Create_Node(NULL);
	vRoot->right = *root;
	BT_Node* iter = *root;
	BT_Node* parent = vRoot;
	while (iter != NULL && iter->data != key)
	{
		parent = iter;
		if (key < iter->data)
		{
			iter = iter->left;
		}
		else
		{
			iter = iter->right;
		}
	}

	if (iter == NULL)
	{
		return;
	}

	BT_Node* delnode = iter;
	if (delnode->left == NULL && delnode->right == NULL)
	{
		if (parent->right == delnode)
		{
			parent->right == NULL;
		}
		else
		{
			parent->left == NULL;
		}
	}
	else if (delnode->left == NULL || delnode->right == NULL)
	{
		(parent->left == delnode ? parent->left : parent->right) = (delnode->left == NULL ? delnode->right : delnode->left);
	}
	else
	{
		BT_Node* su = delnode->right;
		BT_Node* psu = delnode;

		while (su->left != NULL)
		{
			psu = su;
			su = su->left;
		}
		delnode->data = su->data;

		if (psu->left == su)
		{
			psu->left = su->right;
		}
		else
		{
			psu->right = su->right;
		}

		delnode = su;
	}

	if (vRoot->right != *root)
	{
		*root = vRoot->right;
	}
	BT_Destroy_Node(vRoot);
	BT_Destroy_Node(delnode);
}

//출력 관련 함수
void BST_PrintTree2Matrix(int** M, BT_Node* bt_node, int col, int row, int height)
{
	if (bt_node == NULL) return;
	M[row][col] = bt_node->data;
	BST_PrintTree2Matrix(M, bt_node->left, col - pow(2, height - 2), row + 1, height - 1);
	BST_PrintTree2Matrix(M, bt_node->right, col + pow(2, height - 2), row + 1, height - 1);
}

void BST_TreePrinter(BT_Node* root)
{
	int h = BST_Height(root);
	int col = (1 << h) - 1;
	int** M = new int* [h];
	for (int i = 0; i < h; i++) {
		M[i] = new int[col];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] = 0;
		}
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
	BST_PrintTree2Matrix(M, root, col / 2, 0, h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < col; j++) {
			if (M[i][j] == 0)
				printf(" ");
			else
				printf("%2d", M[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < col; j++) {
		printf("==");
	}
	printf("\n");
}

int BST_Height(BT_Node* root)
{

	if (root == NULL)
		return 0;
	return MAX(BST_Height(root->left), BST_Height(root->right)) + 1;
}