#pragma once

#include "resource.h"

void FillArray(int array[], int maxSize);

bool Search(int number, int array[], int* mid, int* left, int* right);

void Delete(int array[], int index, int* size);

void add(int array[], int index, int* size);