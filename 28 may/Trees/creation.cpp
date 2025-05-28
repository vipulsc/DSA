#include <iostream>
using namespace std;

class node
{
	public:
	node* left;
	node* right;
	int data;

	node(int val)
	{
		this->data=val;
		this->left=nullptr;
		this->right=nullptr;
	}
};

node* creation(node* root)
{
	int data;
	cout<<"Enter the value of node"<<endl;
	cin>>data;
	root=new node(data);
	if(data==-1)
	{
		return NULL;
	}

	cout<<"Enter the data for the left of "<<data<<endl;
	root->left=creation(root->left);

	cout<<"Enter the data for the right of "<<data<<endl;
	root->right=creation(root->right);

	return root;
}

void levelOrderTraversal(node* root)
{
	queue<node*>q;
	q.push(root);

	while(!q.empty())
	{
		int levelSize=q.size();
		
		cout<<"LEVEL "<<levelSize<<endl;;
		for(int i=0;i<levelSize;i++)
		{
			node* temp=q.front();
			q.pop();
			cout<<temp->data<<" ";
				if(temp->left)
				{
					q.push(temp->left);
				}
				if(temp->right)
				{
					q.push(temp->right);
				}
		}
		cout<<endl;
		
	}
}

void inorder(node* root)
{
	if(!root) return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(node* root)
{
	if(!root) return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root)
{
	if(!root) return;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

node* buildFromLevel(node* root)
{
	queue<node*>q;
	cout<<"Enter data for root"<<endl;
	int data;
	cin>>data;
	root=new node(data);
	q.push(root);
	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();

		cout<<"Enter left node for: "<<temp->data<<endl;
		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1)
		{
			temp->left=new node(leftdata);
			q.push(temp->left);
		}
		cout<<"Enter left node for: "<<temp->data<<endl;
		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1)
		{
			temp->right=new node(rightdata);
			q.push(temp->right);
		}

	}
	return root;
}

int main()
{
	//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	node* root=nullptr;
	root=creation(root);
	// levelOrderTraversal(root);
	inorder(root);
	preorder(root);
	postorder(root);
}