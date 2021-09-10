#pragma once
class BasePlant : public CObject {
public:
	BasePlant();
	BasePlant(const BasePlant&);
	BasePlant(CString);
	virtual ~BasePlant() {};

	void SetName(CString);
	virtual CString GetName() const;
	virtual void Draw(CPaintDC* points, int x, int y);
	virtual void DrawNumber(CPaintDC*, int x, int y, CString);

	virtual void Serialize(CArchive&);
protected:
	CString name;
};