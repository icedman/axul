
#pragma once

#include "common.h"

namespace Ash
{

	static LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#define BEGIN_MSG_HANDLER \
	LRESULT CALLBACK WindowsProc(UINT uMsg, WPARAM wParam, LPARAM lParam) { \
	LRESULT result; \
	BOOL bHandled=TRUE;

#define HANDLE_MSG(msg,func) \
	if (uMsg==msg)  { \
	result=func(uMsg,wParam,lParam,bHandled); \
	if (bHandled) { return result; }\
	}
#define CHAIN_MSG(func) \
	result=func(uMsg,wParam,lParam,bHandled); \
	if (bHandled) { return result; }

#define END_MSG_HANDLER \
	return ( DefWindowProc( m_hWnd, uMsg, wParam, lParam )); }

	class Window
	{
	public:
		Window()
		{
			m_hWnd=NULL;
		}

		~Window()
		{

		}

		BOOL RegisterClass(HINSTANCE hInstance, const TCHAR* lpszClass)
		{
			m_hInstance=hInstance;

			WNDCLASS wc;

			wc.lpszClassName = lpszClass;
			wc.lpfnWndProc = WinProc;
			wc.style = CS_VREDRAW | CS_HREDRAW;
			wc.hInstance = m_hInstance;
			wc.hIcon = NULL;
			wc.hCursor = LoadCursor( NULL, IDC_ARROW );
			wc.lpszMenuName = NULL;
			wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;

			return (::RegisterClass(&wc)!=NULL);
		}

		VOID UnregisterClass(const TCHAR* lpszClass)
		{
			::UnregisterClass(lpszClass,0);
		}

		BOOL Create(const TCHAR* lpszClass,const TCHAR* lpszTitle,int x,int y,int w,int h,DWORD style,DWORD exStyle=0,HWND hwndParent=NULL)
		{
			m_hWnd = CreateWindowEx( exStyle, lpszClass, lpszTitle,style,
				x, y,
				w, h,
				hwndParent,
				NULL,
				m_hInstance,
				(LPVOID)this);

			return (m_hWnd!=NULL);
		}


		VOID UpdateWindow()
		{
			::UpdateWindow(m_hWnd);
		}

		VOID ShowWindow(int cmd=SW_SHOW)
		{
			::ShowWindow(m_hWnd,cmd);
		}

		VOID DestroyWindow()
		{
			::DestroyWindow(m_hWnd);
		}

		virtual BOOL OnCreate() { return TRUE; }
		virtual VOID OnKeyDown(LONG key) { PostQuitMessage(0); }
		virtual VOID OnKeyUp(LONG key) {}
		virtual VOID OnMouseMove(POINT p) {}
		virtual VOID OnMouseLeave() {}
		virtual VOID OnLButtonDown(POINT p) {}
		virtual VOID OnLButtonUp(POINT p) {}
		virtual VOID OnRButtonDown(POINT p) {}
		virtual VOID OnRButtonUp(POINT p) {}
		virtual VOID Draw(HDC hdc,LPRECT rc) {}

		virtual LRESULT CALLBACK WindowsProc(UINT uMsg, WPARAM wParam, LPARAM lParam) { return DefWindowProc( m_hWnd, uMsg, wParam, lParam ); }

	protected:

		virtual LRESULT OnKeyEvent( UINT msg, WPARAM wparam, LPARAM lparam, BOOL& bHandled )
		{
			LONG key = (LONG)wparam;
			switch(msg) {
	case WM_KEYDOWN:
		OnKeyDown(key);
		break;
	case WM_KEYUP:
		OnKeyUp(key);
		break;
			}
			return 0;
		}

		virtual LRESULT OnMouseEvent( UINT msg, WPARAM wparam, LPARAM lparam, BOOL& bHandled )
		{
			POINT P;
			P.x=LOWORD(lparam);
			P.y=HIWORD(lparam);

			switch(msg)
			{
			case WM_LBUTTONDOWN: OnLButtonDown(P); break;
			case WM_LBUTTONUP:   OnLButtonUp(P);   break;
			case WM_RBUTTONDOWN: OnRButtonDown(P); break;
			case WM_RBUTTONUP:   OnRButtonUp(P);   break;
			case WM_MOUSEMOVE:   OnMouseMove(P); break;
			case WM_MOUSELEAVE:  OnMouseLeave(); break;
			}
			return 0;
		}

		virtual LRESULT OnPaint( UINT msg, WPARAM wparam, LPARAM lparam, BOOL& bHandled )
		{
			PAINTSTRUCT ps;
			BeginPaint(m_hWnd,&ps);
			Draw(ps.hdc, &ps.rcPaint);
			EndPaint(m_hWnd,&ps);
			return 0;
		}

	public:
		HWND m_hWnd;
		HINSTANCE m_hInstance;
	};

	static LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		Window *w=NULL;
		if (uMsg==WM_CREATE) {
			LPCREATESTRUCT cs=(LPCREATESTRUCT)lParam;
			w=reinterpret_cast<Window*>(cs->lpCreateParams);
			w->m_hWnd=hWnd;
			SetWindowLong(hWnd,GWL_USERDATA,(LONG)w);
			w->OnCreate();
		} else {
			w=reinterpret_cast<Window*>(GetWindowLong(hWnd,GWL_USERDATA));
		}
		if (w) {
			w->m_hWnd = hWnd;
			return (w->WindowsProc(uMsg,wParam,lParam));
		}
		return (DefWindowProc(hWnd, uMsg, wParam, lParam));
	}

}