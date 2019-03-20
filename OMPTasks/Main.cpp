#include<iostream>
#include<omp.h>
#include<stdio.h>
#include <ctime>

using namespace std;

//#region Done
////Написать программу где каждый поток печатает свой идентификатор,
////количество потоков всего и строчку «Hello World». Запустить программу с 8 потоками. 
////Всегда ли вывод идентичен? Почему?  (1 балл)
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
////Написать программу, в которой определить две параллельные области, 
////выполнение которых зависит от условного оператора #pragma omp parallel if (…), если заданное значение числа нитей больше 2, 
////параллельная область выполняется, иначе не выполняется.Число нитей перед первой областью задать равным 3, перед второй – равным 1. 
////Внутри параллельных областей определить количество нитей и номер каждой нити, 
////результат выдать на экран.Убедиться в правильности работы программы. (2 балла)
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
////Написать программу, в которой объявить и присвоить начальные значения целочисленным переменным : 
////a и b, определить две параллельные области, первая – с числом нитей 2, вторая – с числом нитей 4. 
////Для первой области переменные a и b объявить защищенными, с режимом доступа private и firstprivate соответственно, 
////внутри области определить номер нити и выполнить увеличение значения переменных на эту величину.
////Выдать на экран значения переменных до входа в параллельную область, внутри параллельной области и после выхода из параллельной области.
////Для второй области переменную a объявить общей, переменную b объявить защищенной, с режимом доступа private,
////определить номер нити и выполнить уменьшение значения переменных на эту величину.
////Выдать на экран значения переменных до входа в параллельную область, внутри параллельной области и после выхода из параллельной области. (2 балла)
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
////Написать программу, в которой объявить и присвоить начальные значения целочисленным массивам a[10] и b[10], 
////определить параллельную область, количество нитей задать равным 2, выделить код для основной(номер 0) и нити с номером 1. 
////Основная нить должна выполнять поиск min значения элементов массива a, нить с номером 1 - поиск max значения элементов массива b.
////Результат выдать на экран. (2 балла)
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
////Написать программу, в которой объявить и присвоить начальные значения элементам двумерного массива d[6][8],
////для инициализации значений использовать генератор случайных чисел.Используя конструкцию директивы sections…section
////определить три секции для выполнения следующих операций :
////первая секция выполняет вычисление среднего арифметического значения элементов двумерного массива,
////вторая секция выполняет вычисление минимального и максимального значений элементов двумерного массива,
////третья секция выполняет вычисление количества элементов массива, числовые значения которых кратны 3.
////В каждой секции определить и выдать на экран номер исполняющей нити и результат выполнения вычислений. (3 балла)
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
////Написать программу, в которой объявить и присвоить начальные значения целочисленным массивам a[10] и b[10].
////Используя конструкцию parallel for и reduction вычислить средние арифметические значения элементов массивов a и b,
////сравнить полученные значения, результат выдать на экран. (2 балла)
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
////Написать программу, в которой определить две параллельные области, 
////каждая из которых содержит итерационную конструкцию for выполняющую 
////инициализацию элементов одномерных массивов целых чисел a[12], b[12] и c[12].
////Число нитей перед первой областью задать равным 3, перед второй – равным 4. 
////Первая параллельная область выполняет инициализацию элементов массивов a и b с использованием статического распределения итераций, 
////размер порции итераций выбрать самостоятельно, вторая параллельная область выполняет инициализацию элементов массива c по следующему
////правилу c[i] = a[i] + b[i], с использованием динамического распределения итераций, размер порции итераций выбрать самостоятельно.
////В каждой области определить и выдать на экран количество нитей, номер нити и результат выполнения цикла.
////Убедиться в правильности работы программы.  (2 баллов)
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
////Написать программу, в которой объявлен массив из 16000 элементов и инициализирован так, 
////что значение элемента массива равно его порядковому номеру.Затем создайте результирующий массив, 
////в котором(за исключением крайних элементов) будут средние значения исходного массива :
////b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0
////Запустите программу с 8 - ю процессами при различных типах распределения работ(static, dynamic, guided, auto) и посмотреть время. 
////(4 балла)
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
////Используя возможности OpenMP написать программу умножения матрицы на вектор.
////Сравнить время выполнения последовательной и параллельных программ.
////Определить размеры матрицы при которых параллельная программа начинает работать быстрей последовательной(3 балла)
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
//Написать программу, в которой объявить и присвоить начальные значения массиву целых чисел a[30], 
//для инициализации значений использовать генератор случайных чисел.Используя конструкцию omp parallel for и omp atomic 
//вычислить количество элементов массива, числовые значения которых кратны 9. Количество нитей задать самостоятельно.
//Результат выдать на экран. (2 балла)
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

//Написать программу, в которой объявить и присвоить начальные значения элементам двумерного массива d[6][8],
//для инициализации значений использовать генератор случайных чисел.
//Используя конструкцию директивы omp parallel for и omp critical определить 
//минимальное и максимальное значения элементов двумерного массива.
//Реализовать аналог reduction для max и min.Количество нитей задать самостоятельно.Результат выдать на экран. (2 балла)
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
				if (min > d[i][j])  //метод двойной проверки!!!
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


//Написать программу, в которой, объявить и заполнить случайными значениями массив целых чисел.
//Используя возможности OpenMP найти максимальное числовое значение элементов массива, кратное 7. 
//Длину массива и количество потоков определить самостоятельно.
//Результат выдать на экран.Для синхронизации числовых значений максимума используется механизм критических секций. (2 балла)
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
			if (a[i] % 7 == 0 && a[i] > max) //метод двойной проверки!!!
				max = a[i];
		}
	}
	cout << "max = " << max << "testMax = " << tempMax << endl;

}

//Модифицируйте задачу 1 так, чтобы потоки распечатывали свои идентификаторы в обратном порядке.
//Существует как минимум 5 способов решения.Постарайтесь найти как можно больше. (каждый вариант 1 балл – max 5 баллов)
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