//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FindTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid1->Cells[0][0] = "Name";
	StringGrid1->Cells[1][0] = "Resource";
	StringGrid1->Cells[2][0] = "Format";
	StringGrid1->Cells[3][0] = "Duration";
	StringGrid1->Cells[4][0] = "Codec";
	StringGrid1->Cells[5][0] = "Clock";
	StringGrid1->Cells[6][0] = "Bitrate";
	StringGrid1->Cells[7][0] = "Karaoke";
	StringGrid1->Cells[8][0] = "PlayerName";
}
//---------------------------------------------------------------------------
