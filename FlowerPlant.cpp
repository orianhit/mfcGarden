#include "pch.h"
#include "FlowerPlant.h"
#include "PlantShopDlg.h"

IMPLEMENT_SERIAL(FlowerPlant, CObject, 0)

FlowerPlant::FlowerPlant() { }

FlowerPlant::FlowerPlant(const FlowerPlant& other): BasePlant(other) {
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

FlowerPlant::FlowerPlant(CString name, int day, int month, int year): BasePlant(name) {
	this->day = day;
	this->month = month;
	this->year = year;
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

COleDateTime FlowerPlant::GetDate() const {
	COleDateTime dateOne(this->year, this->month, this->day, 12, 0, 0);
	return dateOne;
}

void FlowerPlant::Serialize(CArchive& ar) {
	BasePlant::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->year << this->month << this->day;
	} else {
		ar >> this->year >> this->month >> this->day;
	}
}

void FlowerPlant::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);

	points->TextOutW(x, y, L"Flower named " + this->name);
	points->TextOutW(x, y + 20, L"valid until - " + Syear + L"/" + Smonth + L"/" + Sday);
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

int FlowerPlant::GetType() const {
	return 1;
}
