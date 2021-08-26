#pragma once

#include "AbstractPlant.h"

class FlowerPlant : public AbstractPlant, public CObject {
public:
	FlowerPlant(void);

	FlowerPlant(const FlowerPlant&);

	FlowerPlant(CString, COLORREF, int, int, int, int, int, int);

	virtual int GetPrice()const;
	virtual CString GetText()const;
	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;
	int GetHours()const;
	int GetMinutes()const;

	virtual void SetPrice(int);
	virtual void SetText(CString);
	void SetPrice(int);
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	void SetHours(int);
	void SetMinutes(int);

	virtual ~FlowerPlant() {};

	void Serialize(CArchive&);

	void Draw(CPaintDC*, int x, int y);

	void DrawNumber(CPaintDC*, int x, int y, CString);

protected:
	DECLARE_SERIAL(FlowerPlant);
	CString txt;
	int price;
	int day, month, year, hours, minutes;
};

