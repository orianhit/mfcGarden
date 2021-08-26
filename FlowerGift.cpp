#include "pch.h"
#include "FlowerGift.h"

FlowerGift::FlowerGift() { }

FlowerGift::FlowerGift(const FlowerGift& other) : FlowerPlant(other.txt, other.price,other.day,other.month,other.year) {
	this->greeting = other.greeting;
}

FlowerGift::FlowerGift(CString txt, int price, int day, int month, int year, CString greeting): FlowerPlant(txt, price, day, month, year) {
	this->greeting = greeting;
}

void FlowerGift::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->txt << this->price << this->year << this->month << this->day << this->greeting;
	}
	else {
		ar >> this->txt >> this->price >> this->year >> this->month >> this->day >> this->greeting;

	}
}

void FlowerGift::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);

	points->TextOutW(x, y, Syear + L"/" + Smonth + L"/" + Sday);
	points->TextOutW(x, y + 20, this->txt + L",  " + this->greeting);
}

void FlowerGift::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->TextOutW(x, y, number);
}

void FlowerGift::SetGreetingMsg(CString greeting) {
	this->greeting = greeting;
}

CString FlowerGift::GetGreetingMsg() const{
	return this->greeting;
}