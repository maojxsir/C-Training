#include "stdafx.h"
#include "Class.h"

#include <iostream>
using        namespace   std;



//>>>>>>>>>>>>>>>>>>>>>>>>>>>start 测试 子类 父类 构造函数的定义和实现>>>>>>>>>>>>>>>>>>>>>>>>>>>//
class animal{

private:

	int m_Type;

public:
	int m_high;

	int m_weight;

	animal(int dat,int high, int weight){
		m_Type = dat;
		m_high = high;
		m_weight = weight;

		cout<< "animal constructor" <<endl;

	};

};
class dog:public animal{

private:
	
	int m_data;

public:
	int m_high;

	int m_weight;

	int m_age;
	
	dog( const animal & pre,int dat, int age):animal(2,20,200)
	{
		m_data = dat;
		m_high = pre.m_high;
		m_weight = pre.m_weight;
		m_age = age;
		cout << "dog constructor" <<endl;
	};

};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<end 测试 子类 父类 构造函数的定义和实现<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//


//>>>>>>>>>>>>>>>>>>>>>>>>>>>start 测试 子类 父类 构造函数的定义和实现>>>>>>>>>>>>>>>>>>>>>>>>>>>//
class Base{
public:
	int m_age;
	int m_weight;
	char * m_pName;
	Base(){
		m_weight = 0;
		m_age = 0;
		m_pName = NULL;
	};
	//带参数的构造函数
	Base(int age, int weight)
	{
		m_age = age;
		m_weight = weight;

		m_pName = new char[20];
		if (NULL == m_pName)
		{
			cout<< "new the name char failed"<<endl;
		}
		
		cout <<"Base（int age,int weight） constructor" <<endl;

	};



	//复制构造函数（也称为拷贝构造函数）
	//复制构造函数参数为类对象本身的引用，用于根据一个已存在的对象复制出一个新的该类的对象，
	//一般在函数中会将已存在对象的数据成员的值复制一份到新创建的对象中
	//若没有显示的写复制构造函数，则系统会默认创建一个复制构造函数，但当类中有指针成员时，
	//由系统默认创建该复制构造函数会存在风险，具体原因请查询 有关 “浅拷贝” 、“深拷贝”的文章论述
	Base( const Base & tmp )
	{
		m_age = tmp.m_age;
		m_weight = tmp.m_weight;
		m_pName = tmp.m_pName;
	};

	// 等号运算符重载
	// 注意，这个类似复制构造函数，将=右边的本类对象的值复制给等号左边的对象，它不属于构造函数，等号左右两边的对象必须已经被创建
	// 若没有显示的写=运算符重载，则系统也会创建一个默认的=运算符重载，只做一些基本的拷贝工作
	Base& operator= (const Base & base)
	{
		// 首先检测等号右边的是否就是左边的对象本，若是本对象本身,则直接返回	
		if (this == &base)
		{
			return *this;
		}

		// 复制等号右边的成员到左边的对象中
		this->m_age = base.m_age;
		this->m_weight = base.m_weight;
		this->m_pName = base.m_pName;

		// 把等号左边的对象再次传出
		// 目的是为了支持连等 eg:    a=b=c 系统首先运行 b=c
		// 然后运行 a= ( b=c的返回值,这里应该是复制c值后的b对象)    
		return *this;

	}

	// 类型转换构造函数，根据一个指定的类型的对象创建一个本类的对象
	// 例如：下面将根据一个double类型的对象创建了一个Complex对象
	Base::Base(double age)
	{
		m_age = age;
		m_weight = 0;
		m_pName = NULL;

	}


};

void TestClass(void)
{
	////测试构造函数;
	////子类和父类都带参数;
	//animal a(1,10,100);
	//dog DogTom(a,30,300);

	//测试报构造函数重载、拷贝构造函数、等号重载;
	// 调用了无参构造函数，数据成员初值被赋为0.0
	Base c1,c2;

	// 调用一般构造函数，数据成员初值被赋为指定值
	Base c3(30,300);
	// 也可以使用下面的形式
	//Base c3 = Base(30,300);

	//    把c3的数据成员的值赋值给c1
	//    由于c1已经事先被创建，故此处不会调用任何构造函数
	//    只会调用 = 号运算符重载函数
	c1 = c3;

	// !!! 调用类型转换构造函数  ----这个函数类型转换构造函数用于类型转换
	//     系统首先调用类型转换构造函数，将5.2创建为一个本类的临时对象，然后调用等号运算符重载，将该临时对象赋值给c1
	c2 = 20;

	// 调用拷贝构造函数( 有下面两种调用方式) 
	Base c5(c2);
	Base c4 = c2;  // 注意和 =运算符重载区分,这里等号左边的对象不是事先已经创建，故需要调用拷贝构造函数，参数为c2

}