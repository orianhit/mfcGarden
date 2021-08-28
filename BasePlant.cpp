#include "pch.h"
#include "SpicePlant.h"
#include "PlantShopDlg.h"
#include "BasePlant.h"

//IMPLEMENT_SERIAL(BasePlant, CObject, 0)

BasePlant::BasePlant() {}

BasePlant::BasePlant(const BasePlant& msg) {
	this->name = msg.GetName();
}

void BasePlant::SetName(CString name) {
	this->name = name;
}

CString BasePlant::GetName()const {
	return this->name;
}

void BasePlant::Draw(CPaintDC* points, int x, int y) {
	points->TextOutW(x, y, this->name);
}

void BasePlant::DrawNumber(CPaintDC* points, int x, int y, CString number) {
	points->TextOutW(x, y, number);
}

void BasePlant::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->name;
	}
	else {
		ar >> this->name;
	}
}
