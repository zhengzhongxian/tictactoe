#include <fmx.h>
#include <fstream>
#include <System.Classes.hpp>
#pragma hdrstop

#include "Tic_Tac_Toe.h"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm_Game *Form_Game;
bool checkuppl1=false;

//---------------------------------------------------------------------------
__fastcall TForm_Game::TForm_Game(TComponent* Owner)
	: TForm(Owner)
{
	MediaPlayer3->Play();
	game = new Game();
	game->SetPlayer1(new Player());
	game->SetPlayer2(new Player());
	bd=new Board();
	game->SetRobot(new Robot(Form_Game));
	game->GetRobot()->Set_mode(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm_Game::RoundRect1MouseEnter(TObject *Sender)
{
	gle1->Softness=2.5;
	i_login_text->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Game::RoundRect1MouseLeave(TObject *Sender)
{
	gle1->Softness=1.5;
	i_login_text->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Game::RoundRect1Click(TObject *Sender)
{
	if (e_user->Text.IsEmpty() || e_pass->Text.IsEmpty()) {
	   ShowMessage("Please enter both username and password.");
		return;
	}
	bool check=false;
	fstream file("C:\\Users\\ADMIN\\Downloads\\OOP_Final_Project (3)\\OOP_Final_Project\\account_tictactoe.txt",ios::in);
	if (file.is_open()) {
		string user,pass;
		while (file>>user>>pass){
			if (user.c_str()==e_user->Text && pass.c_str()==e_pass->Text) {
				 R_login->Visible=false;
				 R_mode->Visible=true;
				 check=true;
				 break;
			}
		}
		file.close();
	}
	else{

	}
	if (!check) {
		e_user->Text="";
		e_pass->Text="";
		TInvalidForm *form1 = new TInvalidForm(this);
        MessageBeep(0);
		if(form1->ShowModal()==1)  MessageBeep(0);
		delete form1;
		e_user->SetFocus();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::RoundRect1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, float X, float Y)
{
	gle1->Softness=1;
	i_login_text->Enabled = true;
}
void __fastcall TForm_Game::RoundRect1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	gle1->Softness=1.5;
	i_login_text->Enabled = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm_Game::Rectangle2MouseEnter(TObject *Sender)
{
	gle2->Softness=5;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle2MouseLeave(TObject *Sender)
{
	gle2->Softness=3.5;
	Rectangle4->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	gle2->Softness=2.5;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	gle2->Softness=3.5;
	//i_dual_player->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle3MouseEnter(TObject *Sender)
{
	gle3->Softness=5;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle3MouseLeave(TObject *Sender)
{
	gle3->Softness=3.5;
	Rectangle5->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle3MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	gle3->Softness=2.5;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	gle3->Softness=3.5;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle2Click(TObject *Sender)
{
	I_backgr->Align = TAlignLayout::None;
	I_backgr->Position->X+=20;
	Line3->Visible = true;
	Line3->Align = TAlignLayout::None;
	Line3->Position->X+=20;
	//i_bgame->Visible =true;
	Timer1->Enabled = true;
	checkmode=true;
	image2->Visible=true;
	Image8->Visible=false;
	TAlphaColor alphaColor = StringToAlphaColor("#FF00FFFF");
	G_choose_pl2->GlowColor = alphaColor;
	R_player2->Stroke->Color= alphaColor;
	Text3->Text="PlAYER 2";
	G_choose_pl2->Opacity=0.5;
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::Rectangle2MouseMove(TObject *Sender, TShiftState Shift,
		  float X, float Y)
{
	Rectangle4->Visible=true;
	Rectangle4->Position->X=X+40;
	if (X>=112) {
		Rectangle4->Position->X=X+250;
	}
	Rectangle4->Position->Y=Y-90;
	if (Y>=58) {
		Rectangle4->Position->Y=Y-10;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle3MouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
	Rectangle5->Visible=true;
	Rectangle5->Position->X=X-370;
	if (X>=112) {
		Rectangle5->Position->X=X-170;
	}
	Rectangle5->Position->Y=Y+200;
	if (Y>=58) {
		Rectangle5->Position->Y=Y+300;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm_Game::Timer1Timer(TObject *Sender)
{
	I_backgr->Position->X+=20;
	Line3->Position->X+=20;
	if (I_backgr->Position->X > this->Width	) {
		I_backgr->Visible = false;
		Timer1->Enabled = false;
        Line3->Visible =false;
		R_choose->Visible=true;
	}
}
//---------------------------------------------------------------------------





void __fastcall TForm_Game::R_choose_pl1_XMouseEnter(TObject *Sender)
{
	R_choose_pl1_X->Opacity = 1;
	R_choose_pl1_X->Stroke->Kind = TBrushKind::Solid;
	R_choose_pl1_X->Stroke->Thickness = 1;
	R_choose_pl1_X->Stroke->Color = claWhite;
	T_choose_pl1_X->TextSettings->Font->Size=48;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl1_XMouseLeave(TObject *Sender)
{
	if (!checkpl1_X) {
		R_choose_pl1_X->Opacity = 0;
		R_choose_pl1_X->Stroke->Kind = TBrushKind::None;
		T_choose_pl1_X->TextSettings->Font->Size=36;
        RR_pl1->HitTest=true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl1_XMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(!checkpl1_X){
		R_choose_pl1_X->Opacity = 1;
		R_choose_pl1_X->Stroke->Kind = TBrushKind::Solid;
		R_choose_pl1_X->Stroke->Thickness = 1;
		R_choose_pl1_X->Stroke->Color = claWhite;
		T_choose_pl1_X->TextSettings->Font->Size=36;
		T_choose_pl1_X->Opacity = 0.6;
		checkpl1_X=true;
        R_choose_pl1_O->Enabled = false;
		R_choose_pl2_X->Enabled = false;
        SetHitTestFalse(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_resetpl1, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl1_XMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	R_choose_pl1_X->Opacity = 1;
	R_choose_pl1_X->Stroke->Kind = TBrushKind::Solid;
	R_choose_pl1_X->Stroke->Thickness = 1;
	R_choose_pl1_X->Stroke->Color = claWhite;
	T_choose_pl1_X->TextSettings->Font->Size=48;
	T_choose_pl1_X->Opacity = 1;
	checkuppl1=true;
	SetHitTestTrue(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_resetpl1, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
}
//---------------------------------------------------------------------------



void __fastcall TForm_Game::R_choose_pl1_XClick(TObject *Sender)
{
	ActiveButtonAC(checkpl1_X, checkpl2_X, checkpl1_O, checkpl2_O,checksteppl1,checksteppl2,checksteprandom);
	if (game && game->GetPlayer1()) {
		game->GetPlayer1()->SetChar('X');
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl1_OMouseEnter(TObject *Sender)
{
	R_choose_pl1_O->Opacity = 1;
	R_choose_pl1_O->Stroke->Kind = TBrushKind::Solid;
	R_choose_pl1_O->Stroke->Thickness = 1;
	R_choose_pl1_O->Stroke->Color = claWhite;
	T_choose_pl1_O->TextSettings->Font->Size=48;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl1_OMouseLeave(TObject *Sender)
{
	if (!checkpl1_O) {
		R_choose_pl1_O->Opacity = 0;
		R_choose_pl1_O->Stroke->Kind = TBrushKind::None;
		T_choose_pl1_O->TextSettings->Font->Size=36;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl1_OMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(!checkpl1_O){
		R_choose_pl1_O->Opacity = 1;
		R_choose_pl1_O->Stroke->Kind = TBrushKind::Solid;
		R_choose_pl1_O->Stroke->Thickness = 1;
		R_choose_pl1_O->Stroke->Color = claWhite;
		T_choose_pl1_O->TextSettings->Font->Size=36;
		T_choose_pl1_O->Opacity = 0.6;
		checkpl1_O=true;
        R_choose_pl1_X->Enabled = false;
		R_choose_pl2_O->Enabled = false;
		SetHitTestFalse(R_choose_pl1_X , R_choose_pl2_O, R_choose_pl2_X,
					R_resetpl1, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl1_OMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	R_choose_pl1_O->Opacity = 1;
	R_choose_pl1_O->Stroke->Kind = TBrushKind::Solid;
	R_choose_pl1_O->Stroke->Thickness = 1;
	R_choose_pl1_O->Stroke->Color = claWhite;
	T_choose_pl1_O->TextSettings->Font->Size=48;
	T_choose_pl1_O->Opacity = 1;
	SetHitTestTrue(R_choose_pl1_X, R_choose_pl2_O, R_choose_pl2_X,
                    R_resetpl1, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl1_OClick(TObject *Sender)
{
	ActiveButtonAC(checkpl1_X, checkpl2_X, checkpl1_O, checkpl2_O,checksteppl1,checksteppl2,checksteprandom);
	 if (game && game->GetPlayer1()) {
		game->GetPlayer1()->SetChar('O');
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_XMouseEnter(TObject *Sender)
{
	R_choose_pl2_X->Opacity = 1;
	R_choose_pl2_X->Stroke->Kind = TBrushKind::Solid;
	R_choose_pl2_X->Stroke->Thickness = 1;
	R_choose_pl2_X->Stroke->Color = claWhite;
	T_choose_pl2_X->TextSettings->Font->Size=48;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_XMouseLeave(TObject *Sender)
{
	if (!checkpl2_X) {
		R_choose_pl2_X->Opacity = 0;
		R_choose_pl2_X->Stroke->Kind = TBrushKind::None;
		T_choose_pl2_X->TextSettings->Font->Size=36;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_XMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	R_choose_pl2_X->Opacity = 1;
	R_choose_pl2_X->Stroke->Kind = TBrushKind::Solid;
	R_choose_pl2_X->Stroke->Thickness = 1;
	R_choose_pl2_X->Stroke->Color = claWhite;
	T_choose_pl2_X->TextSettings->Font->Size=48;
	T_choose_pl2_X->Opacity = 1;
    SetHitTestTrue(R_choose_pl1_X , R_choose_pl2_O, R_choose_pl1_O,
					R_resetpl1, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_XMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(!checkpl2_X){
		R_choose_pl2_X->Opacity = 1;
		R_choose_pl2_X->Stroke->Kind = TBrushKind::Solid;
		R_choose_pl2_X->Stroke->Thickness = 1;
		R_choose_pl2_X->Stroke->Color = claWhite;
		T_choose_pl2_X->TextSettings->Font->Size=36;
		T_choose_pl2_X->Opacity = 0.6;
		checkpl2_X=true;
        R_choose_pl2_O->Enabled = false;
		R_choose_pl1_X->Enabled = false;
		SetHitTestFalse(R_choose_pl1_X , R_choose_pl2_O, R_choose_pl1_O,
					R_resetpl1, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_XClick(TObject *Sender)
{
	ActiveButtonAC(checkpl1_X, checkpl2_X, checkpl1_O, checkpl2_O,checksteppl1,checksteppl2,checksteprandom);
	if(checkmode){
		if (game && game->GetPlayer2()) {
			game->GetPlayer2()->SetChar('X');
		}
	}
	else{
		if (game && game->GetRobot()) {
			game->GetRobot()->SetChar('X');
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_OMouseEnter(TObject *Sender)
{
	R_choose_pl2_O->Opacity = 1;
	R_choose_pl2_O->Stroke->Kind = TBrushKind::Solid;
	R_choose_pl2_O->Stroke->Thickness = 1;
	R_choose_pl2_O->Stroke->Color = claWhite;
	T_choose_pl2_O->TextSettings->Font->Size=48;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_OMouseLeave(TObject *Sender)
{
	if (!checkpl2_O) {
		R_choose_pl2_O->Opacity = 0;
		R_choose_pl2_O->Stroke->Kind = TBrushKind::None;
		T_choose_pl2_O->TextSettings->Font->Size=36;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_OMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	R_choose_pl2_O->Opacity = 1;
	R_choose_pl2_O->Stroke->Kind = TBrushKind::Solid;
	R_choose_pl2_O->Stroke->Thickness = 1;
	R_choose_pl2_O->Stroke->Color = claWhite;
	T_choose_pl2_O->TextSettings->Font->Size=48;
	T_choose_pl2_O->Opacity = 1;
	SetHitTestTrue(R_choose_pl1_X , R_choose_pl2_X, R_choose_pl1_O,
					R_resetpl1, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_OMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(!checkpl2_O){
		R_choose_pl2_O->Opacity = 1;
		R_choose_pl2_O->Stroke->Kind = TBrushKind::Solid;
		R_choose_pl2_O->Stroke->Thickness = 1;
		R_choose_pl2_O->Stroke->Color = claWhite;
		T_choose_pl2_O->TextSettings->Font->Size=36;
		T_choose_pl2_O->Opacity = 0.6;
		checkpl2_O=true;
		SetHitTestFalse(R_choose_pl1_X , R_choose_pl2_X, R_choose_pl1_O,
					R_resetpl1, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
        R_choose_pl2_X->Enabled = false;
		R_choose_pl1_O->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_choose_pl2_OClick(TObject *Sender)
{
	ActiveButtonAC(checkpl1_X, checkpl2_X, checkpl1_O, checkpl2_O,checksteppl1,checksteppl2,checksteprandom);
	if(checkmode){
		if (game && game->GetPlayer2()) {
			game->GetPlayer2()->SetChar('O');
		}
	}
	else{
		if (game->GetRobot() && game) {
			game->GetRobot()->SetChar('O');
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl1MouseEnter(TObject *Sender)
{
	R_resetpl1->Stroke->Thickness=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl1MouseLeave(TObject *Sender)
{
	if(!checkrspl1){R_resetpl1->Stroke->Thickness=0;
	I_resetpl1->Opacity=1;}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
		if(!checkrspl1){
			I_resetpl1->Opacity=0.7;
			checkrspl1=true;
			SetHitTestFalse(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	I_resetpl1->Opacity=1;
	checkrspl1=false;
	SetHitTestTrue(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random, RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl2MouseEnter(TObject *Sender)
{
    R_resetpl2->Stroke->Thickness=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl2MouseLeave(TObject *Sender)
{
	if(!checkrspl2){R_resetpl2->Stroke->Thickness=0;
	I_resetpl2->Opacity=1;}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
		if(!checkrspl2){
			I_resetpl2->Opacity=0.7;
			checkrspl2=true;
			SetHitTestFalse(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_resetpl1, R_choose_pl1_X, RR_pl1,
					RR_pl2, RR_reset, RR_random, RR_backchoose);
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	 I_resetpl2->Opacity=1;
	 checkrspl2=false;
	 SetHitTestTrue(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, RR_pl1,
					RR_pl2, RR_reset, RR_random,RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl1MouseEnter(TObject *Sender)
{
	G_steppl1->Softness =2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl1MouseLeave(TObject *Sender)
{
	if (!checksteppl1){
		G_steppl1->Softness =1;
		Image6->Opacity=1;
	}
	RR_text->Visible =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(!checksteppl1)
	{
		G_steppl1->Softness =2;
		I_steppl1->Opacity =0.5;
		checksteppl1=true;
		RR_text->Visible =false;
		SetHitTestFalse1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl2, RR_reset, RR_random, RR_backchoose);
		if(checkmode){
			if (game && game->GetPlayer1()) {
				game->GetPlayer1()->setStep(true);
				if (game->GetPlayer2()) {
					game->GetPlayer2()->setStep(false);
				}
			}
			Image5->Opacity=1;
			Image6->Opacity=0.2;
		}
		else {
			if (game && game->GetPlayer1()) {
			game->GetPlayer1()->setStep(true);
				if (game->GetRobot()) {
				game->GetRobot()->setStep(false);
				}
			}
			Image5->Opacity=1;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	 I_steppl1->Opacity =1;
	 G_steppl1->Softness =2;
     SetHitTestTrue1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl2, RR_reset, RR_random, RR_backchoose);
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::RR_pl2MouseEnter(TObject *Sender)
{
	G_steppl2->Softness =2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl2MouseLeave(TObject *Sender)
{
	if (!checksteppl2) G_steppl2->Softness =1;
	RR_text->Visible =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if (!checksteppl2){
		G_steppl2->Softness =2;
		I_steppl2->Opacity =0.5;
		checksteppl2=true;
		RR_text->Visible =false;
        SetHitTestFalse1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl1, RR_reset, RR_random, RR_backchoose);
		if(checkmode){
			if (game && game->GetPlayer1()) {
				game->GetPlayer1()->setStep(false);
				if (game->GetPlayer2()) {
					game->GetPlayer2()->setStep(true);
				}
			}
			Image5->Opacity=0.3;
			Image6->Opacity=1;
		}
		else {
			if (game && game->GetPlayer1()) {
				game->GetPlayer1()->setStep(false);
				if (game->GetRobot()) {
				game->GetRobot()->setStep(true);
				}
			}
			Image5->Opacity=1;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y)
{
	 I_steppl2->Opacity =1;
	 G_steppl2->Softness =2;
	 SetHitTestTrue1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl1, RR_reset, RR_random,RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_randomMouseEnter(TObject *Sender)
{
	G_steprandom->Softness=2;
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::RR_randomMouseLeave(TObject *Sender)
{
	 if(!checksteprandom) G_steprandom->Softness=1;
     RR_text->Visible =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_randomMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(!checksteprandom){
		G_steprandom->Softness =2;
		I_steprandom->Opacity =0.5;
		checksteprandom=true;
		RR_text->Visible =false;
		SetHitTestFalse1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl1, RR_reset, RR_pl2, RR_backchoose);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_randomMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	 I_steprandom->Opacity =1;
	 G_steprandom->Softness =2;
	 SetHitTestTrue1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl1, RR_reset, RR_pl2, RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_fightMouseEnter(TObject *Sender)
{
	G_fight->Softness =2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_fightMouseLeave(TObject *Sender)
{
	G_fight->Softness =1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_fightMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	G_fight->Softness =2;
	T_fight->Opacity =0.5;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_fightMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	G_fight->Softness =2;
	T_fight->Opacity =1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl1MouseMove(TObject *Sender, TShiftState Shift, float X,
          float Y)
{
	if(!checksteppl1){RR_text->Visible =true;
	Text6->Text="PLAYER 1";
	RR_text->Position->X=X+180;
	if (X>=25) {
		RR_text->Position->X=X+360;
	}
	RR_text->Position->Y=Y+75;
	if (Y>=25) {
		RR_text->Position->Y=Y+150;
	} }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl2MouseMove(TObject *Sender, TShiftState Shift, float X,
          float Y)
{
	if(!checksteppl2){RR_text->Visible =true;
	if(checkmode)Text6->Text="PLAYER 2";
	else Text6->Text="BOT";
	RR_text->Position->X=X+180;
	if (X>=25) {
		RR_text->Position->X=X+390;
	}
	RR_text->Position->Y=Y+180;
	if (Y>=25) {
		RR_text->Position->Y=Y+210;
	}}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_randomMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
	if(!checksteprandom){RR_text->Visible =true;
	Text6->Text="RANDOM";
	RR_text->Position->X=X+170;
	if (X>=25) {
		RR_text->Position->X=X+385;
	}
	RR_text->Position->Y=Y+220;
	if (Y>=25) {
		RR_text->Position->Y=Y+280;
	}
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl1Click(TObject *Sender)
{
	 if (checkpl1_X) {
		R_choose_pl1_X->Opacity = 0;
		R_choose_pl1_X->Stroke->Kind = TBrushKind::None;
		T_choose_pl1_X->TextSettings->Font->Size=36;
		if (!checkpl2_O)
		{
			R_choose_pl1_O->Enabled =true;
			R_choose_pl2_X->Enabled =true;
		}
		checkpl1_X=false;
		//X1O2--;
	 }
	 else
	 {
		R_choose_pl1_O->Opacity = 0;
		R_choose_pl1_O->Stroke->Kind = TBrushKind::None;
		T_choose_pl1_O->TextSettings->Font->Size=36;
		if (!checkpl2_X)
		{
			R_choose_pl1_X->Enabled =true;
			R_choose_pl2_O->Enabled =true;
		}
		checkpl1_O=false;
		//X2O1--;
	 }
	 RR_fight->Enabled=false;
	 RR_fight->Stroke->Thickness=1;
	 G_fight->Enabled =false;
	 T_fight->Opacity=0.5;
	 T_fight->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::R_resetpl2Click(TObject *Sender)
{
	if (checkpl2_X) {
		R_choose_pl2_X->Opacity = 0;
		R_choose_pl2_X->Stroke->Kind = TBrushKind::None;
		T_choose_pl2_X->TextSettings->Font->Size=36;
		if (!checkpl1_O)
		{
			R_choose_pl2_O->Enabled =true;
			R_choose_pl1_X->Enabled =true;
		}
		checkpl2_X=false;
		//X2O1--;
	 }
	 else
	 {
		R_choose_pl2_O->Opacity = 0;
		R_choose_pl2_O->Stroke->Kind = TBrushKind::None;
		T_choose_pl2_O->TextSettings->Font->Size=36;
		if (!checkpl1_X)
		{
			R_choose_pl2_X->Enabled =true;
			R_choose_pl1_O->Enabled =true;
		}
		checkpl2_O=false;
		//X1O2--;
	 }
	 RR_fight->Enabled=false;
	 RR_fight->Stroke->Thickness=1;
	 G_fight->Enabled =false;
	 T_fight->Opacity=0.5;
	 T_fight->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl1Click(TObject *Sender)
{
	RR_pl2->Enabled =false;
	RR_random->Enabled =false;
	I_steppl2->Enabled =false;
	I_steprandom->Enabled =false;
	ActiveButtonAC(checkpl1_X, checkpl2_X, checkpl1_O, checkpl2_O,checksteppl1,checksteppl2,checksteprandom);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_pl2Click(TObject *Sender)
{
	RR_pl1->Enabled =false;
	RR_random->Enabled =false;
	I_steppl1->Enabled =false;
	I_steprandom->Enabled =false;
	ActiveButtonAC(checkpl1_X, checkpl2_X, checkpl1_O, checkpl2_O,checksteppl1,checksteppl2,checksteprandom);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_randomClick(TObject *Sender)
{
	RR_pl1->Enabled =false;
	RR_pl2->Enabled =false;
	I_steppl1->Enabled =false;
	I_steppl2->Enabled =false;
	ActiveButtonAC(checkpl1_X, checkpl2_X, checkpl1_O, checkpl2_O,checksteppl1,checksteppl2,checksteprandom);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_resetMouseEnter(TObject *Sender)
{
	G_reset->Softness =2;
	checkleavers=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_resetMouseLeave(TObject *Sender)
{
	if (!checksteprs) {
		G_reset->Softness =1;
		RR_text->Visible = false;
		checkleavers=true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::RR_resetMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	I_reset->Opacity =1;
	G_reset->Softness =2;
	checksteprs=false;
	checkleavers=true;
	SetHitTestTrue1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl1, RR_pl1, RR_pl2, RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_resetMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(!checksteprs){G_reset->Softness =2;
	I_reset->Opacity =0.5;
	RR_text->Visible =false;
	checksteprs=true;
	checkleavers=true;
	}
	SetHitTestFalse1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl1, RR_pl1, RR_pl2, RR_backchoose);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_resetMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
	if(!checkleavers){RR_text->Visible=true;
	Text6->Text="RESET";
	RR_text->Position->X=X+180;
	if (X>=25) {
		RR_text->Position->X=X+380;
	}
	RR_text->Position->Y=Y+270;
	if (Y>=25) {
		RR_text->Position->Y=Y+370;
	}}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_resetClick(TObject *Sender)
{
	if (checksteprandom) checksteprandom=false;
	if (checksteppl1) checksteppl1=false;
	if (checksteppl2) checksteppl2=false;
	RR_pl1->Enabled=true;
	RR_pl2->Enabled=true;
	RR_random->Enabled=true;
	I_steppl2->Enabled =true;
	I_steprandom->Enabled =true;
	I_steppl1->Enabled =true;
	RR_fight->Enabled=false;
	RR_fight->Stroke->Thickness=1;
	G_fight->Enabled =false;
	T_fight->Opacity=0.5;
	T_fight->Enabled=false;
	RR_pl1->OnMouseLeave(RR_pl1);
	RR_pl2->OnMouseLeave(RR_pl2);
	RR_random->OnMouseLeave(RR_random);
	ResetButton();
}
//---------------------------------------------------------------------------
void __fastcall TForm_Game::ActiveButtonAC(bool checkpl1_X, bool checkpl2_X, bool checkpl1_O, bool checkpl2_O,bool checksteppl1,bool checksteppl2, bool checksteprandom){
	if (checkpl1_X && checkpl2_O && (checksteppl1||checksteppl2||checksteprandom)) {
		RR_fight->Enabled=true;
		RR_fight->Stroke->Thickness=0;
		G_fight->Enabled =true;
		T_fight->Opacity=1;
		T_fight->Enabled=true;
		}
		else if (checkpl1_O && checkpl2_X &&(checksteppl1||checksteppl2||checksteprandom)) {
		RR_fight->Enabled=true;
		RR_fight->Stroke->Thickness=0;
		G_fight->Enabled =true;
		T_fight->Opacity=1;
		T_fight->Enabled=true;
		}
}



void __fastcall TForm_Game::Timer2Timer(TObject *Sender)
{
	Text7->Visible =true;
	Text7->Text = (Text7->Text- '0'- 1) + '0';
	if (Text7->Text==0) {
		   Text7->Text="FIGHTING!";
		   Text7->TextSettings->Font->Size=80;
		   Timer2->Enabled =false;
		   Timer3->Enabled =true;
		   Image4->Visible =false;
		   FloatAnimation1->Stop();
		   FloatAnimation2->Stop();
           FloatAnimation3->Stop();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Timer3Timer(TObject *Sender)
{
	//Image5->Visible =false;
	Text7->Visible=false;
	Timer3->Enabled =false;
	Z->Visible =false;
	R_play->Visible =true;
	Image5->Visible=true;
	if(checkmode) {
		Image6->Visible=true;
		Image10->Visible=false;
	}
	else {
		Image10->Visible=true;
        Image6->Visible=false;
	}
	Image7->Visible=true;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall TForm_Game::RR_fightClick(TObject *Sender)
{
	MediaPlayer3->Stop();
    MediaPlayer3->CurrentTime=0;
	R_board->Visible =true;
	MediaPlayer1->Play();
	R_choose->Visible=false;
	Timer2->Enabled =true;
	FloatAnimation1->Enabled =true;
	FloatAnimation2->Enabled =true;
	FloatAnimation3->Enabled =true;
	FloatAnimation3->Start();
	FloatAnimation1->Start();
	FloatAnimation2->Start();
	MediaPlayer3->Stop();
	if (checksteppl2) {
		 if(!checkmode){game->GetRobot()->MakeMove(bd);
		 game->NextStep(checkmode);}
	}
	else if (checksteprandom) {
           	std::srand(std::time(0));
			int n = std::rand() % 2 + 1; // Random ra 1 hoặc 2
			if(checkmode) game->SetRandom(n,Image5,Image6,checkmode,bd);
			else game->SetRandom(n,Image5,Image10,checkmode,bd);
		 }
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::R_chooseMouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, float X, float Y)
{
	if (checkpl1_X){
		R_choose_pl1_X->OnMouseUp(R_choose_pl1_X, Button, Shift, X, Y);
		R_choose_pl1_X->OnClick(R_choose_pl1_X);
	}
	if (checkpl1_O) {
		R_choose_pl1_O->OnMouseUp(R_choose_pl1_O, Button, Shift, X, Y);
		R_choose_pl1_O->OnClick(R_choose_pl1_O);
	}
	if (checkpl2_X) {
		R_choose_pl2_X->OnMouseUp(R_choose_pl2_X, Button, Shift, X, Y);
		R_choose_pl2_X->OnClick(R_choose_pl2_X);
	}
	if (checkpl2_O) {
		R_choose_pl2_O->OnMouseUp(R_choose_pl2_O, Button, Shift, X, Y);
        R_choose_pl2_O->OnClick(R_choose_pl2_O);
	}
	if (checksteppl1) {
		RR_pl1->OnMouseUp(RR_pl1, Button, Shift, X, Y);
		RR_pl1->OnClick(RR_pl1);
	}
	if (checksteppl2) {
		RR_pl2->OnClick(RR_pl2);
		RR_pl2->OnMouseUp(RR_pl2, Button, Shift, X, Y);
	}
	if (checksteprandom) {
		RR_random->OnMouseUp(RR_random, Button, Shift, X, Y);
		RR_random->OnClick(RR_random);
	}
	if (checkrspl1){
		R_resetpl1->Stroke->Thickness=0;
		I_resetpl1->Opacity=1;
		checkrspl1=false;
		SetHitTestTrue(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl2, RR_pl1,
					RR_pl2, RR_reset, RR_random, RR_backchoose);
	}
	if (checkrspl2) {
		R_resetpl2->Stroke->Thickness=0;
		I_resetpl2->Opacity=1;
		checkrspl2=false;
		SetHitTestTrue(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_resetpl1, R_choose_pl1_X, RR_pl1,
					RR_pl2, RR_reset, RR_random, RR_backchoose);
	}
	if (checksteprs) {

		RR_reset->OnMouseUp(RR_reset, Button, Shift, X, Y);
		RR_reset->OnMouseLeave(RR_reset);
	}
	if (checkbackchoose) {
			checkbackchoose=false;
			RR_backchoose->OnMouseLeave(RR_backchoose);
			RR_backchoose->OnMouseUp(RR_backchoose, Button, Shift, X, Y);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::SetHitTestFalse(TRectangle* r_choose_pl1_o, TRectangle* r_choose_pl2_o, TRectangle* r_choose_pl2_x,
					 TRectangle* r_reset_pl1, TRectangle* r_reset_pl2, TRoundRect* rr_pl1,
					 TRoundRect* rr_pl2, TRoundRect* rr_reset, TRoundRect* rr_random,TRoundRect* RR4) {
	r_choose_pl1_o->HitTest = false;
	r_choose_pl2_o->HitTest = false;
	r_choose_pl2_x->HitTest = false;
	r_reset_pl1->HitTest = false;
	r_reset_pl2->HitTest = false;
	rr_pl1->HitTest = false;
	rr_pl2->HitTest = false;
	rr_reset->HitTest = false;
	rr_random->HitTest = false;
	RR4->HitTest =false;
}
void __fastcall TForm_Game::SetHitTestTrue(TRectangle* r_choose_pl1_o, TRectangle* r_choose_pl2_o, TRectangle* r_choose_pl2_x,
					 TRectangle* r_reset_pl1, TRectangle* r_reset_pl2, TRoundRect* rr_pl1,
					 TRoundRect* rr_pl2, TRoundRect* rr_reset, TRoundRect* rr_random,TRoundRect* RR4) {
 	r_choose_pl1_o->HitTest = true;
    r_choose_pl2_o->HitTest = true;
    r_choose_pl2_x->HitTest = true;
    r_reset_pl1->HitTest = true;
    r_reset_pl2->HitTest = true;
    rr_pl1->HitTest = true;
    rr_pl2->HitTest = true;
    rr_reset->HitTest = true;
	rr_random->HitTest = true;
	RR4->HitTest=true;

}
void __fastcall TForm_Game::SetHitTestFalse1(TRectangle* R1, TRectangle* R2, TRectangle* R3,
					 TRectangle* R4, TRectangle* R5, TRectangle* R6,
					 TRoundRect* RR1, TRoundRect* RR2, TRoundRect* RR3,TRoundRect* RR4)
{
	R1->HitTest = false;
	R2->HitTest = false;
	R3->HitTest = false;
	R4->HitTest = false;
	R5->HitTest = false;
	R6->HitTest = false;
	RR1->HitTest = false;
	RR2->HitTest = false;
	RR3->HitTest = false;
	RR4->HitTest = false;
}
void __fastcall TForm_Game::SetHitTestTrue1(TRectangle* R1, TRectangle* R2, TRectangle* R3,
					 TRectangle* R4, TRectangle* R5, TRectangle* R6,
					 TRoundRect* RR1, TRoundRect* RR2, TRoundRect* RR3,TRoundRect* RR4)
{
	R1->HitTest = true;
	R2->HitTest = true;
	R3->HitTest = true;
	R4->HitTest = true;
	R5->HitTest = true;
	R6->HitTest = true;
	RR1->HitTest = true;
	RR2->HitTest = true;
	RR3->HitTest = true;
	RR4->HitTest = true;
}


void __fastcall TForm_Game::b0_0Click(TObject *Sender)
{
	HandleCellClick(b0_0,0,0);
}

void __fastcall TForm_Game::b0_1Click(TObject *Sender)
{
	HandleCellClick(b0_1,0,1);
}

void __fastcall TForm_Game::b0_2Click(TObject *Sender)
{
	HandleCellClick(b0_2,0,2);
}

void __fastcall TForm_Game::b1_0Click(TObject *Sender)
{
	HandleCellClick(b1_0,1,0);
}

void __fastcall TForm_Game::b1_1Click(TObject *Sender)
{
	HandleCellClick(b1_1,1,1);
}

void __fastcall TForm_Game::b1_2Click(TObject *Sender)
{
	HandleCellClick(b1_2,1,2);
}

void __fastcall TForm_Game::b2_0Click(TObject *Sender)
{
	HandleCellClick(b2_0,2,0);
}

void __fastcall TForm_Game::b2_1Click(TObject *Sender)
{
	HandleCellClick(b2_1,2,1);
}

void __fastcall TForm_Game::b2_2Click(TObject *Sender)
{
	HandleCellClick(b2_2,2,2);
}

//---------------------------------------------------------------------------
void __fastcall TForm_Game::HandleCellClick(TButton* button, int n, int m)
{
	bool check = false;
	// Kiểm tra nội dung của nút
	if (button->Text == "") {
		// Kiểm tra lượt của Player1
		if (game->GetPlayer1()->getStep()) {
			button->Text = game->GetPlayer1()->GetChar();
			button->TextSettings->FontColor = claRed;
			bd->Set(n, m, game->GetPlayer1()->GetChar());
			if (game->GetPlayer1()->GetChar() == 'X') {
				if (bd->checkXwin()) {
					Text10->Text = "PLAYER 1 WON";
					//Timer4->Enabled = true;
					R_play->Enabled = false;
					check = true;
					Image5->Enabled = false;
					Image6->Enabled = false;
					Image5->Opacity = 1;
					Image6->Opacity = 1;
					Image10->Enabled=false;
					Image10->Opacity=1;
					RR_backplay->Visible=true;
					Image11->Visible=true;
					Timer4->Enabled=true;
				}
				else {
					game->NextStep(checkmode);
					if (checkmode) {
						Image5->Opacity=0.3;
						Image6->Opacity=1;
						Image10->Opacity=1;
					}
				}
            } else if (game->GetPlayer1()->GetChar() == 'O') {
                if (bd->checkOwin()) {
					Text10->Text = "PLAYER 1 WON";
					//Timer4->Enabled = true;
					R_play->Enabled = false;
					check = true;
					Image5->Enabled = false;
					Image6->Enabled = false;
					Image5->Opacity = 1;
					Image6->Opacity = 1;
					Image10->Enabled=false;
					Image10->Opacity=1;
					RR_backplay->Visible=true;
					Image11->Visible=true;
					Timer4->Enabled=true;
				}
				else {
					game->NextStep(checkmode);
					if (checkmode) {
						Image5->Opacity=0.3;
						Image6->Opacity=1;
						Image10->Opacity=1;
					}
				}
			}
			if (!checkmode && !check) { // Nếu chế độ chơi với máy và chưa có người thắng
				game->GetRobot()->MakeMove(bd);
				game->NextStep(checkmode);
				if (game->GetRobot()->GetChar() == 'X') {
					if (bd->checkXwin()) {
						Text10->Text = "ROBOT WON";
						R_play->Enabled = false;
						check = true;
						Image5->Enabled = false;
						Image5->Opacity = 1;
						Image10->Enabled=false;
						Image10->Opacity = 1;
						RR_backplay->Visible=true;
						Image11->Visible=true;
					}

                } else if (game->GetRobot()->GetChar() == 'O') {
                    if (bd->checkOwin()) {
						Text10->Text = "ROBOT WON";
						R_play->Enabled = false;
						check = true;
						Image5->Enabled = false;
						Image5->Opacity = 1;
						Image10->Enabled=false;
						Image10->Opacity = 1;
						RR_backplay->Visible=true;
						Image11->Visible=true;
                    }
                }
            }
		}
		else if (checkmode && game->GetPlayer2()->getStep()) { // Kiểm tra lượt của Player2
			button->Text = game->GetPlayer2()->GetChar();
			button->TextSettings->FontColor = claBlue; // Đặt màu chữ xanh cho O
            bd->Set(n, m, game->GetPlayer2()->GetChar());
            if (game->GetPlayer2()->GetChar() == 'X') {
                if (bd->checkXwin()) {
					Text10->Text = "PLAYER 2 WON";
                    R_play->Enabled = false;
                    check = true;
					Image5->Enabled = false;
                    Image6->Enabled = false;
                    Image5->Opacity = 1;
					Image6->Opacity = 1;
					Image10->Enabled=false;
					Image10->Opacity=1;
					RR_backplay->Visible=true;
					Image11->Visible=true;
					Timer4->Enabled=true;
				}
				else {
					game->NextStep(checkmode);
					if (checkmode) {
						Image5->Opacity=1;
						Image6->Opacity=0.2;
						Image10->Opacity=1;
					}
				}
			} else if (game->GetPlayer2()->GetChar() == 'O') {
				if (bd->checkOwin()) {
					Text10->Text = "PLAYER 2 WON";
					//Timer4->Enabled = true;
					R_play->Enabled = false;
					check = true;
                    Image5->Enabled = false;
                    Image6->Enabled = false;
                    Image5->Opacity = 1;
					Image6->Opacity = 1;
					Image10->Enabled=false;
					Image10->Opacity=1;
					RR_backplay->Visible=true;
					Image11->Visible=true;
					Timer4->Enabled=true;
				}
                else {
					game->NextStep(checkmode);
					if (checkmode) {
						Image5->Opacity=1;
						Image6->Opacity=0.2;
						Image10->Opacity=1;
					}
				}
			}
		}
        if (bd->checkDraw() && !check) {
			Text10->Text = "DRAW";
			//Timer4->Enabled = true;
            R_play->Enabled = false;
			Image5->Enabled = false;
			Image5->Opacity = 1;
			if(checkmode) {
				Image6->Opacity = 1;
				Image6->Enabled = false;
			}
			else{
				Image10->Opacity = 1;
				Image10->Enabled = false;
			}
			RR_backplay->Visible=true;
			Image11->Visible=true;
			if (checkmode) {
				Timer4->Enabled=true;
			}
		}
	}
}

void __fastcall TForm_Game::EndGame() {
    MediaPlayer2->Play();
	R_play->Enabled = false;
	Image5->Enabled = false;
	Image5->Opacity = 1;
	Image6->Enabled = false;
	Image6->Opacity = 1;
	Image10->Enabled = false;
	Image10->Opacity = 1;
}
void __fastcall TForm_Game::UpdateUIAfterMove() {
	if (checkmode) {
		Image5->Opacity = 0.3;
    } else {
        Image10->Opacity = 1;
    }
    Image6->Opacity = 1;
}

void __fastcall TForm_Game::RR_backchooseClick(TObject *Sender)
{
	I_backgr->Visible=true;
	Line3->Position->X=0;
	Line3->Position->Y=0;
	R_login->Visible=false;
	R_mode->Visible=true;
	I_backgr->Position->X=0;
	I_backgr->Position->Y=0;
	R_choose->Visible=false;
	Rectangle3->Position->X=263;
	RR_easy->Position->X=271;
	RR_normal->Position->X=271;
	RR_hard->Position->X=271;
	RR_easy->Visible=false;
	RR_hard->Visible=false;
	RR_normal->Visible=false;
	R_resetpl1->OnClick(R_resetpl1);
	R_resetpl2->OnClick(R_resetpl2);
	RR_reset->OnClick(RR_reset);
    clickr3=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_backchooseMouseEnter(TObject *Sender)
{
    G_backchoose->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_backchooseMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	if(!checkbackchoose) {
		Image9->Opacity=0.6;
		checkbackchoose=true;
	}
    SetHitTestFalse1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl1, RR_pl1, RR_pl2, RR_reset);

}
//---------------------------------------------------------------------------
void __fastcall TForm_Game::ResetButton() {
	b0_0->Text = "";
    b0_1->Text = "";
    b0_2->Text = "";
    b1_0->Text = "";
    b1_1->Text = "";
    b1_2->Text = "";
    b2_0->Text = "";
    b2_1->Text = "";
	b2_2->Text = "";
	bd->Reset();
}

//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_backchooseMouseLeave(TObject *Sender)
{
	if(!checkbackchoose){
		Image9->Opacity=1;
		G_backchoose->Enabled=false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Rectangle3Click(TObject *Sender)
{
	if(!clickr3){
		RR_easy->Visible=true;
		RR_normal->Visible=true;
		RR_hard->Visible=true;
		FloatAnimation4->Enabled=true;
		FloatAnimation5->Enabled=true;
		FloatAnimation6->Enabled=true;
		FloatAnimation7->Enabled=true;
		FloatAnimation4->Start();
		FloatAnimation5->Start();
		FloatAnimation6->Start();
		FloatAnimation7->Start();
		checkmode=false;
		image2->Visible=false;
		Image8->Visible=true;
		TAlphaColor alphaColor = StringToAlphaColor("#FF4581B4");
		G_choose_pl2->GlowColor = alphaColor;
		R_player2->Stroke->Color= alphaColor;
		G_choose_pl2->Opacity=1;
		Text3->Text="BOT";
		clickr3=true;
	}
	else{
		FloatAnimation8->Enabled=true;
		FloatAnimation9->Enabled=true;
		FloatAnimation10->Enabled=true;
		FloatAnimation11->Enabled=true;
		FloatAnimation8->Start();
		FloatAnimation9->Start();
		FloatAnimation10->Start();
		FloatAnimation11->Start();
		clickr3=false;
        Rectangle3->OnMouseLeave(Rectangle3);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_backchooseMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
	Image9->Opacity=1;
	SetHitTestTrue1(R_choose_pl1_O, R_choose_pl2_O, R_choose_pl2_X,
					R_choose_pl1_X, R_resetpl1, R_resetpl2,
					RR_pl1, RR_pl1, RR_pl2, RR_reset);
    checkbackchoose=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::RR_backplayClick(TObject *Sender)
{
	Image5->Opacity=1;
	Image5->Enabled=true;
	Image6->Opacity=1;
	Image6->Enabled=true;
	Image10->Opacity=1;
	Image10->Enabled=true;
	R_play->Enabled=true;
	R_play->Visible=false;
	Image7->Visible=false;
	Image5->Visible=false;
	Image6->Visible=false;
	Image10->Visible=false;
	RR_reset->OnClick(RR_reset);
	R_resetpl1->OnClick(R_resetpl1);
	R_resetpl2->OnClick(R_resetpl2);
	ResetButton();
	Text10->Text="";
	R_board->Visible=false;
	R_choose->Visible=true;
	RR_backplay->Visible=false;
	Image11->Visible=false;
	Image4->Visible=true;
	Text7->Visible=true;
	Z->Visible=true;
	Text7->Text="3";
	MediaPlayer1->CurrentTime = 0;
	MediaPlayer2->Stop();
	MediaPlayer2->CurrentTime=0;
	Timer4->Enabled=false;
	MediaPlayer3->Play();
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::RR_backplayMouseLeave(TObject *Sender)
{
    Image11->Opacity=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_backplayMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y)
{
    Image11->Opacity=0.6;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::Timer4Timer(TObject *Sender)
{
	MediaPlayer2->Play();
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::RR_easyClick(TObject *Sender)
{
	I_backgr->Align = TAlignLayout::None;
	I_backgr->Position->X+=20;
	Line3->Visible = true;
	Line3->Align = TAlignLayout::None;
	Line3->Position->X+=20;
	i_bgame->Visible =true;
	Timer1->Enabled = true;
	game->GetRobot()->Set_mode(0);
}
//---------------------------------------------------------------------------



void __fastcall TForm_Game::RR_hardClick(TObject *Sender)
{
	I_backgr->Align = TAlignLayout::None;
	I_backgr->Position->X+=20;
	Line3->Visible = true;
	Line3->Align = TAlignLayout::None;
	Line3->Position->X+=20;
	i_bgame->Visible =true;
	Timer1->Enabled = true;
	game->GetRobot()->Set_mode(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::RR_normalClick(TObject *Sender)
{
	I_backgr->Align = TAlignLayout::None;
	I_backgr->Position->X+=20;
	Line3->Visible = true;
	Line3->Align = TAlignLayout::None;
	Line3->Position->X+=20;
	i_bgame->Visible =true;
	Timer1->Enabled = true;
	game->GetRobot()->Set_mode(1);
}
//---------------------------------------------------------------------------


void __fastcall TForm_Game::FloatAnimation9Finish(TObject *Sender)
{
    RR_easy->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::FloatAnimation10Finish(TObject *Sender)
{
    RR_hard->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm_Game::FloatAnimation11Finish(TObject *Sender)
{
    RR_normal->Visible=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm_Game::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if (R_login->Visible) {
		if (Key == VK_RETURN) {
			RoundRect1Click(Sender);
		}
		if (Key == VK_ESCAPE) {
			if (!(e_user->IsFocused || e_pass->IsFocused)) {
				this->Close();
			}
		}
	}
	if (R_mode->Visible) {
		if (VK_ESCAPE == Key) {
			R_mode->Visible=false;
			R_login->Visible=true;
            e_pass->Text="";
		}
	}
}
//---------------------------------------------------------------------------




void __fastcall TForm_Game::R_loginClick(TObject *Sender)
{
	e_user->ResetFocus();
    e_pass->ResetFocus();
}
//---------------------------------------------------------------------------



