#include "Functions.h"
#include "framework.h"

void FillArray(int array[], int maxSize) {
	for (int i = 0; i < maxSize; i++) {
		array[i] = rand() % 100;
	}
}// ����������������� ������ 
	

//bool Search(int number, int array[], int* mid, int* left, int* right) {
//
//	if (array[*mid] == number) {
//		return true;
//	}
//	if (array[*mid] < number) {
//		*left = *mid - 1;
//	}
//	if (array[*mid] > number) {
//		*right = *mid + 1;
//	}
//	return false;
//}���������� ������� ������ ��������, ����� ���������� 

void Delete(int array[], int index, int* size) {
	for (int i = index; i < *size - 1; i++) {
		array[i] = array[i + 1];
	}
	(*size)--;
}// ���������� ������� �������� ��������




//void add(int array[], int index, int* size) {
//	
//	for (int i = index; i < *size - 1; i++) {
//		array[i] = array[i];
//	}
//	(*size)++;
//} ���������� ������� ����������. �������� �� ������ ��������� 


