// OOPS
#include <iostream>
#include <cstring>
using namespace std;

// ----------------- BLUEPRINT/CLASS -------------
class Car{
private:
	int price;
public:
	char* name;
	int model;
	int seats;

	// DEFAULT CONSTRUCTOR
	Car(){
		name =NULL;
		cout<<"In DEFAULT CONSTRUCTOR"<<endl;
	}

	// Paramterized constructor
	Car(char *n,int p,int s,int m){
		cout<<"In Paramterized constructor"<<endl;
		name = new char[strlen(n)+1];
		strcpy(name,n);
		price = p;
		seats = s;
		model = m;
	}

	// COPY CONSTRUCTOR 
	Car(Car &X){
		cout<<"In Copy constructor"<<endl;
		price = X.price;
		model = X.model;
		seats = X.seats;
		// name  = new char[strlen(X.name)+1];
		// strcpy(name,X.name);
		name = X.name;
	}

	void print(){
		cout<<"Name  : "<<name<<endl;
		cout<<"Price : "<<price<<endl;
		cout<<"Model : "<<model<<endl;
		cout<<"Seats : "<<seats<<endl<<endl;
	}

	void SetPrice(int p){
		if(p>100 && p<200){
			price = p;
		}
		else{
			price = 110;
		}
	}

	int GetPrice(){
		return price;
	}

	void SetName(char *n){
		if(name!=NULL){
			delete [] name;
			name = NULL;
		}
		name = new char[strlen(n)+1];
		strcpy(name,n);
	}
};
// -----------------------------------------------
int main(){

	Car a;
	// a.price = 100;
	a.SetPrice(-100);
	a.model = 200;
	a.seats = 4;
	// strcpy(a.name,"BMW");
	a.SetName("BMW");
	// cout<<a.GetPrice()<<endl;

	Car b("Audi",500,3,3000);
	Car c("Renault",400,5,2900);
	// To call the copy constructor these are the two
	// ways : 
	// 1. Car d(a);
	// 2. Car d = a;
	Car d(a);
	Car e(d);

	e.name[0]='T';

	a.print();
	b.print();
	c.print();
	d.print();
	e.print();




	return 0; 
}