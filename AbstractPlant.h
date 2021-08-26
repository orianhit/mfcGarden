#pragma once
class AbstractPlant {
public:
	virtual ~AbstractPlant() {};

	virtual void SetText(CString) = 0;
	virtual CString GetText() const = 0;

	virtual void SetPrice(int) = 0;
	virtual int GetPrice() const = 0;

	virtual void Serialize(CArchive&) = 0;
};

