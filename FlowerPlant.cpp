#include "pch.h"
#include "FlowerPlant.h"
#include "PlantShopDlg.h"

IMPLEMENT_SERIAL(FlowerPlant, CObject, 0)

FlowerPlant::FlowerPlant() { }

FlowerPlant::FlowerPlant(const FlowerPlant& other) {
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

FlowerPlant::FlowerPlant(CString name, int day, int month, int year) {
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

void FlowerPlant::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->name << this->year << this->month << this->day;
	}
	else {
		ar >> this->name >> this->year >> this->month >> this->day;

	}
}

void FlowerPlant::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);

	points->TextOutW(x, y, Syear + L"/" + Smonth + L"/" + Sday );
	points->TextOutW(x, y + 20, this->name);
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