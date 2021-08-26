#pragma once

#include "AbstractPlant.h"

class FlowerPlant : public AbstractPlant, public CObject {
public:
	FlowerPlant(void);

	FlowerPlant(const FlowerPlant&);

	FlowerPlant(CString, int, int, int);

	virtual CString GetName()const;
	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;

	virtual void SetName(CString);
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);

	virtual ~FlowerPlant() {};

	void Serialize(CArchive&);

	void Draw(CPaintDC*, int x, int y);

	void DrawNumber(CPaintDC*, int x, int y, CString);

protected:
	DECLARE_SERIAL(FlowerPlant);
	CString name;
	int day, month, year;
};

