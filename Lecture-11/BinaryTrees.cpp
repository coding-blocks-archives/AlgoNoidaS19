// BinaryTrees
#include <iostream>
#include <queue>
using namespace std;
// ------------- Binary Tree Node ------------------
class node{
public:
	int data;
	node* left;
	node* right;

	node(int d):data(d),left(NULL),right(NULL){}
};
// ------------------------------------------

node* CreateTree(){
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}
	
	node* root = new node(data);
	root->left = CreateTree();
	root->right = CreateTree();
	return root;
}

void PreOrder(node* root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(node* root){
	if(root==NULL){
		return;
	}

	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

void PostOrder(node* root){
	if(root==NULL){
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int CountNodes(node* root){
	if(root == NULL){
		return 0;
	}

	return CountNodes(root->left) + CountNodes(root->right) + 1;
}

int height(node* root){
	if(root == NULL){
		return 0;
	}

	int left = height(root->left);
	int right = height(root->right);
	return max(left,right)+1;
}

int Diameter(node* root){
	if(root == NULL){
		return 0;
	}

	int op1 = height(root->left) + height(root->right);
	int op2 = Diameter(root->left);
	int op3 = Diameter(root->right);
	return max(op1,max(op2,op3));
}

class Pair{
public:
	int diameter;
	int height;
};

Pair FastDiameter(node* root){
	Pair p;
	// Base case
	if(root == NULL){
		p.height = p.diameter = 0;
		return p;
	}
	// Recursive case
	Pair left = FastDiameter(root->left);
	Pair right = FastDiameter(root->right);

	// height of the tree
	p.height = max(left.height,right.height)+1;

	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;
	p.diameter = max(op1,max(op2,op3));
	return p;
}

// LEVEL ORDER PRINT
void PrintLevelOrder(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}

void MirrorTree(node* root){
	// Base case
	if(root==NULL){
		return;
	}

	swap(root->right,root->left);
	MirrorTree(root->left);
	MirrorTree(root->right);
}

int i = 0;
int pre[]={8,10,1,6,4,7,3,14,13};

node* BuildTree(int *in,int s,int e){
	if(s>e){
		return NULL;
	}
	int data = pre[i];
	node* root = new node(data);
	i++;
	int k=-1;
	for(int j=s;j<=e;j++){
		if(in[j] == data){
			k = j;
			break;
		}
	}
	root->left = BuildTree(in,s,k-1);
	root->right = BuildTree(in,k+1,e);
	return root;

}

int main(){
	// node* root = CreateTree();
	int in[]={1,10,4,6,7,8,3,13,14};
	int n=sizeof(in)/sizeof(int);
	node* root = BuildTree(in,0,n-1);
	// PreOrder(root);
	// cout<<endl;
	// InOrder(root);
	// cout<<endl;
	// PostOrder(root);
	// cout<<endl;
	PrintLevelOrder(root);
	MirrorTree(root);
	PrintLevelOrder(root);

	// cout<<"Nodes : "<<CountNodes(root)<<endl;
	// cout<<"Height : "<<height(root)<<endl;
	// cout<<"Diameter : "<<Diameter(root)<<endl;

	// Pair p = FastDiameter(root);
	// cout<<"Fast Height : "<<p.height<<endl;
	// cout<<"Fast Diameter : "<<p.diameter<<endl;









	return 0; 
}