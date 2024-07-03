#include<iostream>
using namespace std;

const int MAX=20;
class Busqueda
{
	int numero_buscado[MAX];
	int n;
public:
	bool linearSearch(int key);
	bool binarySearch(int key);
	void accept(int num);
	void display();
	int fibo(int j);
	bool fibSearch(int key);

};

void Busqueda::accept(int num)
{
	n=num;
	cout<<"\nDigite "<<num<<" elementos, dandole enter al digitar cada opcion  \nllenandolo con numeros aleatorios que desee \n";
	for(int i=0;i<n;i++)
	{
		cin>>numero_buscado[i];
	}
}

void Busqueda::display()
{
	cout<<"\nLos numeros que se encuentran son:\n ";
	for(int i=0;i<n;i++)
	{
		cout<<numero_buscado[i]<<"\t";
	}
}

bool Busqueda::linearSearch(int key)
{
	for(int i=0;i<n;i++)
	{
		if(numero_buscado[i]==key)
			return true;
	}
	return false;
}

bool Busqueda::binarySearch(int key)
{
	int mid;
	int low=0;
	int high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==numero_buscado[mid])
		{
			return true;
		}
		if(key<numero_buscado[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return false;
}

int Busqueda::fibo(int j)
{
	if(j==0)
		return 0;
	if(j==1)
		return 1;
	else
		return ((fibo(j-1))+(fibo(j-2)));
}

bool Busqueda::fibSearch(int key)
{
	int f1,f2,j,mid;
	j=1;
	while(fibo(j)<=n)
		j++;


	f1=fibo(j-2);
	f2=fibo(j-3);
	mid=n-f1+1;

	while(key!=numero_buscado[mid])
	{
		if(key>numero_buscado[mid])
		{
			if(f1==1)
				break;
			mid=mid+f2;
			f1=f1-f2;
			f2=f2-f1;
		}
		else
		{
			if(f2==0)
				break;
			mid=mid-f2;
			int temp=f1-f2;
			f1=f2;
			f2=temp;
		}
	}
	if(numero_buscado[mid]==key)
		return true;
	else
		return false;
}
int main()
{
	Busqueda s1;
	int choice;
	int key,n;
	do
	{
		cout<<"\n1. Linear Search";
		cout<<"\n2. Binary Search";
		cout<<"\n3. Fibonacci Search";
		cout<<"\n0. Salir";
		cout<<"\nChoice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\nDigite el numero de elementos que desea ";
			cin>>n;
			s1.accept(n);
			cout<<"\nIngrese el numero que desea buscar ";
			cin>>key;
			if(s1.linearSearch(key))
				cout<<"\nNumero buscado... "<<key<<" ... Sí se encuentra";
			else
				cout<<"\nNumero buscado... "<<key<<" ... No se encuentra";
			break;

		case 2:
			cout<<"\nDigite el numero de elementos que desea ";
			cin>>n;
			s1.accept(n);
			cout<<"\nIngrese el numero que desea buscar ";
			cin>>key;
			if(s1.binarySearch(key))
				cout<<"\nNumero buscado... "<<key<<" ... Sí se encuentra";
			else
				cout<<"\nNumero buscado... "<<key<<" ... No se encuentra";
			break;
		case 3:
			cout<<"\nDigite el número de elementos que desea ";
			cin>>n;
			s1.accept(n);
			cout<<"\nIngrese el numero que desea buscar ";
			cin>>key;
			if(s1.fibSearch(key))
				cout<<"\nNumero buscado... "<<key<<" ... Sí se encuentra";
			else
				cout<<"\nNumero buscado... "<<key<<" ... No se encuentra";
			break;
		}

	}while(choice!=0);


	return 0;
}
