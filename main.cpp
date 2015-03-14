//! \mainpage Программа, реализующая алгоритм быстрой сортировки \file <main.cpp>
#include <iostream>
#include <conio.h>
using namespace std;

/*!
* \param [in] *M - указатель на массив
* \param [in] left - первое значение слева
* \param [in] right - первое значение справа
*/
void quicksort(int *M, int left, int right)//! Функция быстрой сортировки
    {
    int i = left;
    int j = right;
 
    int x = M[(left + right)/2];/*!
    *Нахождение среднего элемента:
	*\code int x = M[(left + right)/2]; \endcode*/
    int temp;
 
    do{ /*! Основная часть функции:
		*\code while(M[i] < x) i++;
       * while(M[j] > x) j--;
 *
        *if(i<=j){
         *   temp = M[i];
          *  M[i] = M[j];
           * M[j] = temp;
            *i++; j--;
        *}
    *}while(i<=j);\endcode */
 
        while(M[i] < x) i++;
        while(M[j] > x) j--;
 
        if(i<=j){
           temp = M[i];
           M[i] = M[j];
           M[j] = temp;
           i++; j--;
        }
    }while(i<=j);
 
    if(j > left) quicksort(M, left, j);/*!Вызов функции рекурсивно: 
	*\code if(j > left) quicksort(M, left, j);
	*if(i < right) quicksort(M, i, right);\endcode */
    if(i < right) quicksort(M, i, right);
}
void main()//! Main: эта функция заполняет массив элементами и вызывает функцию сортировки
{
	int  n, i; 
    cin>>n; 
	int* p = new int[n];
	for (i = 0; i<n; i++)
	   cin>>p[i]; 
	quicksort(p,0,n-1);
	for (i = 0; i<n; i++)
	{
	   cout<<p[i];
	   cout<<" ";
	}
	_getch();
}