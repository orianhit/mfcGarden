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

	virtual void SetName(CString);
	virtual CString GetName()const;

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