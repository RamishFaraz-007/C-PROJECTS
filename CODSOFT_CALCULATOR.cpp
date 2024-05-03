#include <iostream>
using namespace std;
int main()
{
	cout<<"< CODSOFT CALCULATOR >"<<endl<<"_____________________"<<endl<<endl;
	
	double num1,num2; 
	char op;
	cout<<"ENTER FIRST NUMBER:";
	cin>>num1;
	cout<<"ENTER SECOND NUMBER:";
	cin>>num2;
	cout<<"NOW SELECT THE OPERATOR(+,*,-,/)";
	cin>>op;
	if(op=='+')
	{
		cout<<num1<<"+"<<num2<<"="<<num1+num2;
	}
	else if(op=='-')
	{
		cout<<num1<<"-"<<num2<<"="<<num1-num2;
	}
	else if(op=='/')
	{
		cout<<num1<<"/"<<num2<<"="<<num1/num2;
	}
	else if(op=='*')
	{
		cout<<num1<<"*"<<num2<<"="<<num1*num2;
	}
	else
	{
		cout<<"invalid operator!"<<endl<<endl;
		cout<<"program terminated!";
	}
}
