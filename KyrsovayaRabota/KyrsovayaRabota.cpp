// KyrsovayaRabota.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "KyrsovayaRabota.h"
#include "Interface.h"
#include "Functions.h"


#define MAX_LOADSTRING 100

int array[100];
int size = 0;
int maxSize = 15;
bool first = true;
int mid = -1;
int left = -1;
int right = -1;
bool isSearched = false;

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Разместите код здесь.

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_KYRSOVAYARABOTA, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KYRSOVAYARABOTA));

	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KYRSOVAYARABOTA));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_KYRSOVAYARABOTA);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
HWND hButtonSearch;
HWND hButtonRandArray;
HWND hButtonDelete;
HWND hButtonNotDelete;
HWND hEditDigit;
HWND hButtonadd;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		hInst = ((LPCREATESTRUCT)lParam)->hInstance; // дескриптор приложения

		hButtonSearch = CreateWindow(L"button", L"Найти число",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 10, 200, 40, hWnd, reinterpret_cast<HMENU>(13), hInst, NULL);
		ShowWindow(hButtonSearch, SW_SHOWNORMAL);
		EnableWindow(hButtonSearch, 0);

		hButtonRandArray = CreateWindow(L"button", L"Заполнить массив",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			220, 10, 200, 40, hWnd, reinterpret_cast<HMENU>(14), hInst, NULL);
		ShowWindow(hButtonRandArray, SW_SHOWNORMAL);

		hButtonDelete = CreateWindow(L"button", L"Удалить число",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			430, 10, 200, 40, hWnd, reinterpret_cast<HMENU>(15), hInst, NULL);
		ShowWindow(hButtonDelete, SW_SHOWNORMAL);
		EnableWindow(hButtonDelete, 0);
		
		hButtonadd = CreateWindow(L"button", L"Добавить число",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			640, 10, 200, 40, hWnd, reinterpret_cast<HMENU>(17), hInst, NULL);
		ShowWindow(hButtonadd, SW_SHOWNORMAL);
		

		hButtonNotDelete = CreateWindow(L"button", L"Не удалять число",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			430, 60, 200, 40, hWnd, reinterpret_cast<HMENU>(16), hInst, NULL);
		ShowWindow(hButtonNotDelete, SW_SHOWNORMAL);
		EnableWindow(hButtonNotDelete, 0);

		hEditDigit = CreateWindow(L"edit", NULL,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 10, 60, 410, 40,
			hWnd, 0, hInst, NULL);
		ShowWindow(hEditDigit, SW_SHOWNORMAL);
		EnableWindow(hEditDigit, 0);

		break;
	}// создание кнопок и полей
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		/*case 13:
		{
			int lastMid = mid;
			TCHAR num[6];
			GetWindowText(hEditDigit, num, 6);
			int searchedDigit = TOINT(num);

			if (first == true) {
				right = size - 1;
				left = 0;
				first = false;
			}
			mid = (left + right) / 2;

			isSearched = Search(searchedDigit, array, &mid, &left, &right);

			if (isSearched == true) {
				EnableWindow(hEditDigit, 0);
				EnableWindow(hButtonSearch, 0);
				EnableWindow(hButtonDelete, 1);
				EnableWindow(hButtonNotDelete, 1);
			}
			if (lastMid == mid) {
				mid = -1;
				left = -1;
				mid = -1;
				first = true;
			}

			InvalidateRect(hWnd, NULL, TRUE);

			break;
		} */ //нужно доработать
		case 14:
		{
			FillArray(array, maxSize);
			size = maxSize;			
			mid = -1;
			left = -1;
			mid = -1;
			first = true;
			InvalidateRect(hWnd, NULL, TRUE);
			EnableWindow(hButtonSearch, 1);
			EnableWindow(hEditDigit, 1); 

			break;
		}//реализация заполнения массива
		case 15:
		{
			Delete(array, mid, &size);
			mid = -1;
			left = -1;
			mid = -1;
			first = true;
			isSearched = false;
			EnableWindow(hButtonSearch, 1);
			EnableWindow(hEditDigit, 1);
			EnableWindow(hButtonDelete, 0);
			EnableWindow(hButtonNotDelete, 0);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}//реализация удаления значения
		case 16:
		{
			mid = -1;
			left = -1;
			mid = -1;
			first = true;
			isSearched = false;
			EnableWindow(hButtonSearch, 1);
			EnableWindow(hEditDigit, 1);
			EnableWindow(hButtonDelete, 0);
			EnableWindow(hButtonNotDelete, 0);
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}//реализация не удаления значения
		case 17:
		{
			
			add(array, mid, &size);
			mid = -1;
			left = -1;
			mid = -1;
			first = true;
			isSearched = false;
			EnableWindow(hButtonSearch, 1);
			EnableWindow(hEditDigit, 1);
			EnableWindow(hButtonDelete, 0);
			EnableWindow(hButtonNotDelete, 0);
			InvalidateRect(hWnd, NULL, TRUE);
			
			
			break;
		}//реализация добавления значения 
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		HPEN hpenPenBlack = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
		HPEN hpenPenGreen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
		HPEN hpenPenRed = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));

		for (int i = 0; i < size; i++) {
			if (isSearched == true && i == mid) {
				SelectObject(hdc, hpenPenGreen);
			}
			else if (isSearched == false && i == mid) {
				SelectObject(hdc, hpenPenRed);
			}
			else {
				SelectObject(hdc, hpenPenBlack);
			}
			Rectangle(hdc, 10 + i * 50, 200, 60 + i * 50, 250);
			TextOut(hdc, 15 + i * 50, 220, CharToLPWSTR(TOCHAR(array[i])), strlen(TOCHAR(array[i])));
		}// отрисовка

		if (isSearched == true) {
			TextOut(hdc, 15, 320, CharToLPWSTR("Искомое число найдено, вы можете его удалить"), strlen("Искомое число найдено, вы можете его удалить"));
		}
		if (isSearched == false && mid != -1) {
			TextOut(hdc, 15, 320, CharToLPWSTR("Искомое число не найдено на данной итерации"), strlen("Искомое число не найдено на данной итерации"));
		}
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
