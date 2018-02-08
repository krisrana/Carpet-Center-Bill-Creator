/*   
     Name:      Krishna rana
     course:    CIS 160 ME1
     Date:      03/09/2016   
     Program:   Passaic county Community Carpet Center 
     description:  This program will gentrate customer's bill based on the input of 
	 			   name, id, length, width,price per squarefeet,and discount for passaic county community carpet center.
*/
#include <iostream>
#include<string>
#include<cstdio>
#include<iomanip>
#include<cmath>

using namespace std;
//Function prototype
void getdata(string& ,int&,int&,int&,int&,int&,int&,float&,float&);
void calculations(float&,float&,float&,float&,float&,int&,float&,float&);
	void calcinstalled();
	void calcsubtotal();
	void calctotal();
void showresult(string&,int&,int&,int&,int&,int&,int&,float&,float&,float,float,float,float&,float&);
	void heading();
	void measurements();
	void charges();
//Main() function defination
int main()
{	//Declarlatoin/ definations
	string name;
	int id,lengthin,lengthft,widthin,widthft,area;
	float cost, discount,installedprice,subtotal,total,discounts,tax;
	getdata(name,id,lengthin,lengthft,widthin,widthft,area,cost,discount);
	calculations(cost,installedprice,discount,subtotal,total,area,discounts,tax);
	showresult(name,id,lengthin,lengthft,widthin,widthft,area,cost,discount,installedprice,subtotal,total,discounts,tax);
	return 0;
}
// Function getdata 
void getdata(string& name,int& id,int& lengthin,int& lengthft,int& widthin,int& widthft,int&area,float&cost,float& discount)
{	// Input section
	cout<<"customer's Name			:";getline(cin,name);
	cout<<"Customer's ID#			:";cin>>id;
	cout<<"Length of Room			:Feet	:";cin>>lengthft;// Length feet
	cout<<"\t\t\t\t:Inches:";cin>>lengthin;					//	Length inches
	cout<<"Width of Room			:Feet	:";cin>>widthft;//	Width feet
	cout<<"\t\t\t\t:Inches:";cin>>widthin;					//	Width inches
	cout<<"Cost/Square Foot		:";cin>>cost;
	cout<<"Percentage of Discount		:";cin>>discount;
	area = (((float)lengthin/12)+lengthft)*(((float) widthin/12)+widthft);// formula for area calculation and flaot division.
	area= ceil(area);
}
// Function calculations
void calculations(float& cost,float& installedprice, float& discount,float& subtotal,float& total,int& area,float& discounts, float& tax)
{	// processing/ calculation section
	const float LABOR = 1.65;
	const float TAX = 0.07;
	// sub-functions of calculation	
	void calcinstalled();//installed price, calculation of cost and labor
	{
		installedprice = (cost*area)+ (LABOR*area);
	}
	
	void calcsubtotal();// subtotal, calculation of installed price minus discount
	{
		discounts= installedprice * (discount/100);
		subtotal = installedprice - discounts;
	}
	
	void calctotal();// total, calculation of subtotal with tax. final total.
	{	
		tax = subtotal * TAX;
		total = subtotal + tax;
	}
}
// Function showresult
void showresult(string& name,int& id,int& lengthin,int& lengthft,int& widthin,int& widthft,int& area,float& cost,float& discount,
				float installedprice,float subtotal,float total,float& discounts,float& tax)
{	
	// constant function
	const float LABOR = 1.65;
	const float TAX = 0.07;	
	// sub-function of showresult
	//output section
	void heading();// heading function for header output
	{
		string sign = ("/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/");
		cout<<"\n\n\n"<<sign<<endl;
		cout<<"\t\tPassaic County Community Carpet Center"<<endl;
		cout<<"\t\t\t  123 Main Street"<<endl;
		cout<<"\t\t\tPaterson, NJ 07505"<<endl;
		cout<<sign<<endl;
		cout<<"Customer Name:\t\t"<<name<<endl;
		cout<<"Customer Number:\t"<<id<<endl;
	}
	
	void measurements();// information of measure inputed
	{
		string dash = "--------------------------------------------------------------------\n";
		cout<<"\nRoom Measurements:\n";
		cout<<"\t\t\tLength:	"<<lengthft<<"'"<<lengthin<<"\""<<endl;
		cout<<"\t\t\tWidth:	"<<widthft<<"'"<<widthin<<"\""<<endl;
		cout<<"\t\t\tArea:	"<<area<<" Sq/Ft"<<endl;
		cout<<dash<<endl;
	}
	
	void charges();// final output with footing.
	{	
		cout<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(2);
		string dash = "---------------------------------------------------------------------\n";
		cout<<"\nCharges:\n";
		cout<<"\tDescription\t\tCost/SQ Ft\t\tCharges/Room"<<endl;
		cout<<"\t___________\t\t__________\t\t____________"<<endl;
		cout<<"\tCarpet\t\t\t$"<<cost<<"\t\t\t$"<<cost*area<<endl;
		cout<<"\tLabor\t\t\t$"<<LABOR<<"\t\t\t$"<<LABOR*area<<endl;
		cout<<"\t\t\t\t\t\t\t___________"<<endl;
		cout<<"\tInstalled Price\t\t\t\t\t$"<<installedprice<<endl;
		cout<<"\tDiscount\t\t"<<discount<<"%\t\t\t$"<<discounts<<endl;
		cout<<"\t\t\t\t\t\t\t___________"<<endl;
		cout<<"\tSubtotal\t\t\t\t\t$"<<subtotal<<endl;
		cout<<"\tTax\t\t\t\t\t\t$"<<tax<<endl;
		cout<<"\t\t\t\t\t\t\t___________"<<endl;
		cout<<"\tTotal\t\t\t\t\t\t$"<<total<<endl;
		cout<<dash;
		cout<<"\tThank You for Using PCCCC as Your Professional Carpet Store";// footing
		
	}
}
