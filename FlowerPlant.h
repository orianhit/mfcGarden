#pragma once

#include "BasePlant.h"

class FlowerPlant : public BasePlant {
public:
	FlowerPlant(void);

	FlowerPlant(const FlowerPlant&);

	FlowerPlant(CString, int, int, int);

	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;

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

