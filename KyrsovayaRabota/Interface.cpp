#include "Interface.h"
#include "framework.h"

LPWSTR CharToLPWSTR(LPCSTR char_string)
{
	LPWSTR res;
	DWORD res_len = MultiByteToWideChar(1251, 0, char_string, -1, NULL, 0);
	res = (LPWSTR)GlobalAlloc(GPTR, (res_len + 1) * sizeof(WCHAR));
	MultiByteToWideChar(1251, 0, char_string, -1, res, res_len);
	return res;
}

int TOINT(TCHAR* digit) {

	int num = 0;
	int k = 1;
	int i = 0;

	while (digit[i] >= '0' && digit[i] <= '9') {

		num += ((int)digit[i]) - (int)'0';
		num *= 10;
		i++;
	}

	num /= (10 * k);

	return num;
}

char* TOCHAR(int digit) {
	char num[10];
	int i = 0;

	do {
		num[i] = (digit % 10) | 0x30;
		digit = digit / 10;
		i++;
	} while (digit > 0);
	char* number = new char[i];
	i--;
	int k = 0;
	while (i >= 0) {
		number[k] = num[i];
		i--;
		k++;
	}
	number[k] = '\0';
	return(number);

}
