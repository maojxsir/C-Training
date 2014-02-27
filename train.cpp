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
	/*���캯��*/
	test():v(0){}
	test(const int &a):v(a){}
	test(const test &t1):v(t1.v){} 

	/*��������С�ں� < */
	//�Ƚ���������Ĵ�С 
	bool operator<(const test &t1) const{ 
		return (v < t1.v);
	}
	//�Ƚ϶����int�Ĵ�С 
	bool operator<(const int &t1) const{ 
		return (v < t1);
	}
	//��Ԫ�������Ƚ�int�Ͷ���Ĵ�С 
	friend inline bool operator<(const int &a, const test & t1){
		return (a < t1.v);
	}

	/*�������ظ�ֵ�� = */
	//����丳ֵ 
	test & operator=(const test &t1){
		v = t1.v;
		return *this;
	}
	//int��ֵ������ 
	test & operator=(const int &t1){
		v = t1;
		return *this;
	}

	/*�������ؼӺ� + */
	//������� int 
	test operator+(const int & a){
		test t1;
		t1.v = v + a;
		return t1;
	}
	//����Ӷ��� 
	test operator+(test &t1){
		test t2;
		t2.v = v + t1.v;
		return t2;
	}

	/*�������ؼӵȺ� += */  
	//������϶��� 
	test &operator+=(const test &t1){
		v += t1.v;
		return *this;
	}  
	//�������int
	test &operator+=(const int &a){
		v += a;
		return *this;
	}

	/*��������˫�Ⱥ� == */  
	//����==���� 
	bool operator==(const test &t1)const{
		return (v == t1.v);
	}  
	//����==int
	bool operator==(const int &t1)const{
		return (v == t1);
	}  

	/*�������� ����>> ���<< */
	/*��Ԫ�������������*/
	friend inline ostream & operator << (ostream & os, test &t1){
		cout << "class t(" << t1.v << ")" << endl;
		return os;
	}
	/*��Ԫ�������������*/
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

