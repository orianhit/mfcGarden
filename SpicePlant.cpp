#include "pch.h"
#include "SpicePlant.h"
#include "PlantShopDlg.h"
#include "AbstractPlant.h"

IMPLEMENT_SERIAL(SpicePlant, CObject, 0)

SpicePlant::SpicePlant() {

}

SpicePlant::SpicePlant(const SpicePlant& msg) {
	this->color = msg.GetColor();
	this->txt = msg.GetText();
	this->price = msg.GetPrice();
}

SpicePlant::SpicePlant(CString txt, COLORREF color, int price) {
	this->color = color;
	this->txt = txt;
	this->price = price;
}

void SpicePlant::SetColor(COLORREF color) {
	this->color = color;
}

COLORREF SpicePlant::GetColor()const {
	return this->color;
}

void SpicePlant::SetText(CString txt) {
	this->txt = txt;
}

CString SpicePlant::GetText()const {
	return this->txt;
}

void SpicePlant::SetPrice(int price) {
	this->price = price;
}

int SpicePlant::GetPrice() const {
	return this->price;
}

void SpicePlant::Draw(CPaintDC* points, int x, int y) {
	points->SetTextColor(this->color);
	points->TextOutW(x, y, this->txt);
}

void SpicePlant::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->SetTextColor(this->color);
	points->TextOutW(x, y, number);
}

void SpicePlant::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->txt << this->color << this->price;
	}
	else {
		ar >> this->txt >> this->color << this->price;
	}
}
