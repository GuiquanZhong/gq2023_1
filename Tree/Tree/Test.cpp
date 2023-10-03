#include"Tree.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

void DestoryTree(BTNode** root)
{
	if (*root == NULL)return;
	DestoryTree(&(*root)->left);
	DestoryTree(&(*root)->right);
	free(*root);
	*root = NULL;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		cout << "NULL" << " ";
		return;
	}

	cout << root->data << ' ';
	PrevOrder(root->left);
	PrevOrder(root->right);
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)return 0;
	if (root->left == NULL && root->right == NULL)return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


void PrevOrder1(BTNode* root)
{
	if (root == NULL)
	{
		cout << "NULL" << " ";
		return;
	}

	PrevOrder(root->left);
	cout << root->data << ' ';
	PrevOrder(root->right);
}



void PrevOrder2(BTNode* root)
{
	if (root == NULL)
	{
		cout << "NULL" << " ";
		return;
	}

	PrevOrder(root->left);
	PrevOrder(root->right);
	cout << root->data << ' ';
}

void LevelOrder(BTNode* root)
{
	queue<BTNode*> q1;
	if (root)
		q1.push(root);
	while (!q1.empty())
	{
		BTNode* front = q1.front();
		q1.pop();
		cout << front->data;
		if (front->left != NULL)
		{
			q1.push(front->left);
		}
		if (front->right != NULL)
		{
			q1.push(front->right);
		} 
	}
}

int main() {
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;


	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	PrevOrder(A);
	cout << endl;
	PrevOrder1(A);
	cout << endl; 
	PrevOrder2(A);
	cout << endl;
	cout << TreeSize(A) << endl;
	cout << TreeLeafSize(A) << endl;
	LevelOrder(A);
	return 0;
}