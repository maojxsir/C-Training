// train.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include <stdlib.h>
using namespace std;

class test{
public:
	int v;
	/*构造函数*/
	test():v(0){}
	test(const int &a):v(a){}
	test(const test &t1):v(t1.v){} 

	/*以下重载小于号 < */
	//比较两个对象的大小 
	bool operator<(const test &t1) const{ 
		return (v < t1.v);
	}
	//比较对象和int的大小 
	bool operator<(const int &t1) const{ 
		return (v < t1);
	}
	//友元函数，比较int和对象的大小 
	friend inline bool operator<(const int &a, const test & t1){
		return (a < t1.v);
	}

	/*以下重载赋值号 = */
	//对象间赋值 
	test & operator=(const test &t1){
		v = t1.v;
		return *this;
	}
	//int赋值给对象 
	test & operator=(const int &t1){
		v = t1;
		return *this;
	}

	/*以下重载加号 + */
	//对象加上 int 
	test operator+(const int & a){
		test t1;
		t1.v = v + a;
		return t1;
	}
	//对象加对象 
	test operator+(test &t1){
		test t2;
		t2.v = v + t1.v;
		return t2;
	}

	/*以下重载加等号 += */  
	//对象加上对象 
	test &operator+=(const test &t1){
		v += t1.v;
		return *this;
	}  
	//对象加上int
	test &operator+=(const int &a){
		v += a;
		return *this;
	}

	/*以下重载双等号 == */  
	//对象==对象 
	bool operator==(const test &t1)const{
		return (v == t1.v);
	}  
	//对象==int
	bool operator==(const int &t1)const{
		return (v == t1);
	}  

	/*以下重载 输入>> 输出<< */
	/*友元函数，输出对象*/
	friend inline ostream & operator << (ostream & os, test &t1){
		cout << "class t(" << t1.v << ")" << endl;
		return os;
	}
	/*友元函数，输入对象*/
	friend inline istream & operator >> (istream & is, test &t1){
		cin >> t1.v;
		return is;
	}
};




int _tmain(int argc, _TCHAR* argv[])
{

	test T0, T1(3);
	test T2(T1);
	cout << T0 << T1 << T2;
	cin >> T1;
	T2 = T1;
	T2 += T1;
	T1 += 10;
	cout << T2;
	if(T1 < T2) cout << "T1 < T2"; 
	else if(T1 == T2) cout << "T1 = T2";
	else /* t1 > t2*/ cout << "T1 > T2"; 
	cout <<endl;
	system("pause");
	

	//Sleep(10);
	HANDLE hevent, hevent2;
	hevent = CreateEvent(NULL, TRUE, FALSE ,"GPS");
	hevent2 = CreateEvent(NULL, TRUE,FALSE, "GPS");
	system("Pause");

	return 0;

}

