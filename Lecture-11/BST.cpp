#include <iostream>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d):data(d),left(NULL),right(NULL){

	}
};

node* InsertInBST(node* root,int data){
	if(root==NULL){
		root = new node(data);
		return root;
	}

	if(data<=root->data){
		root->left = InsertInBST(root->left,data);
	}
	else{
		root->right = InsertInBST(root->right,data);
	}
	return root;
}


node* BuildTree(){
	node* root=NULL;

	int data;
	cin>>data;

	while(data!=-1){
		root = InsertInBST(root,data);
		cin>>data;

	}
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

bool isBST(node* root,int min=INT_MIN,int max = INT_MAX){
	// Base case
	if(root==NULL){
		return true;
	}
	// Recursive case
	if(root->data<=max && root->data>=min && isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){
		return true;
	}
	else{
		return false;
	}
}

class Pair{
public:
	int height;
	bool balanced;
};

Pair isBalanced(node* root){
	Pair p;
	// base case
	if(root==NULL){
		p.height=0;
		p.balanced = true;
		return p;
	}

	// Recursive case
	Pair left = isBalanced(root->left);
	Pair right = isBalanced(root->right);

	//Height
	p.height = max(left.height,right.height)+1;

	if(left.balanced && right.balanced && abs(left.height-right.height)<=1){
		p.balanced = true;
	}
	else{
		p.balanced = false;
	}
	return p;
}

node* ArrayToBST(int* arr,int s,int e){
	// Base case
	if(s>e){
		return NULL;
	}
	// Recursive case
	int mid=(s+e)/2;
	node* root = new node(arr[mid]);
	root->left = ArrayToBST(arr,s,mid-1);
	root->right = ArrayToBST(arr,mid+1,e);
	return root;
}

node* LevelOrderInput(){
	node* root = NULL;
	cout<<"Enter root data : ";
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}
	root = new node(data);

	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		cout<<"Enter children of "<<temp->data<<" ";
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1){
			temp->left = new node(c1);
			q.push(temp->left);
		}
		if(c2!=-1){
			temp->right = new node(c2);
			q.push(temp->right);
		}
	}
	return root;
}

int main(){

	// node* root=BuildTree();
	int arr[]={1,3,5,7,8,9,10,11,12};
	int n = sizeof(arr)/sizeof(int);
	// node* root = ArrayToBST(arr,0,n-1);
	node* root = LevelOrderInput();

	// PreOrder(root);
	// cout<<endl;
	// InOrder(root);
	// cout<<endl;
	// PostOrder(root);
	// cout<<endl;
	PrintLevelOrder(root);
	// if(isBST(root)){
	// 	cout<<"BST"<<endl;
	// }
	// else{
	// 	cout<<"Not a BST"<<endl;
	// }

	Pair p = isBalanced(root);
	if(p.balanced){
		cout<<"balanced"<<endl;
	}
	else{
		cout<<"Not balanced"<<endl;
	}






	return 0; 
}