//---------------------------------------------------------------------------

#ifndef DisplayinvalidH
#define DisplayinvalidH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Media.hpp>
#include <FMX.Colors.hpp>
//---------------------------------------------------------------------------
class TInvalidForm : public TForm
{
__published:	// IDE-managed Components
	TRoundRect *clickok;
	TText *Text1;
	TRoundRect *rrok;
	TText *Text2;
	TRectangle *Rectangle1;
	TText *Text3;
	TText *Text4;
	TMediaPlayer *MediaPlayer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall clickokMouseEnter(TObject *Sender);
	void __fastcall clickokMouseLeave(TObject *Sender);
	void __fastcall clickokMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall clickokMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall clickokClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TInvalidForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInvalidForm *InvalidForm;
//---------------------------------------------------------------------------
#endif
