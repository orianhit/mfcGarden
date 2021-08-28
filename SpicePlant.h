#pragma once

#include "pch.h"
#include "BasePlant.h"

class SpicePlant : public BasePlant {
public:
	SpicePlant(void);
	SpicePlant(const SpicePlant&);

	virtual ~SpicePlant() {};

	SpicePlant(CString, COLORREF, int);

	virtual void SetColor(COLORREF);
	virtual COLORREF GetColor()const;

	virtual void SetQuantity(int);
	virtual int GetQuantity() const;

	virtual void Draw(CPaintDC*, int x, int y);
	virtual void DrawNumber(CPaintDC*, int x, int y, CString);

	void Serialize(CArchive&);

protected:
	COLORREF color;
	CString name;
	int quantity;
	DECLARE_SERIAL(SpicePlant);
};