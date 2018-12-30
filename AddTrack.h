//---------------------------------------------------------------------------

#ifndef AddTrackH
#define AddTrackH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TEdit *NameEdit;
	TEdit *ResEdit;
	TEdit *FormatEdit;
	TEdit *DurEdit;
	TEdit *CodecEdit;
	TEdit *ClockEdit;
	TEdit *TextEdit;
	TEdit *PlayerEdit;
	TEdit *BitrateEdit;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
