#include "pch.h"
#include "FlowerColor.h"

FlowerColor::FlowerColor() { }

FlowerColor::FlowerColor(const FlowerColor& other) : FlowerPlant(other.name, other.day, other.month, other.year) {
	this->color = other.color;
}

FlowerColor::FlowerColor(CString name, int day, int month, int year, COLORREF color) : FlowerPlant(name, day, month, year) {
	this->color = color;
}

void FlowerColor::Serialize(CArchive& ar) {
	FlowerPlant::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->color;
	} else {
		ar >> this->color;
	}
}

void FlowerColor::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);

	points->SetTextColor(this->color);
	points->TextOutW(x, y, L"Flower with color named " + this->name);
	points->TextOutW(x, y + 20, L"valid until - " + Syear + L"/" + Smonth + L"/" + Sday);
	points->SetTextColor(0x00000000);
}

void FlowerColor::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->SetTextColor(this->color);
	points->TextOutW(x, y, number);
	points->SetTextColor(0x00000000);
}

void FlowerColor::SetColor(COLORREF color) {
	this->color = color;
}

int FlowerColor::GetType() const{
	return 2;
}

COLORREF FlowerColor::GetColor()const {
	return this->color;
}