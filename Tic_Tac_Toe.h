	//---------------------------------------------------------------------------

	#ifndef Tic_Tac_ToeH
	#define Tic_Tac_ToeH
	//---------------------------------------------------------------------------
	#include <System.Classes.hpp>
	#include <FMX.Controls.hpp>
	#include <FMX.Forms.hpp>
	#include <FMX.Objects.hpp>
	#include <FMX.Types.hpp>
	#include <FMX.Controls.Presentation.hpp>
	#include <FMX.StdCtrls.hpp>
	#include <FMX.Edit.hpp>
	#include <FMX.Ani.hpp>
	#include <FMX.Colors.hpp>
	#include <FMX.Effects.hpp>
	#include <FMX.Controls3D.hpp>
	#include <FMX.Objects3D.hpp>
	#include <System.Math.Vectors.hpp>
	#include <FMX.DateTimeCtrls.hpp>
	#include <FMX.Filter.Effects.hpp>
    #include <FMX.Dialogs.hpp>
	#include <FMX.Media.hpp>
	#include <string>
	#include <System.UITypes.hpp>
	#include "Board.h"
	#include "Player.h"
	#include "Game.h"
	#include "Displayinvalid.h"
	//---------------------------------------------------------------------------
	class TForm_Game : public TForm
	{
	__published:	// IDE-managed Components
		TImage *I_backgr;
		TRectangle *R_login;
		TRectangle *R_form_login;
		TRectangle *Rectangle1;
		TImage *Image1;
		TLabel *Label1;
		TLabel *Label2;
		TLine *Line1;
		TLine *Line2;
		TEdit *e_user;
		TEdit *e_pass;
		TRoundRect *RoundRect1;
		TGlowEffect *gle1;
		TImage *i_login_text;
		TRectangle *R_mode;
		TRectangle *Rectangle2;
		TRectangle *Rectangle3;
		TGlowEffect *gle2;
		TGlowEffect *gle3;
		TImage *i_bot_text;
		TImage *i_vs2_text;
		TRoundRect *RoundRect2;
		TText *Text1;
		TRectangle *Rectangle4;
		TRectangle *Rectangle5;
		TRoundRect *RoundRect3;
		TText *Text2;
		TTimer *Timer1;
		TLabel *Label3;
		TImage *i_bgame;
		TTimer *Timer2;
		TRectangle *R_choose;
		TRectangle *R_player1;
		TRectangle *R_player2;
		TRectangle *R_choose_pl1_X;
		TText *T_choose_pl1_X;
		TRectangle *R_choose_pl1_O;
		TText *T_choose_pl1_O;
		TText *Text5;
		TGlowEffect *G_choose_pl1;
		TGlowEffect *G_choose_pl2;
		TText *Text3;
		TRectangle *R_choose_pl2_X;
		TText *T_choose_pl2_X;
		TRectangle *R_choose_pl2_O;
		TText *T_choose_pl2_O;
		TImage *image2;
		TImage *Image3;
		TRectangle *R_resetpl1;
		TImage *I_resetpl1;
		TRectangle *R_resetpl2;
		TImage *I_resetpl2;
		TRoundRect *RR_pl1;
		TGlowEffect *G_steppl1;
		TRoundRect *RR_pl2;
		TGlowEffect *G_steppl2;
		TRoundRect *RR_random;
		TGlowEffect *G_steprandom;
		TImage *I_steppl1;
		TImage *I_steprandom;
		TImage *I_steppl2;
		TRoundRect *RR_fight;
		TGlowEffect *G_fight;
		TText *T_fight;
		TText *Text4;
		TGlowEffect *GlowEffect2;
		TRoundRect *RR_text;
		TText *Text6;
		TGlowEffect *GlowEffect3;
		TRectangle *RR_CA1;
		TRoundRect *RR_reset;
		TGlowEffect *G_reset;
		TImage *I_reset;
	TRectangle *R_board;
	TRectangle *Z;
	TTimer *Timer3;
	TText *Text7;
	TGlowEffect *GlowEffect7;
	TFloatAnimation *FloatAnimation1;
	TFloatAnimation *FloatAnimation2;
	TMediaPlayer *MediaPlayer1;
	TImage *Image4;
	TFloatAnimation *FloatAnimation3;
	TRectangle *R_play;
	TButton *b1_0;
	TButton *b2_1;
	TButton *b0_0;
	TButton *b0_1;
	TButton *b2_0;
	TButton *b1_1;
	TButton *b0_2;
	TButton *b2_2;
	TButton *b1_2;
	TImage *Image5;
	TImage *Image6;
	TText *Text8;
	TText *Text9;
	TGlowEffect *GlowEffect6;
	TFillEffect *F0_0;
	TGlowEffect *GlowEffect4;
	TImage *Image7;
	TGlowEffect *GlowEffect5;
	TGlowEffect *GlowEffect8;
	TText *Text10;
	TImage *Image8;
	TRoundRect *RR_backchoose;
	TImage *Image9;
	TGlowEffect *G_backchoose;
	TGlowEffect *GlowEffect9;
	TImage *Image10;
	TText *Text11;
	TGlowEffect *GlowEffect10;
	TMediaPlayer *MediaPlayer2;
	TMediaPlayer *MediaPlayer3;
	TRoundRect *RR_backplay;
	TImage *Image11;
	TTimer *Timer4;
	TRoundRect *RR_easy;
	TFloatAnimation *FloatAnimation4;
	TRoundRect *RR_normal;
	TRoundRect *RR_hard;
	TText *Text12;
	TText *Text13;
	TText *Text14;
	TFloatAnimation *FloatAnimation5;
	TFloatAnimation *FloatAnimation6;
	TFloatAnimation *FloatAnimation7;
	TFloatAnimation *FloatAnimation8;
	TFloatAnimation *FloatAnimation9;
	TFloatAnimation *FloatAnimation10;
	TFloatAnimation *FloatAnimation11;
	TLine *Line3;
	TGlowEffect *GlowEffect11;
	TShadowEffect *ShadowEffect2;
	TMediaPlayer *MediaPlayer4;
		void __fastcall RoundRect1MouseEnter(TObject *Sender);
		void __fastcall RoundRect1MouseLeave(TObject *Sender);
		void __fastcall RoundRect1Click(TObject *Sender);
		void __fastcall RoundRect1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RoundRect1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall Rectangle2MouseEnter(TObject *Sender);
		void __fastcall Rectangle2MouseLeave(TObject *Sender);
		void __fastcall Rectangle2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall Rectangle2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall Rectangle3MouseEnter(TObject *Sender);
		void __fastcall Rectangle3MouseLeave(TObject *Sender);
		void __fastcall Rectangle3MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall Rectangle3MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall Rectangle2Click(TObject *Sender);
		void __fastcall Rectangle2MouseMove(TObject *Sender, TShiftState Shift, float X,
			  float Y);
		void __fastcall Rectangle3MouseMove(TObject *Sender, TShiftState Shift, float X,
			  float Y);
		void __fastcall Timer1Timer(TObject *Sender);
		void __fastcall R_choose_pl1_XMouseEnter(TObject *Sender);
		void __fastcall R_choose_pl1_XMouseLeave(TObject *Sender);
		void __fastcall R_choose_pl1_XMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_choose_pl1_XMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_choose_pl1_XClick(TObject *Sender);
		void __fastcall R_choose_pl1_OMouseEnter(TObject *Sender);
		void __fastcall R_choose_pl1_OMouseLeave(TObject *Sender);
		void __fastcall R_choose_pl1_OMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_choose_pl1_OMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_choose_pl1_OClick(TObject *Sender);
		void __fastcall R_choose_pl2_XMouseEnter(TObject *Sender);
		void __fastcall R_choose_pl2_XMouseLeave(TObject *Sender);
		void __fastcall R_choose_pl2_XMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_choose_pl2_XMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_choose_pl2_XClick(TObject *Sender);
		void __fastcall R_choose_pl2_OMouseEnter(TObject *Sender);
		void __fastcall R_choose_pl2_OMouseLeave(TObject *Sender);
		void __fastcall R_choose_pl2_OMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_choose_pl2_OMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_choose_pl2_OClick(TObject *Sender);
		void __fastcall R_resetpl1MouseEnter(TObject *Sender);
		void __fastcall R_resetpl1MouseLeave(TObject *Sender);
		void __fastcall R_resetpl1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_resetpl1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_resetpl2MouseEnter(TObject *Sender);
		void __fastcall R_resetpl2MouseLeave(TObject *Sender);
		void __fastcall R_resetpl2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall R_resetpl2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_pl1MouseEnter(TObject *Sender);
		void __fastcall RR_pl1MouseLeave(TObject *Sender);
		void __fastcall RR_pl1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_pl1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_pl2MouseEnter(TObject *Sender);
		void __fastcall RR_pl2MouseLeave(TObject *Sender);
		void __fastcall RR_pl2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_pl2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_randomMouseEnter(TObject *Sender);
		void __fastcall RR_randomMouseLeave(TObject *Sender);
		void __fastcall RR_randomMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_randomMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_fightMouseEnter(TObject *Sender);
		void __fastcall RR_fightMouseLeave(TObject *Sender);
		void __fastcall RR_fightMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_fightMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_pl1MouseMove(TObject *Sender, TShiftState Shift, float X, float Y);
		void __fastcall RR_pl2MouseMove(TObject *Sender, TShiftState Shift, float X, float Y);
		void __fastcall RR_randomMouseMove(TObject *Sender, TShiftState Shift, float X,
			  float Y);
		void __fastcall R_resetpl1Click(TObject *Sender);
		void __fastcall R_resetpl2Click(TObject *Sender);
		void __fastcall RR_pl1Click(TObject *Sender);
		void __fastcall RR_pl2Click(TObject *Sender);
		void __fastcall RR_randomClick(TObject *Sender);
		void __fastcall RR_resetMouseEnter(TObject *Sender);
		void __fastcall RR_resetMouseLeave(TObject *Sender);
		void __fastcall RR_resetMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_resetMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
			  float X, float Y);
		void __fastcall RR_resetMouseMove(TObject *Sender, TShiftState Shift, float X, float Y);
		void __fastcall RR_resetClick(TObject *Sender);
		void __fastcall ActiveButtonAC(bool checkpl1_X, bool checkpl2_X, bool checkpl1_O, bool checkpl2_O,bool checksteppl1,bool checksteppl2, bool checksteprandom);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall RR_fightClick(TObject *Sender);
	void __fastcall R_chooseMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);

		//void __fastcall SolveAppearButtonFight();
		//void __fastcall FormCreate(TObject *Sender);

	void __fastcall SetHitTestFalse(TRectangle* r_choose_pl1_o, TRectangle* r_choose_pl2_o, TRectangle* r_choose_pl2_x,
					 TRectangle* r_reset_pl1, TRectangle* r_reset_pl2, TRoundRect* rr_pl1,
					 TRoundRect* rr_pl2, TRoundRect* rr_reset, TRoundRect* rr_random,TRoundRect* RR4);
	void __fastcall SetHitTestTrue(TRectangle* r_choose_pl1_o, TRectangle* r_choose_pl2_o, TRectangle* r_choose_pl2_x,
					 TRectangle* r_reset_pl1, TRectangle* r_reset_pl2, TRoundRect* rr_pl1,
					 TRoundRect* rr_pl2, TRoundRect* rr_reset, TRoundRect* rr_random,TRoundRect* RR4);
	void __fastcall SetHitTestFalse1(TRectangle* R1, TRectangle* R2, TRectangle* R3,
					 TRectangle* R4, TRectangle* R5, TRectangle* R6,
					 TRoundRect* RR1, TRoundRect* RR2, TRoundRect* RR3,TRoundRect* RR4);
	void __fastcall SetHitTestTrue1(TRectangle* R1, TRectangle* R2, TRectangle* R3,
					 TRectangle* R4, TRectangle* R5, TRectangle* R6,
					 TRoundRect* RR1, TRoundRect* RR2, TRoundRect* RR3,TRoundRect* RR4);
	void __fastcall b0_0Click(TObject *Sender);
	void __fastcall b0_1Click(TObject *Sender);
	void __fastcall b0_2Click(TObject *Sender);
	void __fastcall b1_0Click(TObject *Sender);
	void __fastcall b1_1Click(TObject *Sender);
	void __fastcall b1_2Click(TObject *Sender);
	void __fastcall b2_0Click(TObject *Sender);
	void __fastcall b2_1Click(TObject *Sender);
	void __fastcall b2_2Click(TObject *Sender);
	void __fastcall HandleCellClick(TButton* button,int n, int m);
	void __fastcall RR_backchooseClick(TObject *Sender);
	void __fastcall RR_backchooseMouseEnter(TObject *Sender);
	void __fastcall RR_backchooseMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  float X, float Y);
	void __fastcall ResetButton();
	void __fastcall RR_backchooseMouseLeave(TObject *Sender);
	void __fastcall Rectangle3Click(TObject *Sender);
	void __fastcall RR_backchooseMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  float X, float Y);
	void __fastcall EndGame();
	void __fastcall UpdateUIAfterMove();
	void __fastcall RR_backplayClick(TObject *Sender);
	void __fastcall RR_backplayMouseLeave(TObject *Sender);
	void __fastcall RR_backplayMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall RR_easyClick(TObject *Sender);
	void __fastcall RR_hardClick(TObject *Sender);
	void __fastcall RR_normalClick(TObject *Sender);
	void __fastcall FloatAnimation9Finish(TObject *Sender);
	void __fastcall FloatAnimation10Finish(TObject *Sender);
	void __fastcall FloatAnimation11Finish(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall R_loginClick(TObject *Sender);

	private:	// User declarations
	bool checkpl1_X=false;
	bool checkpl1_O=false;
	bool checkpl2_X=false;
	bool checkpl2_O=false;
	bool checksteppl1=false;
	bool checksteppl2=false;
	bool checksteprandom=false;
	bool checkrspl1=false;
	bool checkrspl2=false;
	bool checksteprs=false;
	bool checkleavers=false;
	Game *game=nullptr;
	Board *bd=nullptr;
	Board b;
	bool checkmode;
	bool checkbackchoose=false;
	bool checkmakemove=false;
    bool clickr3=false;
	public:		// User declarations
		__fastcall TForm_Game(TComponent* Owner);
	};
	//---------------------------------------------------------------------------
	extern PACKAGE TForm_Game *Form_Game;
	//---------------------------------------------------------------------------
	#endif
