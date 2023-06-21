#include<iostream>
#include <cstdio>
#include <cmath>
#include<math.h>
#include <string>
#include <windows.h>
#include<tchar.h>
#include<wchar.h>
#include<winuser.h>
#include"Calculator.h"

#define SPACE  " "


#define Show(Window) RedrawWindow(Window,0,0,0);ShowWindow(Window,SW_SHOW);
#define VAL(a) (double)atof(a)
static HINSTANCE BCX_hInstance;
static int     BCX_ScaleX;
static int     BCX_ScaleY;
static char    BCX_ClassName[2048];
static HWND    Form1;
static HWND    Edit1;
static double  Op1;
static double  Op2;
static long    OpFlag;
static long    EqFlag;
static long    Code;


// circular storage to prevent memory leaks
char *Calculator::BCX_TmpStr (size_t Bites)
{
  static int   StrCnt;
  static char *StrFunc[2048];
  StrCnt=(StrCnt + 1) & 2047;
  if(StrFunc[StrCnt]) free (StrFunc[StrCnt]);
  return StrFunc[StrCnt]=(char*)calloc(Bites+128,sizeof(char));
}


// fancy string compare
int Calculator::str_cmp (char *a, char *b)
{
  register int counter;
  counter=counter^counter;
  while(1)
  {
    if((a[counter]^b[counter]))
    {
      if((UINT) a[counter]>= (UINT) b[counter])
      {
        return  1;
      }
      return -1;
    }
    if(!a[counter]) return 0;
    counter++;
  }
  return 0;
}


// remove certain leading and trailing characters
char *Calculator::trim (char *S)
{
  register int i = strlen(S);
  char *strtmp = BCX_TmpStr(i);
  strcpy(strtmp,S);
  while(i--)
  {
   if(S[i]!=0  &&
      S[i]!=9  &&
      S[i]!=10 &&
      S[i]!=11 &&
      S[i]!=13 &&
      S[i]!=32) break;
  }
  strtmp[++i]=0;
  if (strtmp)
  {
    while(*(strtmp+1) &&
     *strtmp=='\x00' ||
     *strtmp=='\x09' ||
     *strtmp=='\x0A' ||
     *strtmp=='\x0B' ||
     *strtmp=='\x0D' ||
    (*strtmp=='\x20' ))
     strtmp++;
  }
  return strtmp;
}


// sets accuracy
char *Calculator::str (double d)
{
  register char *strtmp = BCX_TmpStr(16);
  sprintf(strtmp,"% .15G",d);
  return strtmp;
}


// returns the position where a substring is located in a string
int Calculator::instr(char* mane,char* match,int offset,int sensflag)
{
  register char *s;
  if (!mane || !match || ! *match || offset>(int)strlen(mane)) return 0;
  if (sensflag)
    s = _stristr_(offset>0 ? mane+offset-1 : mane,match);
  else
    s = strstr (offset>0 ? mane+offset-1 : mane,match);
  return s ? (int)(s-mane)+1 : 0;
}


// supports instr()
char *Calculator::_stristr_(char *String, char *Pattern)
{
  register char *pptr, *sptr, *start;
  register UINT  slen, plen;
  for (start = (char *)String,
    pptr  = (char *)Pattern,
    slen  = strlen(String),
    plen  = strlen(Pattern);
    slen >= plen;
    start++, slen--)
  {
    while (toupper(*start) != toupper(*Pattern))
    {
      start++;
      slen--;
      if (slen < plen) return(0);
    }
    sptr = start;
    pptr = (char *)Pattern;
    while (toupper(*sptr) == toupper(*pptr))
    {
      sptr++;
      pptr++;
      if (!*pptr) return (start);
    }
  }
  return(0);
}


// created the form
HWND Calculator::BCX_Form(char *Caption, int X, int Y, int W, int H, int Style, int Exstyle)
{
   HWND  A;
   // assign default style
   if (!Style)
   {
      Style = WS_MINIMIZEBOX  |
      WS_SIZEBOX      |
      WS_CAPTION      |
      WS_MAXIMIZEBOX  |
      WS_POPUP        |
      WS_SYSMENU;
   }
   A = CreateWindowEx(Exstyle,BCX_ClassName,Caption,
     Style,
     X*BCX_ScaleX,
     Y*BCX_ScaleY,
     (4+W)*BCX_ScaleX,
     (12+H)*BCX_ScaleY,
     NULL,(HMENU)NULL,BCX_hInstance,NULL);
   SendMessage(A,(UINT)WM_SETFONT,(WPARAM)GetStockObject(DEFAULT_GUI_FONT),
     (LPARAM)MAKELPARAM(FALSE,0));
   return A;
}


// create the various calculator buttons
HWND Calculator::BCX_Button(char* Text,HWND hWnd,int id,int X,int Y,int W,int H,int Style,int Exstyle)
{
  HWND  A;
  // assign default style
  if(!Style)
  {
    Style=WS_CHILD | WS_VISIBLE | BS_MULTILINE | BS_PUSHBUTTON | WS_TABSTOP;
  }
  if(Exstyle==-1)
  {
    Exstyle=WS_EX_STATICEDGE;
  }
  A = CreateWindowEx(Exstyle,"button",Text,Style,
    X*BCX_ScaleX, Y*BCX_ScaleY, W*BCX_ScaleX, H*BCX_ScaleY,
    hWnd,(HMENU)id,BCX_hInstance,NULL);
  SendMessage(A,(UINT)WM_SETFONT,(WPARAM)GetStockObject(DEFAULT_GUI_FONT),
    (LPARAM)MAKELPARAM(FALSE,0));
  if (W==0)
  {
    HDC  hdc=GetDC(A);
    SIZE  size;
    GetTextExtentPoint32(hdc,Text,strlen(Text),&size);
    ReleaseDC(A,hdc);
    MoveWindow(A,X*BCX_ScaleX,Y*BCX_ScaleY,(int)(size.cx+(size.cx*0.5)),(int)(size.cy+(size.cy*0.32)),TRUE);
  }
  return A;
}


// create the edit box to display entry and result
HWND Calculator::BCX_Edit(char* Text,HWND hWnd,int id,int X,int Y,int W,int H,int Style,int Exstyle)
{
  HWND  A;
  // assign default style
  if (!Style)
  {
      Style = WS_CHILD | WS_VISIBLE | ES_WANTRETURN |
              WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL;
  }
  if (Exstyle==-1)
  {
      Exstyle = WS_EX_CLIENTEDGE;
  }
  A = CreateWindowEx(Exstyle,"edit",Text, Style,
      X*BCX_ScaleX, Y*BCX_ScaleY, W*BCX_ScaleX, H*BCX_ScaleY,
      hWnd,(HMENU)id,BCX_hInstance,NULL);

  SendMessage(A,(UINT)WM_SETFONT,(WPARAM)GetStockObject(DEFAULT_GUI_FONT),
    (LPARAM)MAKELPARAM(FALSE,0));
  return A;
}


char *Calculator::BCX_Get_Text(HWND hWnd)
{
  int tmpint;
  tmpint = 1 + GetWindowTextLength(hWnd);
  char *strtmp = BCX_TmpStr(tmpint);
  GetWindowText(hWnd,strtmp,tmpint);
  return strtmp;
}


int Calculator::BCX_Set_Text(HWND hWnd, char *Text)
{
  return SetWindowText(hWnd,Text);
}


LRESULT Calculator::Set_Color (int TxtColr,int BkColr,int wParam,int lParam)
{
  static HBRUSH  ReUsableBrush;
  DeleteObject(ReUsableBrush);
  ReUsableBrush=CreateSolidBrush(BkColr);
  SetTextColor((HDC)wParam,TxtColr);
  SetBkColor((HDC)wParam,BkColr);
  return (LRESULT)ReUsableBrush;
}


HFONT Calculator::BCX_Set_Font (char *Font,int Size,int Bold,int Italic,int Underline,int StrikeThru)
{
  HDC hDC = GetDC(HWND_DESKTOP);
  int CyPixels = GetDeviceCaps(hDC,LOGPIXELSY);
  ReleaseDC(HWND_DESKTOP,hDC);
  return CreateFont(0-(Size*CyPixels)/72,0,0,0,Bold,Italic,Underline,StrikeThru,
  0,OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_DONTCARE,Font);
}


// details like corner coordinates,width,length,text,font
void Calculator::FormLoad (void)
  {
    Form1 = BCX_Form("Calculator",67,42,192,130);
    Edit1 = BCX_Edit(SPACE,Form1,99,-1,3,200,20);
    SendMessage(Edit1,(UINT)WM_SETFONT,(WPARAM)BCX_Set_Font("Verdana",14),1);
    BCX_Button("0",Form1,100,6,97,50,20);
    BCX_Button("1",Form1,101,6,74,20,20);
    BCX_Button("2",Form1,102,36,74,20,20);
    BCX_Button("3",Form1,103,66,74,20,20);
    BCX_Button("4",Form1,104,6,52,20,20);
    BCX_Button("5",Form1,105,36,52,20,20);
    BCX_Button("6",Form1,106,66,52,20,20);
    BCX_Button("7",Form1,107,6,29,20,20);
    BCX_Button("8",Form1,108,36,29,20,20);
    BCX_Button("9",Form1,109,66,29,20,20);
    BCX_Button(".",Form1,110,66,96,20,20);
    BCX_Button("CE",Form1,112,132,29,20,20);
    BCX_Button("-",Form1,113,132,52,20,20);
    BCX_Button("/",Form1,114,132,74,20,20);
    BCX_Button("%",Form1,115,132,96,20,20);
    BCX_Button("C",Form1,116,103,29,20,20);
    BCX_Button("+",Form1,117,103,52,20,20);

    BCX_Button("X",Form1,118,103,74,20,20);
    BCX_Button("=",Form1,119,103,96,20,20);
    BCX_Button("1/X",Form1,120,162,29,20,20);
    BCX_Button("X^2",Form1,121,162,52,20,20);
    BCX_Button("SQR",Form1,122,162,74,20,20);
    BCX_Button("neg",Form1,123,162,96,20,20);

    Show(Form1);
  }


LRESULT CALLBACK WndProc (HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    Calculator cal;
  while(1)
  {
  if(LOWORD(wParam)>99&&LOWORD(wParam)<110)
    {
        cal.ProcessNumber(LOWORD(wParam)-100);
        break;
    }
  if(LOWORD(wParam)>109)
    {
       cal.ProcessOperator(LOWORD(wParam));
    }
  break;
  }
  if((HWND)lParam==Edit1 && Msg==WM_CTLCOLOREDIT)
    return cal.Set_Color(RGB(0,225,0),RGB(0,0,0),wParam,lParam);
  // tidy up and exit program
  if(Msg==WM_DESTROY)
  {
       UnregisterClass(BCX_ClassName,BCX_hInstance);
       PostQuitMessage(0);
  }
 return DefWindowProc(hWnd,Msg,wParam,lParam);
}


void Calculator::ProcessNumber (int Digit)
{
  char A[2048];
  strcpy(A,(char*)BCX_Get_Text(Edit1));
  if(str_cmp(A,SPACE)==0)
  {
      *A=0;
  }
  if(EqFlag)
  {
      *A=0;
      EqFlag=FALSE;
  }
  if(OpFlag)
  {
      *A=0;
      BCX_Set_Text(Edit1,"");
      OpFlag=FALSE;
  }
  sprintf(A,"%s%s",A,trim(str(Digit)));
  BCX_Set_Text(Edit1,A);
}


void Calculator::ProcessOperator (int Operator)
{
  char A[2048];
  strcpy(A,(char*)BCX_Get_Text(Edit1));
  if(str_cmp(A,SPACE)==0)
  {
      *A=0;
  }
  while(1)
  {
  if(Operator==110)   //  .   period
  {
      if(EqFlag)
      {
          *A=0;
          EqFlag=FALSE;
      }
      if(OpFlag)
      {
          *A=0;
          BCX_Set_Text(Edit1,"");
          OpFlag=FALSE;
      }
      if(instr(A,".")==0)
      {
          sprintf(A,"%s%s",A,".");
      }
      BCX_Set_Text(Edit1,A);
      break;
    }
    if(Operator==112)     // CE   clear last entry
    {
      BCX_Set_Text(Edit1,SPACE);
      EqFlag=FALSE;
      break;
    }
    if(Operator==113)     // -   subtract
    {
      Op1=VAL(BCX_Get_Text(Edit1));
      Code=4;
      OpFlag=TRUE;
      EqFlag=FALSE;
      break;
    }
    if(Operator==114)      //  /   divide
    {
      Op1=VAL(BCX_Get_Text(Edit1));
      Code=2;
      OpFlag=TRUE;
      EqFlag=FALSE;
      break;
    }
    if(Operator==115)     //  %  percent to decimal
    {
      Op2=VAL(BCX_Get_Text(Edit1))/100;
      BCX_Set_Text(Edit1,trim(str(Op2)));
      EqFlag=FALSE;
      break;
    }
    if(Operator==116)      //  C   clear all
    {
      BCX_Set_Text(Edit1,SPACE);
      Op1=0;
      Op2=0;
      Code=0;
      EqFlag=FALSE;
      break;
    }
    if(Operator==117)      //  +   add
    {
      Op1=VAL(BCX_Get_Text(Edit1));
      Code=3;
      OpFlag=TRUE;
      EqFlag=FALSE;
      break;
    }
    if(Operator==118)     //  x    multiply
    {
      Op1=VAL(BCX_Get_Text(Edit1));
      Code=1;
      OpFlag=TRUE;
      EqFlag=FALSE;
      break;
    }
    if(Operator==119)       //  =  equals
    {
      Op2=VAL(BCX_Get_Text(Edit1));
      OpFlag=FALSE;
      EqFlag=TRUE;
      while(1)
      {
        if(Code==1)
        {
          Op1*=Op2;
          break;
        }
        if(Code==2)
        {
          Op1/=Op2;
          break;
        }
        if(Code==3)
        {
          Op1+=Op2;
          break;
        }
        if(Code==4)
        {
          Op1-=Op2;
        }
      break;
      }
      strcpy(A,(char*)trim(str(Op1)));
      if(instr(A,"INF"))
      {
        strcpy(A,"Error: Divison by zero");
      }
      BCX_Set_Text(Edit1,A);
      Op2=0;
      break;
    }
    if(Operator==120)     //  1/x   invert
    {
      BCX_Set_Text(Edit1,str(1/VAL(BCX_Get_Text(Edit1))));
      OpFlag=TRUE;
      EqFlag=FALSE;
      break;
    }
    if(Operator==121)     //   x^2    square
    {
      BCX_Set_Text(Edit1,str(VAL(BCX_Get_Text(Edit1))*VAL(BCX_Get_Text(Edit1))));
      OpFlag=TRUE;
      EqFlag=FALSE;
      break;
    }
    if(Operator==122)     //  sqrt   square-root
    {
      BCX_Set_Text(Edit1,str(sqrt(VAL(BCX_Get_Text(Edit1)))));
      OpFlag=TRUE;
      EqFlag=FALSE;
      break;
    }
    if(Operator==123)     //  neg = negate
    {
      BCX_Set_Text(Edit1,str(-1*VAL(BCX_Get_Text(Edit1))));
      OpFlag=TRUE;
      EqFlag=FALSE;
    }
    break;
  }
}


