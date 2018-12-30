//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Class.h"
#include "Find.h"
#include "FindTable.h"
#include "AddTrack.h"
#include "Resource.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm17 *Form17;
audioFile file;
list List;
list List2;
ifstream f;
ofstream f2;
int findTask;
//---------------------------------------------------------------------------
__fastcall TForm17::TForm17(TComponent* Owner)
	: TForm(Owner)
{
	MusicList->Cells[0][0] = "Name";
	MusicList->Cells[1][0] = "Resource";
	MusicList->Cells[2][0] = "Format";
	MusicList->Cells[3][0] = "Duration";
	MusicList->Cells[4][0] = "Codec";
	MusicList->Cells[5][0] = "Clock";
	MusicList->Cells[6][0] = "Bitrate";
	MusicList->Cells[7][0] = "Karaoke";
	MusicList->Cells[8][0] = "PlayerName";
}
//---------------------------------------------------------------------------
void __fastcall TForm17::Button1Click(TObject *Sender)
{
	Form3->Show();  //Показ форми для додавання треку
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    //Пошук за заданим параметром відповідно до значення findTask=1?Bit:codec
	Form2->Show();
	if(findTask){List.findByBitrate(Edit1->Text.ToInt(), Form2->StringGrid1);}
	else{List.findByCodek(Edit1->Text, Form2->StringGrid1);}
	Form1->Hide();
}
void __fastcall TForm17::MusicListSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
    //При натисканні на певну комірку сортує за відповідним параметром
	if(ACol == 0 && ARow == 0)
	{
		if(!(List.isSortName())){
		sort(List.List.begin(), List.List.end(), &List.sortName);
		List.show(MusicList);
		}
		else{
			List.showReverse(MusicList);
		}
	}
	if(ACol == 1 && ARow == 0)
	{
		if(!(List.isSortRes())){
		sort(List.List.begin(), List.List.end(), &List.sortRes);
		List.show(MusicList);
		}
		else{
			List.showReverse(MusicList);
		}
	}
	if(ACol == 2 && ARow == 0)
	{
		if(!(List.isSortFormat())){
		sort(List.List.begin(), List.List.end(), &List.sortFormat);
		List.show(MusicList);
		}
		else{
			List.showReverse(MusicList);
		}
	}
	if(ACol == 3 && ARow == 0)
	{
		if(List.isSortDur()){
		sort(List.List.begin(), List.List.end(), &List.sortDur);
		List.show(MusicList);
        }
		else{
			List.showReverse(MusicList);
		}
	}
	if(ACol == 4 && ARow == 0)
	{
		if(!(List.isSortCodek())){
		sort(List.List.begin(), List.List.end(), &List.sortCodek);
		List.show(MusicList);
        }
		else{
			List.showReverse(MusicList);
		}
	}
	if(ACol == 5 && ARow == 0)
	{
        if(!(List.isSortClock())){
		sort(List.List.begin(), List.List.end(), &List.sortClock);
		List.show(MusicList);
		}
		else{
			List.showReverse(MusicList);
		}
	}
	if(ACol == 6 && ARow == 0)
	{
		if(!(List.isSortBitrate())){
		sort(List.List.begin(), List.List.end(), &List.sortBitrate);
		List.show(MusicList);
        }
		else{
			List.showReverse(MusicList);
		}
	}
	if(ACol == 7 && ARow == 0)
	{
		if(!(List.isSortText())){
		sort(List.List.begin(), List.List.end(), &List.sortText);
		List.show(MusicList);
        }
		else{
			List.showReverse(MusicList);
		}
	}
	if(ACol == 8 && ARow == 0)
	{
		if(List.isSortPlayer()){
		sort(List.List.begin(), List.List.end(), &List.sortPlayer);
		List.show(MusicList);
        }
		else{
			List.showReverse(MusicList);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm17::Codec1Click(TObject *Sender)
{
	//Відкриває форму для введення значення поля пошуку і встановлює відповідне значення
	// findTask
	Form1->Show();
	Form1->Edit1->Clear();
	findTask = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm17::Bitrate1Click(TObject *Sender)
{
    //Відкриває форму для введення значення поля пошуку і встановлює відповідне значення
	// findTask
	Form1->Show();
	Form1->Edit1->Clear();
	findTask = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm17::Open1Click(TObject *Sender)
{
	//Відкриття файлу - якщо назва/розміщення файлу некорректні - вивід помилки
	if(OpenDialog1->Execute()){
		List.List.clear();
		AnsiString ansiB(OpenDialog1->FileName);
		char* str = new char[ansiB.Length()+1];
		strcpy(str, ansiB.c_str());
		try{
			f.open(str);
			if(!f.is_open())
			throw 214;
		}
		catch(int i){
			ShowMessage("ERROR" + String(i) + ". No such file or directory");
			f.close();
            return;
		}
		f.clear();
		f.seekg(0, ios::beg);
		List<<(f);
        f.clear();
		f.seekg(0, ios::beg);
        List2<<(f);
		List.show(MusicList);
		f.close();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm17::Save1Click(TObject *Sender)
{
    //Збереження файлу - якщо назва/розміщення файлу некорректні - вивід помилки
	if(SaveDialog1->Execute()){
		try{
			if(List.List.empty())
			throw 213;
		}
		catch(int i){
			ShowMessage("ERROR" + String(i) + ". Nothing to save");
            return;
		}
		AnsiString ansiB(SaveDialog1->FileName);
		char* str = new char[ansiB.Length()+1];
		strcpy(str, ansiB.c_str());
		f2.open(str);
		delete[] str;
		List>>(f2);
        f2.close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	//Додавання нового треку в кінець списку з клавіатури
	    int temp;
		try{
			try{
				if(NameEdit->Text == "" || ResEdit->Text == "" || FormatEdit->Text == ""
				|| DurEdit->Text == "" || CodecEdit->Text == "" || ClockEdit->Text == ""
				|| BitrateEdit->Text == "" || TextEdit->Text == "" || PlayerEdit->Text == "")
				throw 211;
			}
			catch(int i){
			ShowMessage("ERROR" + String(i) + ". Some of fields are empty");
			return;
			}
			if(!(TryStrToInt(DurEdit->Text, temp) && TryStrToInt(ClockEdit->Text, temp)
			&& TryStrToInt(BitrateEdit->Text, temp) && TryStrToInt(TextEdit->Text, temp)))
			throw 212;
			else if(ClockEdit->Text[1] == '-' || BitrateEdit->Text[1] == '-' ||
					TextEdit->Text[1] == '-' || DurEdit->Text[1] == '-' ||
					TextEdit->Text.ToInt() > 1)
                    throw 212;
		}
		catch(int i){
			ShowMessage("ERROR" + String(i) + ". Wrong info");
			return;
	  	}
	audioFile tmp(NameEdit->Text, ResEdit->Text, FormatEdit->Text,
				DurEdit->Text.ToInt(), CodecEdit->Text, ClockEdit->Text.ToInt(),
				BitrateEdit->Text.ToInt(), TextEdit->Text.ToInt(), PlayerEdit->Text);
	List.List.push_back(tmp);
    List2.List.push_back(tmp);
	List.show(Form17->MusicList);
	NameEdit->Text =    "";
	ResEdit->Text =     "";
	FormatEdit->Text =  "";
	DurEdit->Text =     "";
	CodecEdit->Text =   "";
	ClockEdit->Text =   "";
	TextEdit->Text =    "";
	PlayerEdit->Text =  "";
	BitrateEdit->Text = "";
	Form3->Hide();
}
void __fastcall TForm17::ask1Click(TObject *Sender)
{
	Form4->Show();
	List2.findRes(Form4->StringGrid1);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::StringGrid1SelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect)
{
	if(ACol == 0 && ARow == 0){}
	else{
		List2.sameResource(StringGrid1->Cells[ACol][ARow]);
		Form4->Hide();
		sort(List2.List.begin(), List2.List.end(), &List2.sortClock);
		Form2->Show();
		List2.show(Form2->StringGrid1);
    }
}
//---------------------------------------------------------------------------


