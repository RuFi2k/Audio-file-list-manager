//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Resource.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
    StringGrid1->RowCount = 2;
	StringGrid1->Cells[0][0] = "Select one:";
}
//---------------------------------------------------------------------------

