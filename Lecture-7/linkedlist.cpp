#include<iostream>
using namespace std;

class node
{
   public:
   	int data;
   	node *next;

   	node(int d)
   	{
       data=d;
       next=NULL;
   	}
};


void InsertAtFront(node* &head,int data){
    if(head==NULL){
      node* n = new node(data);
      head = n;
    }
    else{ 
      node* n = new node(data);
      n->next = head;
      head = n;
    }
}

void Print(node* head){
  
  while(head){
    cout<<head->data<<"-->";
    head=head->next;
  }
  cout<<endl;

}

node* mid(node* head){
  node* fast = head->next;
  node* slow = head;

  while(fast){
    fast=fast->next;
    if(fast!=NULL){
      fast = fast->next;
      slow = slow->next;
    }
  }
  return slow;
}

node* merge(node* a,node* b){
  // Base case
  if(a==NULL){
    return b;
  }
  if(b==NULL){
    return a;
  }
  // Recursive case
  node* c;
  if(a->data<b->data){
    c = a;
    c->next = merge(a->next,b);
  }
  else{
    c = b;
    c->next = merge(a,b->next);
  }
  return c;
}

node* mergesort(node* head){
  // base case
  if(head==NULL || head->next == NULL){
    return head;
  }
  // Divide 
  node* m = mid(head);
  node* a = head;
  node* b = m->next;
  m->next = NULL;
  // Sort
  a = mergesort(a);
  b = mergesort(b);
  // Merge
  node* newHead = merge(a,b);
  return newHead;
}

void ReverseLL(node* &head){
  node* c = head;
  node* p = NULL;
  node* n;

  while(c){
    // Work
    n = c->next;
    c->next = p;
    p = c;
    c = n;
  }
  head = p;
}

int length(node* head){
  int count = 0;
  while(head){
    count++;
    head = head->next;
  }
  return count;
}

void BubbleSortLL(node* &head){
  int len = length(head);

  node* c;
  node* p;
  node* n;
  for(int i=0;i<=len-2;i++){
    c = head;
    p = NULL;
    while(c && c->next){
      n = c->next;
      if(c->data>n->data){
          // Swapping hogi
          if(p == NULL){
            c->next = n->next;
            n->next = c;
            head = p = n;
          }
          else{
            c->next = n->next;
            n->next = c;
            p->next = n;
            p = n;
          }
      }
      else{
        // Swapping nahi hogi
        p = c;
        c = c->next;
      }

    }
  }
}


int main()
{
  node* head = NULL;
  InsertAtFront(head,0);
  InsertAtFront(head,1);
  InsertAtFront(head,5);
  InsertAtFront(head,4);
  InsertAtFront(head,3);
  InsertAtFront(head,2);

  Print(head);
  BubbleSortLL(head);
  Print(head); 
	return 0;
}