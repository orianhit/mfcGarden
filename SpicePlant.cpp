#include "pch.h"
#include "SpicePlant.h"
#include "PlantShopDlg.h"
#include "BasePlant.h"

IMPLEMENT_SERIAL(SpicePlant, CObject, 0)

SpicePlant::SpicePlant() {}

SpicePlant::SpicePlant(const SpicePlant& msg) {
	this->color = msg.GetColor();
	this->name = msg.GetName();
	this->quantity = msg.GetQuantity();
}

SpicePlant::SpicePlant(CString name, COLORREF color, int quantity) {
	this->color = color;
	this->name = name;
	this->quantity = quantity;
}

void SpicePlant::SetColor(COLORREF color) {
	this->color = color;
}

COLORREF SpicePlant::GetColor()const {
	return this->color;
}

void SpicePlant::SetQuantity(int quantity) {
	this->quantity = quantity;
}

int SpicePlant::GetQuantity() const {
	return this->quantity;
}

void SpicePlant::Draw(CPaintDC* points, int x, int y) {
	points->SetTextColor(this->color);
	points->TextOutW(x, y, this->name);
}

void SpicePlant::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->SetTextColor(this->color);
	points->TextOutW(x, y, number);
}

void SpicePlant::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->name << this->color << this->quantity;
	}
	else {
		ar >> this->name >> this->color << this->quantity;
	}
}
