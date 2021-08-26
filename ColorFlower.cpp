#include "pch.h"
#include "ColorFlower.h"


ColorFlower::ColorFlower() { }

ColorFlower::ColorFlower(const ColorFlower& other) : FlowerPlant(other.txt, other.price, other.day, other.month, other.year, other.hours, other.minutes) {
	this->color = other.color;
}

ColorFlower::ColorFlower(CString txt, int price, int day, int month, int year, int hours, int minutes, COLORREF color) : FlowerPlant(txt, price, day, month, year, hours, minutes) {
	this->color = color;
}

void ColorFlower::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->txt << this->price << this->year << this->month << this->day << this->hours << this->minutes << this->color;
	}
	else {
		ar >> this->txt >> this->price >> this->year >> this->month >> this->day >> this->hours >> this->minutes >> this->color;
	}
}

void ColorFlower::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);
	Shours.Format(_T("%d"), hours);
	Sminutes.Format(_T("%d"), minutes);

	points->SetTextColor(this->color);
	points->TextOutW(x, y, Syear + L"/" + Smonth + L"/" + Sday + L" " + Shours + L":" + Sminutes);
	points->TextOutW(x, y + 20, this->txt);
}

void ColorFlower::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->TextOutW(x, y, number);
}

void ColorFlower::SetColor(COLORREF color) {
	this->color = color;
}

COLORREF ColorFlower::GetColor()const {
	return this->color;
}