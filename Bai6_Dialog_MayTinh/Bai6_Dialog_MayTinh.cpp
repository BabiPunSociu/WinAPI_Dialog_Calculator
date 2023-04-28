
#include "framework.h"
#include "Bai6_Dialog_MayTinh.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    MayTinh(HWND, UINT, WPARAM, LPARAM);	// Khai báo nguyên mẫu hàm

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_BAI6DIALOGMAYTINH, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BAI6DIALOGMAYTINH));

	MSG msg;

	// Main message loop:
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

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BAI6DIALOGMAYTINH));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_MENU1);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_MayTinh:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, MayTinh);
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
		// TODO: Add any drawing code that uses hdc here...
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

// Dialog IDD_DIALOG1
INT_PTR CALLBACK MayTinh(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int a, b, pheptinh, ketqua;
	static TCHAR str[20], tam[1];
	switch (message)
	{
	case WM_INITDIALOG:
		break;
	case WM_CLOSE:
		SendMessage(GetDlgItem(hDlg, IDC_btnThoat), BM_CLICK, 1, 0);
	case WM_COMMAND:
		int id = LOWORD(wParam);
		switch (id)
		{
		case IDC_btn0:
			wsprintf(tam, L"0");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn1:
			wsprintf(tam, L"1");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn2:
			wsprintf(tam, L"2");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn3:
			wsprintf(tam, L"3");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn4:
			wsprintf(tam, L"4");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn5:
			wsprintf(tam, L"5");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn6:
			wsprintf(tam, L"6");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn7:
			wsprintf(tam, L"7");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn8:
			wsprintf(tam, L"8");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btn9:
			wsprintf(tam, L"9");
			GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20);   // Get text cũ
			wsprintf(str, L"%s%s", str, tam);                       // Nối thêm chữ số vào 
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);       // Set text mới đã nối
			break;
		case IDC_btnCong:
		case IDC_btnTru:
		case IDC_btnNhan:
		case IDC_btnChia:
			// Lấy text trong IDC_STATIC
			if (GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20) == 0)
			{
				MessageBox(hDlg, L"Bạn chưa nhập giá trị nào", L"", MB_OK);
				break;
			}
			// Chuyển TCHAR -> int và lưu vào a
			a = _tstoi(str);

			// Lấy dấu
			pheptinh = id;

			// Làm trống text trong IDC_STATIC
			SendMessage(GetDlgItem(hDlg, IDC_btnXoa), BM_CLICK, 1, 0);  // Click giả vào nút xóa
			break;
		case IDC_btnBang:
			// Lấy text trong IDC_STATIC
			if (GetWindowText(GetDlgItem(hDlg, IDC_STATIC), str, 20) == 0)
			{
				MessageBox(hDlg, L"Bạn chưa nhập giá trị nào", L"", MB_OK);
				break;
			}
			// Chuyển TCHAR -> int và lưu vào b
			b = _tstoi(str);

			// Tính kết quả
			if (pheptinh == IDC_btnCong)
				ketqua = a + b;
			if (pheptinh == IDC_btnTru)
				ketqua = a - b;
			if (pheptinh == IDC_btnNhan)
				ketqua = a * b;
			if (pheptinh == IDC_btnChia)
			{
				if (b == 0) {
					MessageBox(hDlg, L"Không được chia cho 0", L"Saiiiii", MB_OK);
					// Reset tất cả
					a = NULL;
					b = NULL;
					wsprintf(str, L"");
					SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);
					break;
				}
				ketqua = a / b;
			}

			// Hiện kết quả lên IDC_STATIC
			wsprintf(str, L"%d", ketqua);
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);
			// Reset các giá trị
			a = NULL;
			b = NULL;
			break;
		case IDC_btnXoa:
			wsprintf(str, L"");
			SetWindowText(GetDlgItem(hDlg, IDC_STATIC), str);
			break;
		case IDC_btnThoat:
			if (MessageBox(hDlg, L"Bạn có muốn thoát không?", L"Cảnh báo", MB_YESNO) == IDYES)
				EndDialog(hDlg, TRUE);
		default:
			break;
		}
		break;
	}
	return FALSE;
}

