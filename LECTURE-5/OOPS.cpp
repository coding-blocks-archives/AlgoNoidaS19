// OOPS
#include <iostream>
#include <cstring>
using namespace std;

// ----------------- BLUEPRINT/CLASS -------------
class Car{
private:
	int price;
public:
	static int count;
	char* name;
	int model;
	int seats;
	const int tyres;

	// DEFAULT CONSTRUCTOR
	Car():tyres(4),name(NULL){
		// name =NULL;
		count++;
		cout<<"In DEFAULT CONSTRUCTOR"<<endl;
	}

	// Paramterized constructor
	Car(char *n,int p,int s,int m):tyres(4),price(p){
		cout<<"In Paramterized constructor"<<endl;
		name = new char[strlen(n)+1];
		strcpy(name,n);
		// price = p;
		seats = s;
		model = m;
		count++;
	}

	// COPY CONSTRUCTOR 
	Car(Car &X):tyres(4){
		cout<<"In Copy constructor"<<endl;
		price = X.price;
		model = X.model;
		seats = X.seats;
		name  = new char[strlen(X.name)+1];
		strcpy(name,X.name);
		count++;
	}

	// COPY ASSIGNMENT 
	void operator=(Car X){
		cout<<"In Copy Assignment"<<endl;
		price = X.price ;
		seats = X.seats ;
		model = X.model ;
		if(name!=NULL){
			delete []name;
			name = NULL;
		}
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}

	// Operator Overloading +=
	void operator+=(Car &X){
		char * oldname = name;
		name = new char[strlen(name)+strlen(X.name)+1];
		strcpy(name,oldname);
		strcat(name,X.name);
		delete []oldname;
		price += X.price;
		model += X.model;
		seats += X.seats;
	}

	void print()const{
		cout<<"Name  : "<<name<<endl;
		cout<<"Price : "<<price<<endl;
		cout<<"Model : "<<model<<endl;
		cout<<"Tyres : "<<tyres<<endl;
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

	int GetPrice()const{
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


	~Car(){
		cout<<"Deleting Car : "<<name<<endl;
		count--;
	}
};

int Car::count = 0;

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
	// Car e(d);
	Car e;
	e = d; // Copy Assignment 

	e.name[0]='T';
	a+=b;

	Car *f = new Car("Maruti",400,2,2111);

	(*f).SetName("Mahindra");

	a.print();
	b.print();
	c.print();
	d.print();
	e.print();
	(*f).print();
	cout<<"No of cars : "<<Car::count<<endl;
	delete f;
	cout<<"No of cars : "<<Car::count<<endl;





	return 0; 
}