#include "pch.h"
#include "FlowerPlant.h"
#include "PlantShopDlg.h"

IMPLEMENT_SERIAL(FlowerPlant, CObject, 0)

FlowerPlant::FlowerPlant() { }

FlowerPlant::FlowerPlant(const FlowerPlant& other) {
	this->price = other.price;
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	this->hours = other.hours;
	this->minutes = other.minutes;
}

FlowerPlant::FlowerPlant(CString txt, COLORREF color, int price, int day, int month, int year, int hours, int minutes) {
	this->price = price;
	this->day = day;
	this->month = month;
	this->year = year;
	this->hours = hours;
	this->minutes = minutes;
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

int FlowerPlant::GetHours()const {
	return this->hours;

}

int FlowerPlant::GetMinutes()const {
	return this->minutes;

}

CString FlowerPlant::GetText()const {
	return this->txt;
}

int FlowerPlant::GetPrice()const {
	return this->price;
}

void FlowerPlant::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->txt << this->price << this->year << this->month << this->day << this->hours << this->minutes;
	}
	else {
		ar >> this->txt >> this->price >> this->year >> this->month >> this->day >> this->hours >> this->minutes;

	}
}

void FlowerPlant::Draw(CPaintDC* points, int x, int y) {
	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"), year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);
	Shours.Format(_T("%d"), hours);
	Sminutes.Format(_T("%d"), minutes);

	points->TextOutW(x, y, Syear + L"/" + Smonth + L"/" + Sday + L" " + Shours + L":" + Sminutes);
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
void FlowerPlant::SetHours(int hours) {
	this->hours = hours;
}
void FlowerPlant::SetMinutes(int minutes) {
	this->minutes = minutes;
}
void FlowerPlant::SetText(CString txt) {
	this->txt = txt;
}
void FlowerPlant::SetPrice(int price) {
	this->price = price;
}