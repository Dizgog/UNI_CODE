#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include"Math.h"
#include<windows.h>
#include <wchar.h>

class Calculator{
    private:

    public:
        //Calculator();
        int     str_cmp(char*, char*);
        HWND    BCX_Form(char*,int=0,int=0,int=250,int=150,int=0,int=0);
        HWND    BCX_Edit(char*,HWND,int,int,int,int,int,int=0,int=-1);
        HWND    BCX_Button(char*,HWND,int=0,int=0,int=0,int=0,int=0,int=0,int=-1);
        char*   BCX_Get_Text(HWND);
        int     BCX_Set_Text(HWND,char*);
        HFONT   BCX_Set_Font (char *,int,int=0,int=0,int=0,int=0);
        LRESULT Set_Color (int,int,int,int);
        char*   BCX_TmpStr(size_t);
        char*   trim (char*);
        char*   str (double);
        int     instr(char*,char*,int=0,int=0);
        char    *_stristr_(char*,char*);

        void    FormLoad (void);

        void    ProcessNumber (int);
        void    ProcessOperator (int);
        int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrev,LPSTR CmdLine,int CmdShow);



};

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

#endif // CALCULATOR_H_INCLUDED
