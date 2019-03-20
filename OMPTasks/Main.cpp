#include<iostream>
#include<omp.h>
#include<stdio.h>
#include <ctime>

using namespace std;

//#region Done
////�������� ��������� ��� ������ ����� �������� ���� �������������,
////���������� ������� ����� � ������� �Hello World�. ��������� ��������� � 8 ��������. 
////������ �� ����� ���������? ������?  (1 ����)
//void task1(int threadNum = -1)
//{
//	if (threadNum > 0)
//		omp_set_num_threads(threadNum);
//#pragma omp parallel
//	{
//		printf("Thread num = %d hello world!, num threads =  %d \n", omp_get_thread_num(), omp_get_num_threads());
//	}
//}
//
////�������� ���������, � ������� ���������� ��� ������������ �������, 
////���������� ������� ������� �� ��������� ��������� #pragma omp parallel if (�), ���� �������� �������� ����� ����� ������ 2, 
////������������ ������� �����������, ����� �� �����������.����� ����� ����� ������ �������� ������ ������ 3, ����� ������ � ������ 1. 
////������ ������������ �������� ���������� ���������� ����� � ����� ������ ����, 
////��������� ������ �� �����.��������� � ������������ ������ ���������. (2 �����)
//void task2(int firstTest = 4, int secondTest = 2)
//{
//	int n = firstTest;
//	omp_set_num_threads(n);
//#pragma omp parallel if(n > 3)
//	{
//		printf("1section Thread num = %d, num threads =  %d \n", omp_get_thread_num(), omp_get_num_threads());
//	}
//	n = secondTest;
//	omp_set_num_threads(n);
//#pragma omp parallel if(n > 3)
//	{
//		printf("2section Thread num = %d, num threads =  %d \n", omp_get_thread_num(), omp_get_num_threads());
//	}
//
//}
//
////�������� ���������, � ������� �������� � ��������� ��������� �������� ������������� ���������� : 
////a � b, ���������� ��� ������������ �������, ������ � � ������ ����� 2, ������ � � ������ ����� 4. 
////��� ������ ������� ���������� a � b �������� �����������, � ������� ������� private � firstprivate ��������������, 
////������ ������� ���������� ����� ���� � ��������� ���������� �������� ���������� �� ��� ��������.
////������ �� ����� �������� ���������� �� ����� � ������������ �������, ������ ������������ ������� � ����� ������ �� ������������ �������.
////��� ������ ������� ���������� a �������� �����, ���������� b �������� ����������, � ������� ������� private,
////���������� ����� ���� � ��������� ���������� �������� ���������� �� ��� ��������.
////������ �� ����� �������� ���������� �� ����� � ������������ �������, ������ ������������ ������� � ����� ������ �� ������������ �������. (2 �����)
//void task3(int a = 0, int b = 0, int n1 = 4, int n2 = 4)
//{
//	a = 0;
//	b = 0;
//	omp_set_num_threads(n1);
//	printf("Begin 1st section \n");
//	printf("a,b = %d %d \n", a, b);
//#pragma omp parallel private(a) firstprivate(b)
//	{
//		a = 0;
//		a += omp_get_thread_num();
//		b += omp_get_thread_num();
//		printf("a,b = %d %d %d \n", a, b, omp_get_thread_num());
//	}
//	printf("a,b = %d %d \n", a, b);
//	omp_set_num_threads(n2);
//	printf("Begin 2nd section \n");
//	printf("a,b = %d %d\n", a, b);
//#pragma omp parallel shared(a) private(b)
//	{
//		b = 0;
//		a -= omp_get_thread_num();
//		b -= omp_get_thread_num();
//		printf("a,b = %d %d %d \n", a, b, omp_get_thread_num());
//	}
//	printf("a,b = %d %d \n", a, b);
//}
//
////�������� ���������, � ������� �������� � ��������� ��������� �������� ������������� �������� a[10] � b[10], 
////���������� ������������ �������, ���������� ����� ������ ������ 2, �������� ��� ��� ��������(����� 0) � ���� � ������� 1. 
////�������� ���� ������ ��������� ����� min �������� ��������� ������� a, ���� � ������� 1 - ����� max �������� ��������� ������� b.
////��������� ������ �� �����. (2 �����)
//void task4()
//{
//	int  min, max;
//	max = INT_MIN;
//	min = INT_MAX;
//	int a[10] = { 4, 3, 2, 1, 4, 5, 3, 5, 9, 1 };
//	int b[10] = { 2, 2, 3, 2, 1, 4, 5, 3, 5, 9 };
//#pragma omp parallel num_threads(2)
//	{
//#pragma omp master
//		for (int i = 0; i < 10; i++)
//		{
//			if (a[i] < min)
//			{
//				min = a[i];
//			}
//			printf("AThread_num = %d, i = %d \n", omp_get_thread_num(), i);
//		}
//#pragma omp single
//		for (int i = 0; i < 10; i++)
//		{
//			if (b[i] > max)
//			{
//				max = b[i];
//			}
//			printf("BThread_num = %d, i = %d \n", omp_get_thread_num(), i);
//		}
//	}
//	printf("maxb = %d, mina = %d", max, min);
//}
//
////�������� ���������, � ������� �������� � ��������� ��������� �������� ��������� ���������� ������� d[6][8],
////��� ������������� �������� ������������ ��������� ��������� �����.��������� ����������� ��������� sections�section
////���������� ��� ������ ��� ���������� ��������� �������� :
////������ ������ ��������� ���������� �������� ��������������� �������� ��������� ���������� �������,
////������ ������ ��������� ���������� ������������ � ������������� �������� ��������� ���������� �������,
////������ ������ ��������� ���������� ���������� ��������� �������, �������� �������� ������� ������ 3.
////� ������ ������ ���������� � ������ �� ����� ����� ����������� ���� � ��������� ���������� ����������. (3 �����)
//void task5()
//{
//	int d[6][8];
//	int sum = 0;
//	int  min, max;
//	max = INT_MIN;
//	min = INT_MAX;
//	int kolvo = 0;
//	for (int i = 0; i < 6; i++)
//		for (int j = 0; j < 8; j++)
//			d[i][j] = rand();
//#pragma omp parallel 
//	{
//#pragma omp sections 
//		{
//#pragma omp section
//			{
//				for (int i = 0; i < 6; i++)
//					for (int j = 0; j < 8; j++)
//					{
//						sum += d[i][j];
//						//printf("1st section Thread_num(%d)%c", omp_get_thread_num(), '\n');
//					}
//				printf("1st section Thread_num = %d, M = %.2f \n", omp_get_thread_num(), sum*1.0 / 48);
//			}
//#pragma omp section
//			{
//				for (int i = 0; i < 6; i++)
//					for (int j = 0; j < 8; j++)
//					{
//						if (d[i][j] > max)
//						{
//							max = d[i][j];
//						}
//						if (d[i][j] < min)
//						{
//							min = d[i][j];
//						}
//						//printf("2nd section Thread_num(%d)%c", omp_get_thread_num(), '\n');
//					}
//				printf("2nd section Thread_num = %d, max = %d, min = %d\n", omp_get_thread_num(), max, min);
//			}
//#pragma omp section
//			{
//				for (int i = 0; i < 6; i++)
//					for (int j = 0; j < 8; j++)
//					{
//						if (d[i][j] % 3 == 0)
//						{
//							kolvo++;
//						}
//						//printf("3rd section Thread_num(%d)%c", omp_get_thread_num(), '\n');
//					}
//				printf("3rd section Thread_num = %d, kolvo = %d\n", omp_get_thread_num(), kolvo);
//			}
//		}
//	}
//}
//
////�������� ���������, � ������� �������� � ��������� ��������� �������� ������������� �������� a[10] � b[10].
////��������� ����������� parallel for � reduction ��������� ������� �������������� �������� ��������� �������� a � b,
////�������� ���������� ��������, ��������� ������ �� �����. (2 �����)
//void task6()
//{
//	int a[10], b[10], Ma, Mb;
//	for (int i = 0; i < 10; i++)
//	{
//		a[i] = rand() % 100;
//		b[i] = rand() % 100;
//	}
//	Ma = 0;
//	Mb = 0;
//#pragma omp parallel for shared(a,b) reduction(+:Ma) reduction(+:Mb)
//	for (int i = 0; i < 10; i++)
//	{
//		Ma += a[i];
//		Mb += b[i];
//		printf("Thread_num = %d, i = %d  \n", omp_get_thread_num(), i);
//	}
//	Ma /= 10;
//	Mb /= 10;
//	if (Ma <= Mb)
//	{
//		if (Ma < Mb)
//			cout << "Ma<Mb " << "Ma = " << Ma << ", Mb = " << Mb << endl;
//		else
//			cout << "Ma = Mb = " << Ma << " = " << Mb << endl;
//	}
//	else
//		cout << "Ma>Mb " << "Ma = " << Ma << ", Mb = " << Mb << endl;
//}
//
////�������� ���������, � ������� ���������� ��� ������������ �������, 
////������ �� ������� �������� ������������ ����������� for ����������� 
////������������� ��������� ���������� �������� ����� ����� a[12], b[12] � c[12].
////����� ����� ����� ������ �������� ������ ������ 3, ����� ������ � ������ 4. 
////������ ������������ ������� ��������� ������������� ��������� �������� a � b � �������������� ������������ ������������� ��������, 
////������ ������ �������� ������� ��������������, ������ ������������ ������� ��������� ������������� ��������� ������� c �� ����������
////������� c[i] = a[i] + b[i], � �������������� ������������� ������������� ��������, ������ ������ �������� ������� ��������������.
////� ������ ������� ���������� � ������ �� ����� ���������� �����, ����� ���� � ��������� ���������� �����.
////��������� � ������������ ������ ���������.  (2 ������)
//void task7()
//{
//	int a[12], b[12], c[12];
//	omp_set_num_threads(3);
//#pragma omp parallel for schedule(static,3)	
//	for (int i = 0; i < 12; i++)
//	{
//		a[i] = rand() % 10;
//		b[i] = rand() % 10;
//		printf("1st ThreadNum (%d) i (%d) a(%d) (%d) b(%d) (%d) and numThreads (%d) \n", omp_get_thread_num(), i, i, i, a[i], b[i], omp_get_num_threads());
//	}
//	omp_set_num_threads(4);
//#pragma omp parallel for schedule(dynamic,3)
//	for (int i = 0; i < 12; i++)
//	{
//		c[i] = a[i] + b[i];
//		printf("2nd ThreadNum (%d) i (%d) c(%d)(%d) and numThreads (%d)  \n", omp_get_thread_num(), i, i, c[i], omp_get_num_threads());
//	}
//}
//
////�������� ���������, � ������� �������� ������ �� 16000 ��������� � ��������������� ���, 
////��� �������� �������� ������� ����� ��� ����������� ������.����� �������� �������������� ������, 
////� �������(�� ����������� ������� ���������) ����� ������� �������� ��������� ������� :
////b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0
////��������� ��������� � 8 - � ���������� ��� ��������� ����� ������������� �����(static, dynamic, guided, auto) � ���������� �����. 
////(4 �����)
//
//void task8()
//{
//	int a[16000];
//	double b[16000];
//	for (int i = 0; i < 16000; i++)
//		a[i] = i;
//	unsigned int start_time_stat = clock();
//#pragma omp parallel for num_threads(8) schedule(static) shared(b)
//	for (int i = 1; i < 15999; i++)
//	{
//		b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3.0;
//		/*printf("static i num_threads and b[i] %d %d %.1f %d %c", i, omp_get_thread_num(), b[i], omp_get_num_threads(), '\n');*/
//	}
//	unsigned int end_time_stat = clock();
//	unsigned int search_time_stat = end_time_stat - start_time_stat;
//
//	unsigned int start_time_dyn = clock();
//#pragma omp parallel for num_threads(8) schedule(dynamic) shared(b)
//	for (int i = 1; i < 15999; i++)
//	{
//		b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3.0;
//		/*printf("static i num_threads and b[i] %d %d %.1f %d %c", i, omp_get_thread_num(), b[i], omp_get_num_threads(), '\n');*/
//	}
//	unsigned int end_time_dyn = clock();
//	unsigned int search_time_dyn = end_time_dyn - start_time_dyn;
//
//	unsigned int start_time_guid = clock();
//#pragma omp parallel for num_threads(8) schedule(guided) shared(b)
//	for (int i = 1; i < 15999; i++)
//	{
//		b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3.0;
//		/*printf("static i num_threads and b[i] %d %d %.1f %d %c", i, omp_get_thread_num(), b[i], omp_get_num_threads(), '\n');*/
//	}
//	unsigned int end_time_guid = clock();
//	unsigned int search_time_guid = end_time_guid - start_time_guid;
//
//	unsigned int start_time_auto = clock();
//#pragma omp parallel for num_threads(8) schedule(dynamic, 3) shared(b)
//	for (int i = 1; i < 15999; i++)
//	{
//		b[i] = (a[i - 1] + a[i] + a[i + 1]) * 1.0 / 3.0;
//		/*printf("static i num_threads and b[i] %d %d %.1f %d %c", i, omp_get_thread_num(), b[i], omp_get_num_threads(), '\n');*/
//	}
//	unsigned int end_time_auto = clock();
//	unsigned int search_time_auto = end_time_auto - start_time_auto;
//
//	printf("static dynamic guided auto \n");
//	printf("%d     %d      %d     %d \n", search_time_stat, search_time_dyn, search_time_guid, search_time_auto);
//}
//
////��������� ����������� OpenMP �������� ��������� ��������� ������� �� ������.
////�������� ����� ���������� ���������������� � ������������ ��������.
////���������� ������� ������� ��� ������� ������������ ��������� �������� �������� ������� ����������������(3 �����)
//void task9(int n = 10000)
//{
//	int **a = new int*[n];
//	int *b = new int[n];
//	int *c1 = new int[n];
//	int *c2 = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		b[i] = rand() % 100;
//		a[i] = new int[n];
//		for (int j = 0; j < n; j++)
//		{
//			a[i][j] = rand() % 100;
//		}
//	}
//
//	unsigned int start_time_posl = clock();
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			c1[i] += a[i][j] * b[j];
//		}
//	}
//	unsigned int end_time_posl = clock();
//	unsigned int search_time_posl = end_time_posl - start_time_posl;
//
//	unsigned int start_time_paral = clock();
//#pragma omp parallel for schedule(guided)
//	for (int i = 0; i < n; i++)
//	{
//#pragma omp parallel for schedule(guided)
//		for (int j = 0; j < n; j++)
//		{
//			c2[i] += a[i][j] * b[j];
//		}
//	}
//	unsigned int end_time_paral = clock();
//	unsigned int search_time_paral = end_time_paral - start_time_paral;
//
//	cout << "paralllel_time = " << search_time_paral << " posl time = " << search_time_posl;
//	delete[] b, c1, c2;
//	for (int i = 0; i < n; i++)
//		delete[] a[i];
//}
//
//�������� ���������, � ������� �������� � ��������� ��������� �������� ������� ����� ����� a[30], 
//��� ������������� �������� ������������ ��������� ��������� �����.��������� ����������� omp parallel for � omp atomic 
//��������� ���������� ��������� �������, �������� �������� ������� ������ 9. ���������� ����� ������ ��������������.
//��������� ������ �� �����. (2 �����)
//void task11()
//{
//	int a[30];
//	int  tempCount = 0;
//	int  count = 0;
//	for (int i = 0; i < 30; i++)
//	{
//		a[i] = rand();
//		if (a[i] % 9 == 0)
//		{
//			tempCount++;
//		}
//	}
//#pragma omp parallel for
//	for (int i = 0; i < 30; i++)
//	{
//		if (a[i] % 9 == 0)
//		{
//#pragma omp atomic
//			count++;
//		}
//
//	}
//
//	cout << "counter = " << count << " without par = " << tempCount << endl;
//}

//�������� ���������, � ������� �������� � ��������� ��������� �������� ��������� ���������� ������� d[6][8],
//��� ������������� �������� ������������ ��������� ��������� �����.
//��������� ����������� ��������� omp parallel for � omp critical ���������� 
//����������� � ������������ �������� ��������� ���������� �������.
//����������� ������ reduction ��� max � min.���������� ����� ������ ��������������.��������� ������ �� �����. (2 �����)
void task10()
{
	int d[6][8];
	int  min, max;
	max = INT_MIN;
	min = INT_MAX;
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 8; j++)
			d[i][j] = rand();

#pragma omp parallel num_threads(8)
#pragma omp for 
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (min > d[i][j])
			{
#pragma omp critical
				if (min > d[i][j])  //����� ������� ��������!!!
					min = d[i][j];
			}

			if (max < d[i][j])
			{
#pragma omp critical 
				if (max < d[i][j])
					max = d[i][j];

			}
		}
	}

	cout << "min = " << min << " max = " << max << endl;
}


//�������� ���������, � �������, �������� � ��������� ���������� ���������� ������ ����� �����.
//��������� ����������� OpenMP ����� ������������ �������� �������� ��������� �������, ������� 7. 
//����� ������� � ���������� ������� ���������� ��������������.
//��������� ������ �� �����.��� ������������� �������� �������� ��������� ������������ �������� ����������� ������. (2 �����)
void task12()
{
	int max = INT_MIN;
	int tempMax = INT_MIN;
	int a[100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = rand();
		if (a[i] % 7 == 0 && a[i] > tempMax)
		{
			tempMax = a[i];
		}
	}
#pragma omp parallel for
	for (int i = 0; i < 100; i++)
	{
		if (a[i] % 7 == 0 && a[i] > max)
		{
#pragma omp critical
			if (a[i] % 7 == 0 && a[i] > max) //����� ������� ��������!!!
				max = a[i];
		}
	}
	cout << "max = " << max << "testMax = " << tempMax << endl;

}

//������������� ������ 1 ���, ����� ������ ������������� ���� �������������� � �������� �������.
//���������� ��� ������� 5 �������� �������.������������ ����� ��� ����� ������. (������ ������� 1 ���� � max 5 ������)
void task13_1(int threadNum = -1)
{
	if (threadNum > 0)
		omp_set_num_threads(threadNum);
	int i = threadNum - 1;
	int temp;
#pragma omp parallel
	{
		while (i >= 0)
		{
			if (omp_get_thread_num() == i)
			{
				printf("Thread num = %d hello world!, num threads =  %d \n", omp_get_thread_num(), omp_get_num_threads());
				i--;
			}
		}
	}
}

void task13_2(int threadNum = -1)
{
	if (threadNum > 0)
		omp_set_num_threads(threadNum);
	int i;
#pragma omp parallel 
	{
#pragma omp for private(i) ordered
			for (i = 0; i < omp_get_num_threads(); i++)
#pragma omp ordered 
				printf("Thread num = %d hello world!, num threads =  %d \n", omp_get_thread_num(), omp_get_num_threads());
	}

}

int main()
{
	////1
	///*task1();
	//task1(8);*/
	////task2();
	////task3();
	////task4();
	////task5();
	////task6();
	////task7();
	////task8();
	///*task9(500);
	//task9(550);*/
	////task9(10000);
	////task11();

	task10();
	task12();
	task13_1(4);
	//task13_2(4);
	/*task13_3(4);
	task13_4(4);
	task13_5(4);*/

	system("pause");
	return 0;
}