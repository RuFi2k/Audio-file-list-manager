//---------------------------------------------------------------------------

#pragma hdrstop

#include "Class.h"
#include "FindTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
audioFile::audioFile(){
	this->internetResource = "http//www.defaultmusic.com";
	this->format = "MP3";
	this->duration = 300;
	this->Codek = "AVC";
	this->discretizationClock = 48000;
	this->Bitrate = 320;
	this->text = 0;
	this->playerName = "VLCplayer";
}


audioFile::audioFile(String name, String res, String form, int dur, String codek, long clock,
	int bitrate, int Text, String player){
    this->Name = name;
	this->internetResource = res;
	this->format = form;
	this->duration = dur;
	this->Codek = codek;
	this->discretizationClock = clock;
	this->Bitrate = bitrate;
	this->text = Text;
	this->playerName = player;
}


audioFile::audioFile(const audioFile &File){
    this->Name = File.GetName();
	this->internetResource = File.GetInternetResource();
	this->format = File.GetFormat();
	this->duration = File.GetDuration();
	this->Codek = File.GetCodek();
	this->discretizationClock = File.GetDiscretizationClock();
	this->Bitrate = File.GetBitrate();
	this->text = File.GetText();
	this->playerName = File.GetPlayerName();
}

list::list(const list &L){
	for(int i = 0; i < L.List.size(); ++i){
        this->List.push_back(L.List[i]);
	}
}

void list::addTrack(String name, String res, String form, int dur, String codek, long clock, int bitrate,
	int Text, String player){
	audioFile tmp(name, res, form, dur, codek, clock, bitrate, Text, player);
	List.push_back(tmp);
}

audioFile::~audioFile(){

}

list::~list(){}

void list::show(TStringGrid* Grid){
	Grid->RowCount = this->List.size() + 1;
	for(int i = 0; i < List.size(); ++i){
		Grid->Cells[0][i+1] = this->List[i].GetName();
		Grid->Cells[1][i+1] = this->List[i].GetInternetResource();
		Grid->Cells[2][i+1] = this->List[i].GetFormat();
		Grid->Cells[3][i+1] = String(this->List[i].GetDuration());
		Grid->Cells[4][i+1] = this->List[i].GetCodek();
		Grid->Cells[5][i+1] = String(this->List[i].GetDiscretizationClock());
		Grid->Cells[6][i+1] = String(this->List[i].GetBitrate());
		Grid->Cells[7][i+1] = String(this->List[i].GetText());
		Grid->Cells[8][i+1] = this->List[i].GetPlayerName();
	}
}

void list::showReverse(TStringGrid* Grid){
	list tmp(*this);
	this->List.clear();
	for(int i = tmp.List.size()-1; i >= 0; --i){
		List.push_back(tmp.List[i]);
	}
	for(int i = List.size()-1; i >= 0; --i){
		Grid->Cells[0][i+1] = this->List[i].GetName();
		Grid->Cells[1][i+1] = this->List[i].GetInternetResource();
		Grid->Cells[2][i+1] = this->List[i].GetFormat();
		Grid->Cells[3][i+1] = String(this->List[i].GetDuration());
		Grid->Cells[4][i+1] = this->List[i].GetCodek();
		Grid->Cells[5][i+1] = String(this->List[i].GetDiscretizationClock());
		Grid->Cells[6][i+1] = String(this->List[i].GetBitrate());
		Grid->Cells[7][i+1] = String(this->List[i].GetText());
		Grid->Cells[8][i+1] = this->List[i].GetPlayerName();
	}
}

void list::findByCodek(String taskCodek, TStringGrid* Grid){
	int k = 1;
	for(int i = 0; i < Grid->ColCount; ++i){
		for(int j = 1; j < Grid->RowCount; ++j){
			Grid->Cells[i][j] = "";
		}
	}
	for(int i = 0; i < List.size(); ++i){
		if(this->List[i].GetCodek() == taskCodek){
			Grid->RowCount = k+1;
			Grid->Cells[0][k] = this->List[i].GetName();
			Grid->Cells[1][k] = this->List[i].GetInternetResource();
			Grid->Cells[2][k] = this->List[i].GetFormat();
			Grid->Cells[3][k] = String(this->List[i].GetDuration());
			Grid->Cells[4][k] = this->List[i].GetCodek();
			Grid->Cells[5][k] = String(this->List[i].GetDiscretizationClock());
			Grid->Cells[6][k] = String(this->List[i].GetBitrate());
			Grid->Cells[7][k] = String(this->List[i].GetText());
			Grid->Cells[8][k] = this->List[i].GetPlayerName();
			++k;
		}
	}
		if(k == 1){
		ShowMessage("There are no elements with this parametr.");
		Form2->Hide();
	}
}

void list::findByBitrate(int taskBitrate, TStringGrid* Grid){
    int k = 1;
	for(int i = 0; i < Grid->ColCount; ++i){
		for(int j = 1; j < Grid->RowCount; ++j){
			Grid->Cells[i][j] = "";
		}
	}
	for(int i = 0; i < List.size(); ++i){
		if(this->List[i].GetBitrate() == taskBitrate){
			Grid->RowCount = k+1;
			Grid->Cells[0][k] = this->List[i].GetName();
			Grid->Cells[1][k] = this->List[i].GetInternetResource();
			Grid->Cells[2][k] = this->List[i].GetFormat();
			Grid->Cells[3][k] = String(this->List[i].GetDuration());
			Grid->Cells[4][k] = this->List[i].GetCodek();
			Grid->Cells[5][k] = String(this->List[i].GetDiscretizationClock());
			Grid->Cells[6][k] = String(this->List[i].GetBitrate());
			Grid->Cells[7][k] = String(this->List[i].GetText());
			Grid->Cells[8][k] = this->List[i].GetPlayerName();
			++k;
		}
	}
	if(k == 1){
		ShowMessage("There are no elements with this parametr.");
		Form2->Hide();
	}
}

void list::operator <<(ifstream &f){
	int temp;
	String tempName =    "";
    String tempRes =     "";
	String tempFormat =  "";
	String tempDur =     "";
	String tempCodek =   "";
	String tempClock =   "";
	String tempBitrate = "";
	String tempText =    "";
	String tempPlayer =  "";
	char buff;
	int i = 0;
	while(!(f.eof())){
    audioFile tmp;
	while(f >> buff && buff != '|'){
		switch(i%9){
		case 0:
		 tempName +=buff;
		 break;
		case 1:
		 tempRes +=buff;
		 break;
		case 2:
		 tempFormat +=buff;
		 break;
		case 3:
		 tempDur +=buff;
		 break;
		case 4:
		 tempCodek +=buff;
		 break;
		case 5:
		 tempClock +=buff;
		 break;
		case 6:
		 tempBitrate +=buff;
		 break;
		case 7:
		 tempText +=buff;
		 break;
		case 8:
         tempPlayer +=buff;
		 break;
		}
	}
	++i;
	if(i%9 == 0 && i != 0){
		try{
			try{
				if(tempName == "" || tempRes == "" || tempFormat == "" || tempDur == ""
				|| tempCodek == "" || tempClock == "" || tempBitrate == "" || tempText == ""
				|| tempPlayer == "")
				throw 211;
			}
			catch(int i){
			ShowMessage("ERROR" + String(i) + ". Some of fields are empty");
			f.close();
			return;
			}
			if(!(TryStrToInt(tempDur, temp) && TryStrToInt(tempClock, temp)
			&& TryStrToInt(tempBitrate, temp) && TryStrToInt(tempText, temp)))
			throw 212;
		}
		catch(int i){
			ShowMessage("ERROR" + String(i) + ". Wrong info");
			f.close();
			return;
		}
		this->addTrack(tempName, tempRes, tempFormat, tempDur.ToInt(), tempCodek,
		tempClock.ToInt(), tempBitrate.ToInt(), tempText.ToInt(), tempPlayer);
	tempName =    "";
	tempRes =     "";
	tempFormat =  "";
	tempDur =     "";
	tempCodek =   "";
	tempClock =   "";
	tempBitrate = "";
	tempText =    "";
	tempPlayer =  "";
	}
	}
}

void list::operator>>(ofstream &f){
	for(int i = 0; i < List.size(); ++i){
		f << AnsiString(List[i].GetName() + " | ").c_str()
		  << AnsiString(List[i].GetInternetResource() + " | ").c_str()
		  << AnsiString(List[i].GetFormat() + " | ").c_str()
		  << AnsiString(String(List[i].GetDuration()) + " | ").c_str()
		  << AnsiString(List[i].GetCodek() + " | ").c_str()
		  << AnsiString(String(List[i].GetDiscretizationClock()) + " | ").c_str()
		  << AnsiString(String(List[i].GetBitrate()) + " | ").c_str()
		  << AnsiString(String(List[i].GetText()) + " | ").c_str()
		  << AnsiString(List[i].GetPlayerName() + " | ").c_str() << endl;
	}
}


bool list::sortDur(audioFile &t1, audioFile &t2){
	return (t1.GetDuration() < t2.GetDuration());
}

bool list::sortName(audioFile &t1, audioFile &t2){
	return (t1.GetName() < t2.GetName());
}

bool list::sortRes(audioFile &t1, audioFile &t2){
	return (t1.GetInternetResource() < t2.GetInternetResource());
}

bool list::sortFormat(audioFile &t1, audioFile &t2){
	return (t1.GetFormat() < t2.GetFormat());
}

bool list::sortCodek(audioFile &t1, audioFile &t2){
	return (t1.GetCodek() < t2.GetCodek());
}

bool list::sortClock(audioFile &t1, audioFile &t2){
	return (t1.GetDiscretizationClock() < t2.GetDiscretizationClock());
}

bool list::sortBitrate(audioFile &t1, audioFile &t2){
	return (t1.GetBitrate() < t2.GetBitrate());
}

bool list::sortText(audioFile &t1, audioFile &t2){
	return (t1.GetText() < t2.GetText());
}

bool list::sortPlayer(audioFile &t1, audioFile &t2){
	return (t1.GetPlayerName() < t2.GetPlayerName());
}

bool list::isSortName(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetName() != tmp.List[i].GetName()){
			return false;
		}
	}
	return true;
}

bool list::isSortRes(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetInternetResource() != tmp.List[i].GetInternetResource()){
			return false;
		}
	}
	return true;
}

bool list::isSortFormat(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetFormat() != tmp.List[i].GetFormat()){
			return false;
		}
	}
	return true;
}

bool list::isSortDur(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetDuration() != tmp.List[i].GetDuration()){
			return false;
		}
	}
	return true;
}

bool list::isSortCodek(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetCodek() != tmp.List[i].GetCodek()){
			return false;
		}
	}
	return true;
}

bool list::isSortClock(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetDiscretizationClock() != tmp.List[i].GetDiscretizationClock()){
			return false;
		}
	}
	return true;
}

bool list::isSortBitrate(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetBitrate() != tmp.List[i].GetBitrate()){
			return false;
		}
	}
	return true;
}

bool list::isSortText(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetText() != tmp.List[i].GetText()){
			return false;
		}
	}
	return true;
}

bool list::isSortPlayer(){
	list tmp(*this);
	sort(tmp.List.begin(), tmp.List.end(), &this->sortName);
	for(int i = 0; i < List.size(); ++i){
		if(List[i].GetPlayerName() != tmp.List[i].GetPlayerName()){
			return false;
		}
	}
	return true;
}

void list::sameResource(String Res){
	list tmp(*this);
	this->List.clear();
	for(int i = 0; i < tmp.List.size(); ++i){
		if(tmp.List[i].GetInternetResource() == Res){
            List.push_back(tmp.List[i]);
		}
	}
}

void list::findRes(TStringGrid* Grid){
	if(!List.empty()){
	Grid->Cells[0][1] = List[0].GetInternetResource();
	for(int i = 1; i < List.size(); ++i){
    int counter = 0;
		for(int j = 1; j < Grid->RowCount; ++j){
			if(List[i].GetInternetResource() != Grid->Cells[0][j])
				counter++;
		}
		if(counter == Grid->RowCount-1){
			Grid->RowCount +=1;
            Grid->Cells[0][Grid->RowCount - 1] = List[i].GetInternetResource();
		}
	}
	}
	else{
		ShowMessage("ERROR! List is empty");
		return;
	}
}
