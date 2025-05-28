#pragma once

enum MouseMSG { NONE, LBD, LBU, RBD, RBU, MBD, MBU, LDBLK, RDBLK, MDBLK };

int OnMouseWhell(HWND hWnd, WPARAM wParam, LPARAM lParam);
int OnMouseLBTNDBLCK(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseRBTNDBLCK(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseMBTNDBLCK(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseLBUTTONDOWN(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseLBUTTONUP(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseRBUTTONDOMN(HWND hWnd, WPARAM wParam, LPARAM lParam);
;
int OnMouseRBUTTONUP(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseMBUTTONDOWN(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseMBUTTONUP(HWND hWnd, WPARAM wParam, LPARAM lParam);
