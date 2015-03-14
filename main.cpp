//! \mainpage ���������, ����������� �������� ������� ���������� \file <main.cpp>
#include <iostream>
#include <conio.h>
using namespace std;

/*!
* \param [in] *M - ��������� �� ������
* \param [in] left - ������ �������� �����
* \param [in] right - ������ �������� ������
*/
void quicksort(int *M, int left, int right)//! ������� ������� ����������
    {
    int i = left;
    int j = right;
 
    int x = M[(left + right)/2];/*!
    *���������� �������� ��������:
	*\code int x = M[(left + right)/2]; \endcode*/
    int temp;
 
    do{ /*! �������� ����� �������:
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
 
    if(j > left) quicksort(M, left, j);/*!����� ������� ����������: 
	*\code if(j > left) quicksort(M, left, j);
	*if(i < right) quicksort(M, i, right);\endcode */
    if(i < right) quicksort(M, i, right);
}
void main()//! Main: ��� ������� ��������� ������ ���������� � �������� ������� ����������
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