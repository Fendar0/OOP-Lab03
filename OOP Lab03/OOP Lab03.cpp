#include <iostream>
#include "kramer.h"

int main()
{
	setlocale(LC_ALL, "");	

	int rows = 3; //кол-во строк
	int columns = 3; //кол-во столбцов
	float determinant; //определитель матрицы

	float** arrayMain = new float* [rows];// матрица
	float* vectorMain = new float[rows];// вектор значений 
	float** intermediateArrayMain = new float* [rows];// промежуточная матрица
	float* determinantArrayMain = new float[columns]; 
	float* resultArrayMain = new float[columns];// массив корней СЛАУ

	kramer kr;
	kr.FillArray(rows, columns); // заполняем массивы 
	arrayMain = kr.GetArray(); 
	intermediateArrayMain = kr.GetIntermediateArray();
	 
	kr.FillVector(rows); // заполняем вектор значений СЛАУ
	vectorMain = kr.GetVector(); 
		
	std::cout << "СЛАУ: " << std::endl; // выводим полностью СЛАУ на экран
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << arrayMain[i][j] << "  ";
		std::cout << "| " << vectorMain[i];
		std::cout << std::endl; 
	}
	std::cout << std::endl;
		
	determinant = kr.DeterminantArray(arrayMain, rows, columns); // вычисляем определитель главной матрицы
	std::cout << "Главный определитель: " << determinant << std::endl;

	kr.FillIntermediateArray(intermediateArrayMain, rows, columns, vectorMain); // вычисляем определители второстепенных матриц с поставлением вектора значений
	
	std::cout << std::endl;
		
	determinantArrayMain = kr.GetDeterminantArray(); //выводим определители промежуточных матриц на экран
	std::cout << "Определители: ";
	for (int i = 0; i < columns; i++)
	{
		std::cout << "x" << i + 1 << " = ";
		std::cout << determinantArrayMain[i] << "  ";
	}

	kr.Kramer(determinantArrayMain, rows, columns, determinant);// подсчитываем корни СЛАУ

	std::cout << std::endl;
	std::cout << std::endl;

	resultArrayMain = kr.GetResultArray(); // выводим корни на экран
	std::cout << "Ответ: ";
	for (int i = 0; i < columns; i++)
	{
		std::cout << "x" << i + 1 << " = ";
		std::cout << resultArrayMain[i] << "  ";
	}		
}
