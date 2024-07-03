
#include "header.h"

using namespace std;

bool Pares(char opening,char closing)
{
if(opening == '(' && closing == ')') return true;
else if(opening == '{' && closing == '}') return true;
else if(opening == '[' && closing == ']') return true;
else if(opening == '<' && closing == '>') return true;
return false;
}
bool Parentesis_balanceados(string exp)
{
	Stack<char> S;
for(int i =0;i<exp.length();i++)
	{
if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == '<')
			S.push(exp[i]);
else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']' || exp[i] == '>')
		{
if(S.empty() || !Pares(S.pop(),exp[i]))
return false;

else
				S.pop();
		}
	}
return S.empty() ? true:false;
}

int main()
{
	string stack_caract;
	cout<<"  ************************************************************\n  ";
	cout<<"Digite una expresión con signos de agrupación para verificar\nque el uso de los mimso sea correcto:\n  ";
	cout<<"  ************************************************************ \n ";
	cin>>stack_caract;

if(Parentesis_balanceados(stack_caract))
		cout<<"\nUso correcto, expresión balanceada\n";

else
		cout<<"\nIncorrecto! Uso inadecuado, la expresión no está balanceada\n";

}
