#pragma once
class AbstractPlant {
public:
	virtual ~AbstractPlant() {};

	virtual void SetName(CString) = 0;
	virtual CString GetName() const = 0;

	virtual void Serialize(CArchive&) = 0;
};