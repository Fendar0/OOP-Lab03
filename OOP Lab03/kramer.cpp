#include "kramer.h"
#include <iostream>

// ��������� ������� ������������� ������������� ������
float* kramer::GetDeterminantArray()
{
	return determinantArray;
}

// ���������� ������� ������� ���������� � �������������
void kramer::FillArray(int rows, int columns)
{
	array = new float* [rows];	
	intermediateArray = new float* [rows];
	for (int i = 0; i < rows; i++) 
	{
		array[i] = new float[columns];
		intermediateArray[i] = new float[columns];
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = rand() % 10;
			intermediateArray[i][j] = array[i][j];
		}
	}		
}

// ��������� ������� ������� �������
float** kramer::GetArray()
{
	return array;
}

// ��������� ������� ��������
float* kramer::GetVector()
{
	return vector;
}

// ��������� ������������� �������
float** kramer::GetIntermediateArray()
{
	return intermediateArray;
}

// ��������� ������� � ������� ����
float* kramer::GetResultArray()
{
	return resultArray;
}

// ���������� ������������ ������� �������
float kramer::DeterminantArray(float** array, int rows, int columns)
{	
	if (rows == 1)
		return **array;
	else if (rows == 2)
	{
		 return array[0][0] * array[1][1] - array[0][1] * array[1][0];
	}
	else {
		float d = 0;
		for (int k = 0; k < rows; k++) {
			float** m = new float* [rows - 1];
			for (int i = 0; i < rows - 1; i++) {
				m[i] = new float[rows - 1];
			}
			for (int i = 1; i < rows; i++) {
				int t = 0;
				for (int j = 0; j < rows; j++) {
					if (j == k)
						continue;
					m[i - 1][t] = array[i][j];
					t++;
				}
			}
			d += pow(-1, k + 2) * array[0][k] * DeterminantArray(m, rows - 1, columns - 1);
		}
		return d;		
	}
}

// ���������� ������� ��������
void kramer::FillVector(int rows)
{
	vector = new float[rows];
	for (int i = 0; i < rows; i++)
		vector[i] = rand() % 10;
}

// ����� ������������� ������������� ������
void kramer::FillIntermediateArray(float** intermediateArray, int rows, int columns, float* vector)
{		
	determinantArray = new float[columns];
	for (int c = 0; c < columns; c++)
	{		
		for (int i = 0; i < rows; i++)
		{			
			for (int j = 0; j < columns; j++)							
				intermediateArray[i][j] = array[i][j];			
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = c; j < columns; j++)
			{
				intermediateArray[i][j] = vector[i];
				break;
			}
		}
		determinantArray[c] = DeterminantArray(intermediateArray, rows, columns);
	}	
}

// ������ ������ ����
void kramer::Kramer(float* determinantArray, int rows, int columns, float determinant)
{
	resultArray = new float[columns];
	for (int i = 0; i < columns; i++)
		resultArray[i] = round(determinantArray[i] / determinant * 10000) / 10000;
}


