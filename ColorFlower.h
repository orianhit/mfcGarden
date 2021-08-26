#pragma once
#include "FlowerPlant.h"
class colorFlower : public FlowerPlant, public CObject {
public:
	colorFlower(void);

	colorFlower(const colorFlower&);

	colorFlower(CString, int, int, int, int, int, int, COLORREF);

	COLORREF GetColor()const;
	void SetColor(COLORREF color);

	void Serialize(CArchive&);

	void Draw(CPaintDC*, int x, int y);

	void DrawNumber(CPaintDC*, int x, int y, CString);
private:
	COLORREF color;
};