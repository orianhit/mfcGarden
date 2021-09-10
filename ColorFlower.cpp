#include "pch.h"
#include "ColorFlower.h"

ColorFlower::ColorFlower() { }

ColorFlower::ColorFlower(const ColorFlower& other) : FlowerPlant(other.name, other.day, other.month, other.year) {
	this->color = other.color;
}

ColorFlower::ColorFlower(CString name, int day, int month, int year, COLORREF color) : FlowerPlant(name, day, month, year) {
	this->color = color;
}

void ColorFlower::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->name << this->year << this->month << this->day << this->color;
	}
	else {
		ar >> this->name >> this->year >> this->month >> this->day >> this->color;
	}
}

void ColorFlower::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);

	points->SetTextColor(this->color);
	points->TextOutW(x, y, Syear + L"/" + Smonth + L"/" + Sday);
	points->TextOutW(x, y + 20, this->name);
}

void ColorFlower::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->SetTextColor(this->color);
	points->TextOutW(x, y, number);
}

void ColorFlower::SetColor(COLORREF color) {
	this->color = color;
}

COLORREF ColorFlower::GetColor()const {
	return this->color;
}