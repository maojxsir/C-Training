// module.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <string>

using        namespace   std;



#define fx(a,b) a##b; // �����ַ���
#define fxx(a)  #@a; // ˫����
#define fxxx(a) #a;  //������


//
//#include <iostream.h> 

//��ת�ַ���
void     ReverseStr( char * str)     
{   
	char  tmp;   
	int  len;   
	len = strlen(str);   
	for   ( int i = 0 ; i< len / 2; ++i)     
	{   
		tmp  = str [i];   
		str[i] =  str[len - i - 1];   
		str[len - i - 1] = tmp;   
	}     
} 



//����������1
bool isPrime(int n)
{
	if(n < 2) return false;
	if(n == 2) return n;

	for(int i = 3; i*i <= n; i += 2)
		if(n%i == 0) return false;

	return n;//
}
//����������2
int isPrime2(int n)
{
	int i ;

	if (n == 1)
	{
		return 1;
	}
	for (i=2;i<n;i++)
	{
		if (n%i ==0)
		{
			break;
		}
	}
	if ( i>= n)
	{
		return 1;
	}
	else
	{
		return 0;

	}

}


//�ַ���ת��Ϊʮ��������
int myAtoi(const char * str) 
{ 
	int num = 0;              //����ת�������ֵ 
	int isNegative = 0;            //��¼�ַ������Ƿ��и��� 
	int n =0; 
	char *p = (char * )str; 
	if(p == NULL)              //�ж�ָ��ĺϷ��� 
	{ 
		return -1; 
	} 
	while(*p++ != '\0')            //�������ַ����� 
	{ 
		n++; 
	} 
	p = (char * )str; 
	if(p[0] == '-')              //�ж������Ƿ��и��� 
	{ 
		isNegative = 1; 
	} 
	char temp = '0'; 
	for(int i = 0 ; i < n; i++) 
	{ 
		char temp = *p++; 
		if(temp > '9' ||temp < '0')        //�˳��������ַ� 
		{ 
			continue; 
		} 
		if(num !=0 || temp != '0')        //�˳��ַ�����ʼ��0�ַ� 
		{ 
			temp -= 0x30;        //�������ַ�ת��Ϊ��ֵ 
			num += temp *int( pow((float)10 , n - 1 -i) ); 
		} 
	}   
	if(isNegative)                //����ַ������и��ţ�����ֵȡ�� 
	{ 
		return (0 - num); 
	} 
	else 
	{ 
		return num;              //����ת�������ֵ 
	} 
} 
struct A
{
	int x;
	char str;
	float y;
} dat;
A dat1;

//getmemoryʧ��
void getmemory1(char *p)
{
	p = (char *) malloc (100);
	strcpy(p,"hello ,world");
}

void getmemory2(char **p,int num)
{
	*p = (char *) malloc (num);
	
}

struct stda{
	int num1;
	short x;
	short y;
	char z;
	double num;
}stu ,*pstu;


void xyz (char ba[])
{
	int a=sizeof(ba);
}

//copy string ;;
char *strcpy2(char *str1,const char *str2)
{
	
	char *addr = str1;  //��������
	if (str1 == NULL | str2 == NULL)
	{
		return NULL;
	}
	while ((*str1++ = *str2++) != '\0')//��������
		NULL;
	return addr;//��������

}

//ð������, pnDataҪ��������ݣ� nLen���ݵĸ���
int BubbleSort(int* pnData, int nLen)
{
	bool isOk = false;        //���������Ƿ�������ڱ�

	//i��[0,nLen-1)��ʼð�ݣ�ȷ����i��Ԫ��
	for (int i = 0; i < nLen - 1 && !isOk; ++i)
	{
		isOk = true;        //�ٶ�����ɹ�

		//��[nLen - 1, i������Ƿ������һ��С����С��ð�ݸ���ȥ
		for (int j = nLen- 1; j > i; --j)
		{
			if (pnData[j] < pnData[j - 1])    //�������ı�����С������
			{
				int nTemp = pnData[j];
				pnData[j] = pnData[j - 1];
				pnData[j - 1] = nTemp;
				isOk = false;
			}
		}
	}

	return 1;
}
//���Դ��С�˸�ʽ
union test
{
	int num;
	char num3[2];
};

typedef union
{
	long i;
	char k[5];
	char c;
}data_u;

struct data
{
	int cat;
	data_u cow;
	double dog;
}data_t;
data_u max;

//���������ȼ�����
void test()
{
	int x0 = 8>6;
	int x1 = 5+6>1 && 7 <8;
	int a,b;
	//int x2 = a>=b || b<a;
	int x3 ='Y'>'S'?10:5;
	//int x4 = a>b?b<a:a>b;
	int x5 = (a=1)?2:3;
	int x6 = !!0x12345678;
	int x7 = 0x12345678 && ~0x1000;
	

	int (*p)[2],*pp;
	int aa[2][2]={10,11,12};
	p=aa;  //�����ַ
	pp=aa[0]; //�����ַ
	int x8 = **(p+1);
	int x9 = *(pp+2);

}
 

void BitDomin()
{
	union 
	{ 
		struct 
		{ 
			unsigned short s1:3; 
			unsigned short s2:3; 
			unsigned short s3:3; 
		}x; 
		char c; 
	}v;
	v.c=100; 
	printf("%d\n",v.x.s3); 
}


int _tmain(int argc, _TCHAR* argv[])
{
	




	
	
	
	
	
	//&a �����int (*)[5]���� &a + 1 �ƶ� 20���ֽ� �㵽Ϊֹ

	// printf("%d",sizeof(struct data)+sizeof(max));
	//test test1;
	//test1.num = 0x12345678;

	//char numchar ,numchar2;
	//numchar = test1.num3[0];
	//numchar2 = test1.num3[1];
	//char *Pb = (char *)&test1.num;
    string strtest="abcdefg12345678";
	///strtest.

	char pqwe[11] = "1234567890";
	char *pxy="1234567890";
	for(int i = 0; i < strlen(pxy); i++)
	{
		pxy++;
		printf("%d", i);
	}


	//printf("0x%x-0x%x-0x%x-0x%x",Pb[0],Pb[1],Pb[2],Pb[3]);
	char *px = fx("abc","def");
	char pxx = fxx(23);
	char *pxxx = fxxx(4321) ;

	char datalen[]="abcdefg";
	px=datalen;
	int numlen = sizeof (px);//numlen=4;
		numlen = sizeof(*px);// �ر�ע����� numlen=1;
		numlen = sizeof(datalen);//numleb = 8;
	test();
	
	char strx[]="abcdefg";
	ReverseStr(strx);
	int a34d[][4] ={0,0};
	


	char  str10[]="string",str20[7];


	strcpy(str20,"hello");
	strcpy(str10,"hello");
	//str20 = str10;
	//str20="hel";


	unsigned int ad =3;
	int bd=-2;
	int cd= 0;
	while((int)(ad+bd)>0)
	{
		ad=ad+bd;
		cd++;
		if (cd==2013)
		{
			cd++;
		}
	}
	printf("%d",cd);





//=================================ð������==========================================//
	//int nData[10] = {4,10,9,8,7,6,5,4,3,2};    //����10�����ݣ�����
	//BubbleSort(nData, 10);        //����ð������
	//for (int i = 0; i < 10; ++i)        
	//{
	//	printf("%d ", nData[i]);
	//}
	//printf("\n");
	//system("pause");//   ӦƸ������ʱ�䣺2013��7��
//=================================ð������==========================================//
	isPrime2(11);
	isPrime2(23);



	
	char text[10];
	char name[20];
	char *pname;

	char len = sizeof(stda);
//============================�߼��� �� ��λ�� �����𣡣���============================
	int yx =8&&5;  //�߼��룡������
	int yxz = 7 & 5;  //��λ�룡������
	
	//��λ������
	int x=9999;
	int countx = 0;
	while(x)
	{
		countx ++;
		x = x&(x-1);
	}
	// countx ��ֵΪ1�ĸ���
//============================�߼��� �� ��λ�� �����𣡣���============================


	//�Լ���д strcopy ������������
	pname = strcpy2(text,"abcdefghk");
	


//	stu.pxd = name;
	strcpy(name,"jamiyad");
	xyz(name);
	stu.num=99;
	

	char *str = NULL;
	getmemory1(str);
	printf("%s/n",str);
	getmemory2(&str,100);
	strcpy(str,"hello");
	free(str);
	printf("\n str is %s",str);

	
	
	
	
	int a[5]={1,2,3,4,5}; 
	int *ptr0 =(int *) &a;
	int (*p0)[5];
	p0 = &a;
	p0++;
	printf("%d,%d",*(a+1),(&p0)); 

	int *ptr=(int *)(&a+1); 
	ptr0++; 
	int c = *(ptr0);
//	int xx=myAtoi("45423");
	//printf("%d,%d",*(a+1),(&ptr+1)); 


//	char   str[] ="Hello" ;  
	char    *p =  str ;  
	int      n = 10;  
	int x1 = sizeof ( str );
	int x2 = sizeof ( *p )  ;
	int x3 = sizeof ( n ) ;
	
	printf("%d",strlen(str));
	printf("%d",strlen(p));

	return 0;
}

