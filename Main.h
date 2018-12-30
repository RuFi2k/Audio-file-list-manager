//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm17 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *MusicList;
	TButton *Button1;
	TMainMenu *MainMenu1;
	TMenuItem *Find1;
	TMenuItem *Codec1;
	TMenuItem *Bitrate1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMenuItem *File1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *ResourceTask1;
	TMenuItem *ask1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall MusicListSelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall Codec1Click(TObject *Sender);
	void __fastcall Bitrate1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall ask1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm17(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm17 *Form17;
//---------------------------------------------------------------------------
#endif
