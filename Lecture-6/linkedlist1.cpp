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




class linkedlist
{
   public:
   	node *head;
   	node *tail;

   	linkedlist()
   	{
   		head=NULL;
   		tail=NULL;
   	}

   	int length()
   	{
   		node *temp=head;
   		int count=0;
   		while(temp!=NULL)
   		{
   			count++;
   			temp=temp->next;
   		}
   		return count;
   	}


   	void insertatbeg(int d)
   	{
   		if(head==NULL)
   		{
   			node *n=new node(d);
   			head=n;
   			tail=n;
   		}
   		else 
   		{
   			node *n=new node(d);
   			n->next=head;
   			head=n;
   		}
   	}

   	void insertatend(int d)
   	{
   		if(head==NULL)
   		{
   			node *n=new node(d);
   			head=n;
   			tail=n;
   		}
        else 
        {
        	node *n=new node(d);
        	tail->next=n;
        	tail=n;
        }

   	}

   	void insertatpos(int d,int pos)
   	{
        if(pos==0)
        {
        	insertatbeg(d);
        }
        else if(pos>=length())
        {
        	insertatend(d);
        }
        else
        {
        	node* temp=head;
        	int p=1;
            while(p<=pos-1)
            {
            	temp=temp->next;
            	p++;
            }
            node *n=new node(d);
            n->next=temp->next;
            temp->next=n;
        }
   	}


   	void deleteatfront()
   	{
   		if(head==NULL)
   		{
           return;
   		}
   		else if(head->next==NULL)
   		{
   			delete head;
            head=NULL;
            tail=NULL;
   		}
   		else 
   		{
            node *temp=head;
            head=head->next;
            delete temp;

   		}
   	}

    void deleteatend()
    {
    	if(head==NULL)
    	{
    		return;
    	}

    	else if(head->next==NULL)
    	{
    		delete head;
    		head=NULL;
    		tail=NULL;
    		return;
    	}
    	else
    	{
    		node *temp=head;
    		while(temp->next!=tail)
    		{
    			temp=temp->next;
    		}
    		temp->next=NULL;
    		delete tail;
    		tail=temp;
    	}
    }
    
    void deleteatpos(int pos)
    {
    	if(pos==0)
    	{
    		deleteatfront();
    	}

    	else if(pos>=length())
    	{
    		deleteatend();
    	}

    	else 
    	{
    		node *temp=head;
    		int p=1;
    		while(p<=pos-1)
    		{
    			temp=temp->next;
    			p++;
    		}
    		node *n=temp->next;
    		temp->next=n->next;
    		delete n;
    	}
    }

    node* search(int d)
    {
    	node *temp=head;
    	while(temp!=NULL)
    	{
    		if(temp->data==d)
    		{
    			return temp;
    		}
    		temp=temp->next;
    	}
    	return NULL;
    }


    node* searchrec(node *h,int d)
    {
    	if(h==NULL)
    	{
    		return NULL;
    	}

    	else if(h->data==d)
    	{
    		return h;
    	}
    	return searchrec(h->next,d);
    }



   	void printll()
   	{
   		node *temp=head;
   		while(temp!=NULL)
   		{
   			cout<<temp->data<<" ";
   			temp=temp->next;
   		}
   		cout<<endl;
   	}

} ;


int main()
{
    
    linkedlist l;
    l.insertatbeg(5);
    l.insertatbeg(4);
    l.insertatbeg(3);
    l.insertatbeg(2);
    l.insertatbeg(1);
    l.insertatbeg(0);
    l.insertatend(6);
    l.insertatpos(100,1);
    l.deleteatfront();
    l.deleteatend();
    l.deleteatpos(1);
     l.printll();
    int data;
    cin>>data;
    // cout<<l.length()<<endl;
    if(l.search(data)==NULL)
    {
       cout<<"element not found"<<endl;
    }
    else 
    {
    	cout<<"element found"<<endl;
    }


    if(l.searchrec(l.head,data)==NULL)
    {
    	cout<<"element not found"<<endl;
    }
    else 
    {
    	cout<<"element found"<<endl;
    }





   
	return 0;
}