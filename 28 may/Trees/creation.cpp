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



int main()
{
	node* root=nullptr;
	root=creation(root);
	levelOrderTraversal(root);

}