// module.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <string>
#include <iostream>

using        namespace   std;



#define fx(a,b) a##b; // 链接字符串
#define fxx(a)  #@a; // 双引号
#define fxxx(a) #a;  //单引号


//
//#include <iostream.h> 

//反转字符串
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



//求素数方法1
bool isPrime(int n)
{
	if(n < 2) return false;
	if(n == 2) return n;

	for(int i = 3; i*i <= n; i += 2)
		if(n%i == 0) return false;

	return n;//
}
//求素数方法2
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


//字符串转换为十进制整数
int myAtoi(const char * str) 
{ 
	int num = 0;              //保存转换后的数值 
	int isNegative = 0;            //记录字符串中是否有负号 
	int n =0; 
	char *p = (char * )str; 
	if(p == NULL)              //判断指针的合法性 
	{ 
		return -1; 
	} 
	while(*p++ != '\0')            //计算数字符串度 
	{ 
		n++; 
	} 
	p = (char * )str; 
	if(p[0] == '-')              //判断数组是否有负号 
	{ 
		isNegative = 1; 
	} 
	char temp = '0'; 
	for(int i = 0 ; i < n; i++) 
	{ 
		char temp = *p++; 
		if(temp > '9' ||temp < '0')        //滤除非数字字符 
		{ 
			continue; 
		} 
		if(num !=0 || temp != '0')        //滤除字符串开始的0字符 
		{ 
			temp -= 0x30;        //将数字字符转换为数值 
			num += temp *int( pow((float)10 , n - 1 -i) ); 
		} 
	}   
	if(isNegative)                //如果字符串中有负号，将数值取反 
	{ 
		return (0 - num); 
	} 
	else 
	{ 
		return num;              //返回转换后的数值 
	} 
} 
struct A
{
	int x;
	char str;
	float y;
} dat;
A dat1;

//getmemory失败
void getmemory1(char *p)
{
	p = (char *) malloc (100);
	strcpy(p,"hello ,world");
}

//getmemory ok
char * getmemory10(unsigned int num)
{
	char *p;
	p = (char *) malloc (num);//！！！若num=0，p会申请到合法指针
	if (NULL == p)
	{
		return 0;
	}
	strcpy(p,"hello ,world");
	return p;
}
//getmemory ok
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
	
	char *addr = str1;  //容易忘记
	if (str1 == NULL | str2 == NULL)
	{
		return NULL;
	}
	while ((*str1++ = *str2++) != '\0')//容易忘记
		NULL;
	return addr;//容易忘记

}

//冒泡排序, pnData要排序的数据， nLen数据的个数
int BubbleSort(int* pnData, int nLen)
{
	bool isOk = false;        //设置排序是否结束的哨兵

	//i从[0,nLen-1)开始冒泡，确定第i个元素
	for (int i = 0; i < nLen - 1 && !isOk; ++i)
	{
		isOk = true;        //假定排序成功

		//从[nLen - 1, i）检查是否比上面一个小，把小的冒泡浮上去
		for (int j = nLen- 1; j > i; --j)
		{
			if (pnData[j] < pnData[j - 1])    //如果下面的比上面小，交换
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
//测试大端小端格式
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

//操作符优先级测试
void OperationTest()
{
	int x0 = 8>6;
	int x1 = 5+6>1 && 7 <8;
	int a,b;
	int x2 = a>=b || b<a;
	int x3 ='Y'>'S'?10:5;
	int x4 = a>b?b<a:a>b;
	int x5 = (a=1)?2:3;
	int x6 = !!0x12345678;
	int x7 = 0x12345678 && ~0x1000;
	

	int (*p)[2],*pp;
	int aa[2][2]={10,11,12};
	p=aa;  //数组地址
	pp=aa[0]; //数组地址
	int x8 = **(p+1);
	int x9 = *(pp+2);

}
 
//位域测试
//输出还有可能是4
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

#pragma (2)




//	Why?我们在 15 行对 instant2 的修改改变了 instant1 中成员的值！ 
//	原因在于 13 行的 instant2 = instant1 赋值语句采用的是变量逐个拷贝，这使得 instant1 和
//	instant2 中的 cMember 指向了同一片内存，因而对 instant2 的修改也是对 instant1 的修改。 
//	在 C 语言中，当结构体中存在指针型成员时，一定要注意在采用赋值语句时是否将 2 个实例中的
//	指针型成员指向了同一片内存。 
struct structA 
{ 
	int iMember;	
	char *cMember; 
}; 

int structMisstakeNote()
{ 
	structA instant1,instant2; 
	char c = 'a'; 
	instant1.iMember = 1; 
	instant1.cMember = &c;  
	instant2 = instant1;					//!!!instant2 = instant1 赋值语句采用的是变量逐个拷贝，
	cout << *(instant1.cMember) << endl;	//14 行的输出结果是：a 
	*(instant2.cMember) = 'b'; 
	cout << *(instant1.cMember) << endl;	//16 行的输出结果是：b 
	return 0; 
} 





#define BIT3 (0x1 << 3) 
/*void set_bit3(unsigned int &dat) 
{ 
	dat |= BIT3; 
}*/ 
//void set_bit3(unsigned int *dat) 
//{ 
//	*dat |= BIT3; 
//}
unsigned int set_bit3(unsigned int dat) 
{ 
	dat |= BIT3;
	return dat;
} 
void clear_bit3(unsigned int &dat) 
{ 
	dat &= ~BIT3; 
}



//本例中：在调用Exchg1(a,b)时最开始做的两个隐含动作是：int x=a;int y=b;.及x=a;y=b;
//原来函数在调用时是隐含地把参数a,b的值分别赋值给了x,y。之后在函数体内一直是对形参x,y进行操作。并没有对a,b进行任何操作。
//函数只是把a,b的值通过赋值传递将值传递给了x,y。函数里操作的只是x,y的值，并不是a,b的值。这就是所谓的值传递
void Exchg1(int ax, int by)
{
	int tmp;
	tmp = ax;
	ax = by;
	by = tmp;
	printf("ax = %d, by = %d\n", ax, by);
}

//本例中：在调用Exchg2(&a,&b)时最开始做的两个隐含动作是：int *px=&a;int *py=&b;.及 px=&a;py=&b;.
//原来函数在调用时是隐含地把参数a,b的地址分别传递给了指针px,py。
//之后在函数体内一直是对指针px,py进行操作。也就是对a,b的地址进行的操作。
void Exchg2(int *pax, int *pby)
{
	int tmp = *pax;
	*pax = *pby;
	*pby = tmp;
	printf("*pax = %d, *pby = %d.\n",*pax, *pby);
}


//本例中：与值传递相比，代码上只有只有一处不同，即函数定义处：void Exchg3(int &x, int &y)
//Exchg3函数的定义处Exchg3(int&x, int &y)。调用时我们可以像值传递（如： Exchg1(a, b); ）一样调用函数（如： Exchg3(a,b);）。
//但是x、y前都有一个取地址符号“&”。有了这个，调用Exchg3时函数会将a、b 分别代替了x、y了，我们称：x、y分别引用了a、b变量。
//这样函数里操作的其实就是实参a、b本身了，因此函数的值可在函数里被修改
void Exchg3(int &ax, int &by)
{
	int tmp = ax;
	ax = by;
	by = tmp;
	printf("ax= %d,by = %d\n", ax, by);
}

//值传递 地址传递 应用传递
void TestValueTransport()
{
	int a = 4,b =6;
	Exchg1(a, b);//不能交换 值传递
	Exchg2(&a, &b); //可以交换 地址传递
	Exchg3(a, b);//可以交换 应用传递
	printf("a= %d, b = %d\n", a, b);


	char *str = NULL;
	getmemory1(str); //get buffer faile
	printf("%s/n",str);
	str  = getmemory10(0);

	getmemory2(&str,100); //地址传递
	strcpy(str,"hello");
	free(str);
	printf("\n str is %s",str);

}

//编写一个函数，作用是把一个 char 组成的字符串循环右移 n 个。比如原来是“abcdefghi”
//如果 n=2，移位后应该是“hiabcdefgh” 
//函数头是这样的： 
//pStr 是指向以'\0'结尾的字符串的指针 
//steps 是要求移动的 n 
#define  MAX_LEN	256

//解答： 
//正确解答 1： 
void LoopMove ( char *pStr, int steps,long x ) 
{ 
	int n = strlen( pStr ) - steps; 
	char tmp[MAX_LEN];  
	strcpy ( tmp, pStr + n );  
	strcpy ( tmp + steps, pStr);  
	*( tmp + strlen ( pStr ) ) = '\0'; 
	strcpy( pStr, tmp ); 
} 
//正确解答 2： 
void LoopMove ( char *pStr, int steps ) 
{ 
	int n = strlen( pStr ) - steps; 
	char tmp[MAX_LEN];  
	memcpy( tmp, pStr + n, steps );  
	memcpy(pStr + steps, pStr, n );  
	memcpy(pStr, tmp, steps );  
} 

/*请写一个 C 函数，若处理器是 Big_endian 的，则返回 0；若是 Little_endian 的，则返回 1 
解答：*/ 
int checkCPU() 
{ 
	{ 
		union w 
		{ 
			int a; 
			char b; 
		} c; 
		c.a = 1; 
		return (c.b ==1); 
	} 
} 
//对于一个字节（8bit）的数据，求其中“1”的个数，要求算法的执行效率尽可能地高。
#define BYTE unsigned char
void FindTheOne()
{

	 int i, num = 0; 
	 BYTE a; 
	 /* 接收用户输入*/ 
	 printf("\nPlease Input a BYTE(0~255):"); 
	 scanf("%d", &a); 
	 /* 计算1的个数*/ 
	 for (i = 0; i < 8; i++) 
	 { 
		num += (a >> i) &0x01; 
	 } 
	 /*或者这样计算1的个数：*/ 
	 /* for(i=0;i<8;i++) 
	 { 
	 if((a>>i)&0x01) 
	 num++; 
	 } 
	76 
	 */ 
	 printf("\nthe num of 1 in the BYTE is %d", num); 

}




int _tmain(int argc, _TCHAR* argv[])
{
	
	int *pInt = new int[10];
	if (NULL == pInt)
	{
		printf("new buf failed\r\n");
	}
	char *pMalloc = (char *) malloc(200);
	if (NULL == *pMalloc)
	{
		printf("malloc buf failed \r\n");
	}
	
	int aaa=3,baa=4,caa=0;
	caa = aaa+++baa;

	TestValueTransport();
		
	unsigned int dataT=0xc0;
	int x430 = set_bit3(dataT);
	clear_bit3(dataT);

	//&a 这个是int (*)[5]类型 &a + 1 移动 20个字节 点到为止

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
		numlen = sizeof(*px);// 特别注意这个 numlen=1;
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





//=================================冒泡排序==========================================//
	//int nData[10] = {4,10,9,8,7,6,5,4,3,2};    //创建10个数据，测试
	//BubbleSort(nData, 10);        //调用冒泡排序
	//for (int i = 0; i < 10; ++i)        
	//{
	//	printf("%d ", nData[i]);
	//}
	//printf("\n");
	//system("pause");//   应聘：到岗时间：2013年7月
//=================================冒泡排序==========================================//
	isPrime2(11);
	isPrime2(23);



	
	char text[10];
	char name[20];
	char *pname;

	char len = sizeof(stda);
//============================逻辑与 和 按位与 的区别！！！============================
	int yx =8&&5;  //逻辑与！！！！
	int yxz = 7 & 5;  //按位与！！！！
	
	//按位与例子
	int x=9999;
	int countx = 0;
	while(x)
	{
		countx ++;
		x = x&(x-1);
	}
	// countx 的值为1的个数
//============================逻辑与 和 按位与 的区别！！！============================


	//自己编写 strcopy 函数！！！！
	pname = strcpy2(text,"abcdefghk");
	


//	stu.pxd = name;
	strcpy(name,"jamiyad");
	xyz(name);
	stu.num=99;
	



	
	
	
	
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
	//char    *p =  str ;  
	//int      n = 10;  
	//int x1 = sizeof ( str );
	//int x2 = sizeof ( *p )  ;
	//int x3 = sizeof ( n ) ;
	//
	//printf("%d",strlen(str));
	//printf("%d",strlen(p));

	return 0;
}

