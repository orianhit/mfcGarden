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

	void Draw(CPaintDC*, int x, int y);
	void DrawNumber(CPaintDC*, int x, int y, CString);

	void Serialize(CArchive&);

protected:
	COLORREF color;
	int quantity;
	DECLARE_SERIAL(SpicePlant);
};