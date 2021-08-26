#include "pch.h"
#include "FlowerGift.h"

FlowerGift::FlowerGift() { }

FlowerGift::FlowerGift(const FlowerGift& other) : FlowerPlant(other.txt, other.price,other.day,other.month,other.year, other.hours, other.minutes) {
	this->greeting = other.greeting;
}

FlowerGift::FlowerGift(CString txt, int price, int day, int month, int year, int hours, int minutes, CString greeting) : FlowerPlant(txt, price, day, month, year, hours, minutes) {
	this->greeting = greeting;
}

void FlowerGift::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->txt << this->price << this->year << this->month << this->day << this->hours << this->minutes << this->greeting;
	}
	else {
		ar >> this->txt >> this->price >> this->year >> this->month >> this->day >> this->hours >> this->minutes >> this->greeting;

	}
}

void FlowerGift::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);
	Shours.Format(_T("%d"), hours);
	Sminutes.Format(_T("%d"), minutes);

	points->TextOutW(x, y, Syear + L"/" + Smonth + L"/" + Sday + L" " + Shours + L":" + Sminutes);
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