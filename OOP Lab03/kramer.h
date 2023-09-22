#pragma once

class kramer
{
private:
	int rows, columns;// ������ � �������
	float determinant; //������������
	float** array;// �������
	float** intermediateArray;// ������������� �������
	float* vector;// ������ �������� 	
	float* determinantArray;// ������������ ������������� ������
	float* resultArray;// ����� ����
public:
	float* GetDeterminantArray();// ��������� ������� ������������� ������������� ������
	float** GetArray();// ��������� ������� ������� �������
	float* GetVector();// ��������� ������� ��������
	float** GetIntermediateArray();// ��������� ������������� �������
	float* GetResultArray();// ��������� ������� � ������� ����
	void FillArray(int rows, int columns);// ���������� ������� ������� ���������� � �������������
	float DeterminantArray(float** array, int rows, int columns);// ���������� ������������ ������� �������
	void FillVector(int columns);// ���������� ������� ��������
	void FillIntermediateArray(float** intermediateArray, int rows, int columns, float* vector);// ����� ������������� ������������� ������
	void Kramer(float* determinantArray, int rows,int columns, float determinant);// ������ ������ ����
};

