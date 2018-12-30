//---------------------------------------------------------------------------

#ifndef ClassH
#define ClassH
//---------------------------------------------------------------------------
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <vcl.h>
#include <fstream>

#include <Vcl.Grids.hpp>
using namespace std;
class audioFile{
	String Name;
	String internetResource;
	String format;
	int duration;
	String Codek;
	long discretizationClock;
	int Bitrate;
	int text;
	String playerName;
	public:
	String GetName() const               {return Name;}                    //-----------
	String GetInternetResource() const   {return internetResource;}        //
	String GetFormat() const			 {return format;}                  //
	int GetDuration() const			     {return duration;}                //
	String GetCodek() const			     {return Codek;}                   // Getters
	long GetDiscretizationClock() const  {return discretizationClock;}     //
	int GetBitrate() const               {return Bitrate;}                 //
	int GetText() const				     {return text;}                    //
	String GetPlayerName() const	     {return playerName;}              //-----------
	void SetName(String name) 				{this->Name = name;}           //
	void SetInternetResource(String res)	{this->internetResource = res;}//
	void SetFormat(String form) 			{this->format = form;}         //
	void SetDuration(int dur) 				{this->duration = dur;}        //
	void SetCodek(String codek)				{this->Codek = codek;}         // Setters
	void SetDiscretizationClock(long clock)	{this->discretizationClock = clock;}
	void SetBitrate(int bitrate)			{this->Bitrate = bitrate;}     //
	void SetText(int Text)					{this->text = Text;}           //
	void SetPlayerName(String player)		{this->playerName = player;}   //-----------
	audioFile();                                                                      //-------
	audioFile(String name, String res, String form, int dur, String codek, long clock,// Costructors
	int bitrate, int text, String player);                                            //
	audioFile(const audioFile &File);                                                 //
	~audioFile();                                                                     //-------
};

class list{
    public:
	vector<audioFile> List;
	list(const list &L);
	list(){}
    ~list();

	void addTrack(String Name, String res, String form, int dur, String codek, long clock,
	int bitrate, int Text, String player);

	void show(TStringGrid* Grid);          //Вивід списку в прямому і зворотному порядку
	void showReverse(TStringGrid* Grid);   //

	void findByCodek(String taskCodek, TStringGrid* Grid);  //Пошук за заданими параметрами
	void findByBitrate(int taskBitrate, TStringGrid* Grid); //

	void operator<<(ifstream &f);         //--------------------
	void operator>>(ofstream &f);         //Оператори для зчитування та запису в файл
	void operator=(const list &L);        //---------------------

	bool sortName(audioFile &t1, audioFile &t2);    //----------------------------
	bool sortRes(audioFile &t1, audioFile &t2);     //
	bool sortFormat(audioFile &t1, audioFile &t2);  //
	bool sortDur(audioFile &t1, audioFile &t2);     //
	bool sortCodek(audioFile &t1, audioFile &t2);   // Функції порівняння для std::sort
	bool sortClock(audioFile &t1, audioFile &t2);   //
	bool sortBitrate(audioFile &t1, audioFile &t2); //
	bool sortText(audioFile &t1, audioFile &t2);    //
	bool sortPlayer(audioFile &t1, audioFile &t2);  //---------------------------

	bool isSortName();         //----------------------------
	bool isSortRes();          //
	bool isSortFormat();       //
	bool isSortDur();          //
	bool isSortCodek();        //  Перевірка, чи список вже відсортований по заданому параметру
	bool isSortClock();        //
	bool isSortBitrate();      //
	bool isSortText();         //
	bool isSortPlayer();       //----------------------------

	void sameResource(String Res);
    void findRes(TStringGrid* Grid);
};
