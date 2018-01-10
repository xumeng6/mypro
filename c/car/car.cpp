#include<iostream>
using namespace::std;

#include"car.h"
void Car::run()
{
	cout<<"Car run"<<endl;
}
void Car::stop()
{
	cout<<"Car stop"<<endl;
}
void Car::setProperty(int price,int carNum)
{
	this->m_price = price;
	this->m_carNum = carNum;	
}
void Car::print()
{
	cout<<"in"<<__func__<<"this= "<<this<<endl;
}

