#include "pch.h"
#include "FlowerPlant.h"
#include "PlantShopDlg.h"

FlowerPlant::FlowerPlant() { }

FlowerPlant::FlowerPlant(const FlowerPlant& other) {
	this->price = other.price;
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

FlowerPlant::FlowerPlant(CString txt, int price, int day, int month, int year) {
	this->price = price;
	this->day = day;
	this->month = month;
	this->year = year;
}

int FlowerPlant::GetPrice()const {
	return this->day;
}

int FlowerPlant::GetDay()const {
	return this->day;
}

int FlowerPlant::GetMonth()const {
	return this->month;

}

int FlowerPlant::GetYear()const {
	return this->year;

}

CString FlowerPlant::GetText()const {
	return this->txt;
}

void FlowerPlant::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->txt << this->price << this->year << this->month << this->day;
	}
	else {
		ar >> this->txt >> this->price >> this->year >> this->month >> this->day;

	}
}

void FlowerPlant::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);

	points->TextOutW(x, y, Syear + L"/" + Smonth + L"/" + Sday );
	points->TextOutW(x, y + 20, this->txt);
}

void FlowerPlant::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->TextOutW(x, y, number);
}

void FlowerPlant::SetDay(int day) {
	this->day = day;
}
void FlowerPlant::SetMonth(int month) {
	this->month = month;
}
void FlowerPlant::SetYear(int year) {
	this->year = year;
}
void FlowerPlant::SetText(CString txt) {
	this->txt = txt;
}
void FlowerPlant::SetPrice(int price) {
	this->price = price;
}