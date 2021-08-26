#pragma once

#include "pch.h"
#include "AbstractPlant.h"

class SpicePlant : public AbstractPlant, public CObject {
public:
	SpicePlant(void);
	SpicePlant(const SpicePlant&);

	virtual ~SpicePlant() {};

	SpicePlant(CString, COLORREF, int);

	virtual void SetColor(COLORREF);
	virtual COLORREF GetColor()const;

	virtual void SetText(CString);
	virtual CString GetText()const;

	virtual void SetPrice(int) = 0;
	virtual int GetPrice() const = 0;

	virtual void Draw(CPaintDC*, int x, int y);
	virtual void DrawNumber(CPaintDC*, int x, int y, CString);

	void Serialize(CArchive&);

protected:
	COLORREF color;
	CString txt;
	int price;
	DECLARE_SERIAL(SpicePlant);
};