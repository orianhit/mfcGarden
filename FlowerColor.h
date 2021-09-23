#pragma once
#include "FlowerPlant.h"
class FlowerColor : public FlowerPlant {
public:
	FlowerColor(void);

	FlowerColor(const FlowerColor&);

	FlowerColor(CString, int, int, int, COLORREF);

	COLORREF GetColor()const;
	void SetColor(COLORREF color);

	virtual int GetType() const;

	void Serialize(CArchive&);

	void Draw(CPaintDC*, int x, int y);

	void DrawNumber(CPaintDC*, int x, int y, CString);
private:
	COLORREF color;
	DECLARE_SERIAL(FlowerColor)
};