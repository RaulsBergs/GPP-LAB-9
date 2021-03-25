#ifndef MY_MATRIX
#define MY_MATRIX
#include "Vector3.h"
//Author: Rauls Bergs

class MyMatrix3
{
public:
	MyMatrix3();
	MyMatrix3(
		float t_a11, float t_a12, float t_a13,
		float t_a21, float t_a22, float t_a23,
		float t_a31, float t_a32, float t_a33);
	MyMatrix3(MyVector3 t_row1, MyVector3 t_row2, MyVector3 t_row3);
	~MyMatrix3();



	std::string toString()const;

	bool operator ==(const MyMatrix3 other)const;
	bool operator !=(const MyMatrix3 other)const;


	MyMatrix3 operator +(const MyMatrix3 t_other) const;
	MyMatrix3 operator -(const MyMatrix3 t_other) const;
	MyMatrix3 operator *(const MyMatrix3 t_other) const;
	MyVector3 operator *(const MyVector3 t_vector)const;
	MyMatrix3 operator *(const float t_scale)const;

	MyMatrix3 transpose()const;
	float determinant() const;
	MyMatrix3 inverse() const;

	MyVector3 row(const int t_row)const;
	MyVector3 column(const int t_column) const;


	static MyMatrix3 rotationZ(const float t_angleRadians);
	static MyMatrix3 rotationY(const float t_angleRadians);
	static MyMatrix3 rotationX(const float t_angleRadians);

	static MyMatrix3 translation(const MyVector3 t_displacement); // 2d translation make sure z=1
	static MyMatrix3 scale(const float t_scalingfactor);


private:
	float m11;
	float m12;
	float m13;
	float m21;
	float m22;
	float m23;
	float m31;
	float m32;
	float m33;
};

#endif // !MY_MATRIX


namespace gpp
{
	class Matrix3
	{
	public:
		Matrix3() {};
		~Matrix3() {};
	private:
	};
}
