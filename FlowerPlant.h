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

	virtual COleDateTime GetDate() const;

	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);

	virtual int GetType() const;

	virtual ~FlowerPlant() {};

	void Serialize(CArchive&);

	void Draw(CPaintDC*, int x, int y);

	void DrawNumber(CPaintDC*, int x, int y, CString);

protected:
	DECLARE_SERIAL(FlowerPlant);
	int day, month, year;
};

