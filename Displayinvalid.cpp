//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Displayinvalid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TInvalidForm *InvalidForm;
//---------------------------------------------------------------------------
__fastcall TInvalidForm::TInvalidForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TInvalidForm::FormCreate(TObject *Sender)
{
	clickok->Position->Y+=36;
	Rectangle1->Height+=10;
	Text4->Position->Y+=20;
}
//---------------------------------------------------------------------------
void __fastcall TInvalidForm::clickokMouseEnter(TObject *Sender)
{
	TAlphaColor color = StringToAlphaColor("#FF33E2D1"); // Ví dụ mã màu với alpha

	// Đặt màu cho TRoundRect hoặc thành phần khác
	clickok->Fill->Color = color;
	rrok->Fill->Color=StringToAlphaColor("#FF33FBFF");
}
//---------------------------------------------------------------------------
void __fastcall TInvalidForm::clickokMouseLeave(TObject *Sender)
{
	clickok->Fill->Color=StringToAlphaColor("#FF00AFD1");
	rrok->Fill->Color=StringToAlphaColor("#FF00C8F0");
}
//---------------------------------------------------------------------------
void __fastcall TInvalidForm::clickokMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	clickok->Fill->Color=StringToAlphaColor("#FF00AFD1");
	rrok->Fill->Color=StringToAlphaColor("#FF00C8F0");
}
//---------------------------------------------------------------------------
void __fastcall TInvalidForm::clickokMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
    TAlphaColor color = StringToAlphaColor("#FF33E2D1"); // Ví dụ mã màu với alpha

	// Đặt màu cho TRoundRect hoặc thành phần khác
	clickok->Fill->Color = color;
	rrok->Fill->Color=StringToAlphaColor("#FF33FBFF");
}
//---------------------------------------------------------------------------
void __fastcall TInvalidForm::clickokClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TInvalidForm::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (Key==VK_RETURN) {
            clickok->OnClick(clickok);
	}
}
//---------------------------------------------------------------------------

