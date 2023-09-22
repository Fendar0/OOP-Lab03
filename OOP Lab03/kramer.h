#pragma once

class kramer
{
private:
	int rows, columns;// строки и столбцы
	float determinant; //определитель
	float** array;// матрица
	float** intermediateArray;// промежуточная матрица
	float* vector;// вектор значений 	
	float* determinantArray;// определители промежуточных матриц
	float* resultArray;// корни СЛАУ
public:
	float* GetDeterminantArray();// получение массива определителей промежуточных матриц
	float** GetArray();// получение массива главной матрицы
	float* GetVector();// получение вектора значений
	float** GetIntermediateArray();// получение промежуточной матрицы
	float* GetResultArray();// получение массива с корнями СЛАУ
	void FillArray(int rows, int columns);// заполнение главной матрицы значениями и промежуточной
	float DeterminantArray(float** array, int rows, int columns);// нахождение определителя главной матрицы
	void FillVector(int columns);// заполнение вектора значений
	void FillIntermediateArray(float** intermediateArray, int rows, int columns, float* vector);// поиск определителей промежуточных матриц
	void Kramer(float* determinantArray, int rows,int columns, float determinant);// расчет корней СЛАУ
};

