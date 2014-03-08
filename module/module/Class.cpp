#include "stdafx.h"
#include "Class.h"

#include <iostream>
using        namespace   std;



//>>>>>>>>>>>>>>>>>>>>>>>>>>>start ���� ���� ���� ���캯���Ķ����ʵ��>>>>>>>>>>>>>>>>>>>>>>>>>>>//
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
//<<<<<<<<<<<<<<<<<<<<<<<<<<<end ���� ���� ���� ���캯���Ķ����ʵ��<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//


//>>>>>>>>>>>>>>>>>>>>>>>>>>>start ���� ���� ���� ���캯���Ķ����ʵ��>>>>>>>>>>>>>>>>>>>>>>>>>>>//
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
	//�������Ĺ��캯��
	Base(int age, int weight)
	{
		m_age = age;
		m_weight = weight;

		m_pName = new char[20];
		if (NULL == m_pName)
		{
			cout<< "new the name char failed"<<endl;
		}
		
		cout <<"Base��int age,int weight�� constructor" <<endl;

	};



	//���ƹ��캯����Ҳ��Ϊ�������캯����
	//���ƹ��캯������Ϊ�����������ã����ڸ���һ���Ѵ��ڵĶ����Ƴ�һ���µĸ���Ķ���
	//һ���ں����лὫ�Ѵ��ڶ�������ݳ�Ա��ֵ����һ�ݵ��´����Ķ�����
	//��û����ʾ��д���ƹ��캯������ϵͳ��Ĭ�ϴ���һ�����ƹ��캯��������������ָ���Աʱ��
	//��ϵͳĬ�ϴ����ø��ƹ��캯������ڷ��գ�����ԭ�����ѯ �й� ��ǳ������ �������������������
	Base( const Base & tmp )
	{
		m_age = tmp.m_age;
		m_weight = tmp.m_weight;
		m_pName = tmp.m_pName;
	};

	// �Ⱥ����������
	// ע�⣬������Ƹ��ƹ��캯������=�ұߵı�������ֵ���Ƹ��Ⱥ���ߵĶ����������ڹ��캯�����Ⱥ��������ߵĶ�������Ѿ�������
	// ��û����ʾ��д=��������أ���ϵͳҲ�ᴴ��һ��Ĭ�ϵ�=��������أ�ֻ��һЩ�����Ŀ�������
	Base& operator= (const Base & base)
	{
		// ���ȼ��Ⱥ��ұߵ��Ƿ������ߵĶ��󱾣����Ǳ�������,��ֱ�ӷ���	
		if (this == &base)
		{
			return *this;
		}

		// ���ƵȺ��ұߵĳ�Ա����ߵĶ�����
		this->m_age = base.m_age;
		this->m_weight = base.m_weight;
		this->m_pName = base.m_pName;

		// �ѵȺ���ߵĶ����ٴδ���
		// Ŀ����Ϊ��֧������ eg:    a=b=c ϵͳ�������� b=c
		// Ȼ������ a= ( b=c�ķ���ֵ,����Ӧ���Ǹ���cֵ���b����)    
		return *this;

	}

	// ����ת�����캯��������һ��ָ�������͵Ķ��󴴽�һ������Ķ���
	// ���磺���潫����һ��double���͵Ķ��󴴽���һ��Complex����
	Base::Base(double age)
	{
		m_age = age;
		m_weight = 0;
		m_pName = NULL;

	}


};

void TestClass(void)
{
	////���Թ��캯��;
	////����͸��඼������;
	//animal a(1,10,100);
	//dog DogTom(a,30,300);

	//���Ա����캯�����ء��������캯�����Ⱥ�����;
	// �������޲ι��캯�������ݳ�Ա��ֵ����Ϊ0.0
	Base c1,c2;

	// ����һ�㹹�캯�������ݳ�Ա��ֵ����Ϊָ��ֵ
	Base c3(30,300);
	// Ҳ����ʹ���������ʽ
	//Base c3 = Base(30,300);

	//    ��c3�����ݳ�Ա��ֵ��ֵ��c1
	//    ����c1�Ѿ����ȱ��������ʴ˴���������κι��캯��
	//    ֻ����� = ����������غ���
	c1 = c3;

	// !!! ��������ת�����캯��  ----�����������ת�����캯����������ת��
	//     ϵͳ���ȵ�������ת�����캯������5.2����Ϊһ���������ʱ����Ȼ����õȺ���������أ�������ʱ����ֵ��c1
	c2 = 20;

	// ���ÿ������캯��( ���������ֵ��÷�ʽ) 
	Base c5(c2);
	Base c4 = c2;  // ע��� =�������������,����Ⱥ���ߵĶ����������Ѿ�����������Ҫ���ÿ������캯��������Ϊc2

}