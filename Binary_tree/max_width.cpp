
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/*Function protoypes*/
int getWidth(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(struct node* ptr)
{
	int level, width[100];

	std::queue<pair<struct node*, int> > q;
	q.push(make_pair(ptr, 1));
	memset(width, 0, sizeof(width));
	width[1] = 1;

	while (!q.empty())
	{
		ptr = q.front().first;
		level = q.front().second;
		if (ptr->left)
		{
			q.push(make_pair(ptr->left, level + 1));
			width[level+1]++;
		}
		if (ptr->right) {
			q.push(make_pair(ptr->right, level + 1));
			width[level+1]++;
		}
		q.pop();
	}
	for (int i = 0; i < 10; i++)
		cout << "widht of level:" << i << " is :" << width[i] << "\n";
	return width[max_element(width, width + 100) - width];

}

/* Get width of a given level */
int getWidth(struct node* root, int level)
{

	if (root == NULL)
		return 0;

	if (level == 1)
		return 1;

	else if (level > 1)
		return getWidth(root->left, level - 1) +
		getWidth(root->right, level - 1);
}


/* UTILITY FUNCTIONS */
/* Compute the "height" of a tree -- the number of
nodes along the longest path from the root node
down to the farthest leaf node.*/
int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lHeight = height(node->left);
		int rHeight = height(node->right);
		/* use the larger one */

		return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
	}
}
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
/* Driver program to test above functions*/
int main()
{
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(8);
	root->right->right->left = newNode(6);
	root->right->right->right = newNode(7);

	/*
	Constructed bunary tree is:
	1
	/  \
	2    3
	/  \     \
	4   5     8
	/  \
	6   7
	*/
	printf("Maximum width is %d \n", getMaxWidth(root));
	getchar();
	return 0;
}
