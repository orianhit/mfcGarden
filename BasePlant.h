#pragma once
class BasePlant : public CObject {
public:
	BasePlant();
	BasePlant(const BasePlant&);
	BasePlant(CString);
	virtual ~BasePlant() {};

	void SetName(CString);
	virtual CString GetName() const;
	virtual CString GetGreeting() const { return NULL; };
	virtual COLORREF GetColor() const { return NULL; };
	virtual int GetQuantity() const { return NULL; };
	virtual COleDateTime GetDate() const { return COleDateTime::GetCurrentTime(); };
	virtual int GetType() const { return -1; };
	virtual void Draw(CPaintDC* points, int x, int y);
	virtual void DrawNumber(CPaintDC*, int x, int y, CString);

	virtual void Serialize(CArchive&);
protected:
	DECLARE_SERIAL(BasePlant)
	CString name;
};