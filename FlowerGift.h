#pragma once
#include "FlowerPlant.h"

class FlowerGift : public FlowerPlant {
public:
	FlowerGift(void);

	FlowerGift(const FlowerGift&);

	FlowerGift(CString, int, int, int, CString);

	CString GetGreeting() const;
	void SetGreeting(CString);

	virtual int GetType() const;

	void Serialize(CArchive&);

	void Draw(CPaintDC*, int x, int y);

	void DrawNumber(CPaintDC*, int x, int y, CString);
private:
	CString greeting;
	DECLARE_SERIAL(FlowerGift)
};

