#include<windows.h>
#include<d3dx9.h>
#include<mmsystem.h>


//the WindowProc function prototype
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);     

HWND createWindow(

	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow);

//the entry point any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow) 
{

	HWND hWnd = createWindow(

		hInstance,
		hPrevInstance,
		lpCmdLine,
		//Store the value of Window Handle // Create at least one Window // The OS side manages the Window by the handle
		nCmdShow);

	//Stores messages received from OS
	MSG msg;

	void message();

	//   Get system time
	DWORD SyncPrev = timeGetTime();
	DWORD SyncCurr;

	ZeroMemory(
		&msg,

		//Initialize msg structure.
		sizeof(msg));

	timeBeginPeriod(1);

	//Loop if the message of msg structure is not WM_QUIT.
	while (msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage
	(&msg,NULL,0U,0U,PM_REMOVE))
			//Check message from OS
			//Check if there is a message in the message queue, Store a message similar to the argument structure.
		{//If there is
		//Pass to WindowProc functionÅEtransfer
			TranslateMessage(&msg);//translation

			DispatchMessage(&msg);//send

		}
		else
		{
			//If not, generally write the app processing
			
		}

	
	}
	timeEndPeriod(1); //Timer end
	return (INT)msg.wParam;//Exit the app
}

    //this is the main message handler for the program
	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
	{

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN://When the key is depressed
		switch ((CHAR)wParam)
		{
		case VK_ESCAPE://When u press ESC key
			
		PostQuitMessage(0);//App's end
			break;
		}
		break;
	}
	// Let the system handle what the app does not handle.
	// Leave all messages unnecessary for the app on the system.
	
	return DefWindowProc(hWnd,iMsg,wParam,lParam);
}

HWND createWindow(HINSTANCE hInst,HINSTANCE hPrevInstance,PSTR lpCmdLine,int nCmdShow)

{
	HWND hWnd = NULL;//store the value of WHÅECreate ast least one Window,THe OS side manages the Window.

	//store messages from OS
	MSG msg;
	//Window initiazation
	static char szAppName[] = "ProgrramIntroduction_Task1 ";
	WNDCLASSEX wc;

	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH); // Change th Background color
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register the window class
	RegisterClassEx(&wc);

	hWnd = CreateWindow(
		szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,//window style
		0,     //x-position of the window
		0,     //y-position of the window
		640,  //width of the window
		480,  //height of the window
		NULL, //we have no parent window,NULL
		NULL,  //we aren't using menus,NULL
		hInst, //application handle
		NULL); //used with multipe windows,NULL
	ShowWindow(
		hWnd,
		SW_SHOW);
	UpdateWindow(hWnd);
	return hWnd;
}