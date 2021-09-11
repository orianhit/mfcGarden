#include "pch.h"
#include "SpicePlant.h"
#include "PlantShopDlg.h"
#include "BasePlant.h"

IMPLEMENT_SERIAL(SpicePlant, CObject, 0)

SpicePlant::SpicePlant() {}

SpicePlant::SpicePlant(const SpicePlant& other): SpicePlant(other.name, other.color, other.quantity) {}

SpicePlant::SpicePlant(CString name, COLORREF color, int quantity): BasePlant(name) {
	this->color = color;
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

int SpicePlant::GetType() const {
	return 4;
}


void SpicePlant::Draw(CPaintDC* points, int x, int y) {
	CString numQ;
	numQ.Format(_T("%d"), this->quantity);
	points->SetTextColor(this->color);
	points->TextOutW(x, y, this->name + _T(" with quantity : ") + numQ);
	points->SetTextColor(0x00000000);
}

void SpicePlant::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->SetTextColor(this->color);
	points->TextOutW(x, y, number);
	points->SetTextColor(0x00000000);
}

void SpicePlant::Serialize(CArchive& ar) {
	BasePlant::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->color << this->quantity;
	} else {
		ar >> this->color << this->quantity;
	}
}
