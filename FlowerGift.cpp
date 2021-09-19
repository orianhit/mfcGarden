#include "pch.h"
#include "FlowerGift.h"

FlowerGift::FlowerGift() { }

FlowerGift::FlowerGift(const FlowerGift& other) : FlowerPlant(other.name,other.day,other.month,other.year) {
	this->greeting = other.greeting;
}

FlowerGift::FlowerGift(CString name, int day, int month, int year, CString greeting): FlowerPlant(name, day, month, year) {
	this->greeting = greeting;
}

void FlowerGift::Serialize(CArchive& ar) {
	FlowerPlant::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->greeting;
	} else {
		ar >> this->greeting;
	}
}

void FlowerGift::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);

	points->TextOutW(x, y, L"Flower to gift named " + this->name);
	points->TextOutW(x, y + 20, L"valid until - " + Syear + L"/" + Smonth + L"/" + Sday);
	points->TextOutW(x, y + 40, L"includes greeting for the gift: " + this->greeting);
}

void FlowerGift::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->TextOutW(x, y, number);
}

void FlowerGift::SetGreetingMsg(CString greeting) {
	this->greeting = greeting;
}

int FlowerGift::GetType() const{
	return 3;
}

CString FlowerGift::GetGreetingMsg() const{
	return this->greeting;
}