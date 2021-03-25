#include "Matrix3.h"
//Author: Rauls Bergs


//Done 1 tested
MyMatrix3::MyMatrix3() : m11{ 0.0f }, m12{ 0.0f }, m13{ 0.0f }, m21{ 0.0f }, m22{ 0.0f }, m23{ 0.0f }, m31{ 0.0f }, m32{0.0f}, m33{0.0f}
{	
}
//Done 2 tested
MyMatrix3::MyMatrix3(float t_a11, float t_a12, float t_a13, float t_a21, float t_a22, float t_a23, float t_a31, float t_a32, float t_a33)	
{
	m11 = t_a11;
	m12 = t_a12;
	m13 = t_a13;
	m21 = t_a21;
	m22 = t_a22;
	m23 = t_a23;
	m31 = t_a31;
	m32 = t_a32;
	m33 = t_a33;
}
//Done 3 tested
MyMatrix3::MyMatrix3(MyVector3 t_row1, MyVector3 t_row2, MyVector3 t_row3) 
{
	m11 = t_row1.x;
	m12 = t_row1.y;
	m13 = t_row1.z;

	m21 = t_row2.x;
	m22 = t_row2.y;
	m33 = t_row2.z;

	m31 = t_row3.x;
	m32 = t_row3.y;
	m33 = t_row3.z;
}

//Done 4 tested
MyMatrix3::~MyMatrix3()
{
}
//Done 5 tested (transforms matrice to visual data in console)
std::string MyMatrix3::toString() const
{ 
	const std::string output = "[" + std::to_string(m11) + "," + std::to_string(m12) + "," + std::to_string(m13) + "]\n"
							+ "[" + std::to_string(m21) + "," + std::to_string(m22) + "," + std::to_string(m23) + "]\n"
							+ "[" + std::to_string(m31) + "," + std::to_string(m32) + "," + std::to_string(m33) + "]";
	return output;
	
}
//Done 6 tested (checks if both matrices have all the same members)
bool MyMatrix3::operator==(const MyMatrix3 other) const
{
	if (m11 == other.m11 && m12 == other.m12 && m13 == other.m13 &&
		m21 == other.m21 && m22 == other.m22 && m23 == other.m23 &&
		m31 == other.m31 && m32 == other.m32 && m33 == other.m33)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Done 7 tested (checks if a matrix has any of the same components)
bool MyMatrix3::operator!=(const MyMatrix3 other) const
{
	if (m11 != other.m11 || m12 != other.m12 || m13 != other.m13 ||
		m21 != other.m22 || m22 != other.m22 || m23 != other.m23 ||
		m31 != other.m31 || m32 != other.m32 || m33 != other.m33)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Done 8 Tested (Adds b matrix onto a matrix)
MyMatrix3 MyMatrix3::operator+(const MyMatrix3 t_other) const
{
	MyMatrix3 answer;

	(answer.m11 = m11 + t_other.m11, answer.m12 = m12 + t_other.m12, answer.m13 = m13 + t_other.m13,
	 answer.m21 = m21 + t_other.m21, answer.m22 = m22 + t_other.m22, answer.m23 = m23 + t_other.m23,
	 answer.m31 = m31 + t_other.m31, answer.m32 = m32 + t_other.m32, answer.m33 = m33 + t_other.m33);

	return answer;
}

//Done 9 Tested (subtarcts b matrix from a matrix)
MyMatrix3 MyMatrix3::operator-(const MyMatrix3 t_other) const
{
	MyMatrix3 answer;

	(answer.m11 = m11 - t_other.m11, answer.m12 = m12 - t_other.m12, answer.m13 = m13 - t_other.m13,
	 answer.m21 = m21 - t_other.m21, answer.m22 = m22 - t_other.m22, answer.m23 = m23 - t_other.m23,
	 answer.m31 = m31 - t_other.m31, answer.m32 = m32 - t_other.m32, answer.m33 = m33 - t_other.m33);

	return answer;
}

//Done 10 tested (multiplies matrix by another matrix)
MyMatrix3 MyMatrix3::operator*(const MyMatrix3 t_other) const
{
	MyMatrix3 answer;

	answer.m11 = (m11 * t_other.m11) + (m12 * t_other.m21) + (m13 * t_other.m31), // Not working
	answer.m12 = (m11 * t_other.m12) + (m12 * t_other.m22) + (m13 * t_other.m32),
	answer.m13 = (m11 * t_other.m13) + (m12 * t_other.m23) + (m13 * t_other.m33),
	answer.m21 = (m21 * t_other.m11) + (m22 * t_other.m21) + (m23 * t_other.m31), // Not working
	answer.m22 = (m21 * t_other.m12) + (m22 * t_other.m22) + (m23 * t_other.m32),
	answer.m23 = (m21 * t_other.m13) + (m22 * t_other.m23) + (m23 * t_other.m33),
	answer.m31 = (m31 * t_other.m11) + (m32 * t_other.m21) + (m33 * t_other.m31), // Not working
	answer.m32 = (m31 * t_other.m12) + (m32 * t_other.m22) + (m33 * t_other.m32),
	answer.m33 = (m31 * t_other.m13) + (m32 * t_other.m23) + (m33 * t_other.m33);

	return answer;
}

//Done 11 Tested (Multiplies matrix by a sf::vector3f)
MyVector3 MyMatrix3::operator*(const MyVector3 t_vector) const
{
	MyVector3 answer;

	(answer.x = (( m11 * t_vector.x) + (m12 * t_vector.y) + (m13 * t_vector.z)),
	 answer.y = ((m21 * t_vector.x) + (m22 * t_vector.y) + (m23 * t_vector.z)),
	 answer.z = ((m31 * t_vector.x) + (m32 * t_vector.y) + (m33 * t_vector.z)));

	return answer;
}

//Done 12 Tested (multiplies all members by a constant)
MyMatrix3 MyMatrix3::operator*(const float t_scale) const
{
	MyMatrix3 answer;

	(answer.m11 = m11 * t_scale, answer.m12 = m12 * t_scale, answer.m13 = m13 * t_scale,
	 answer.m21 = m21 * t_scale, answer.m22 = m22 * t_scale, answer.m23 = m23 * t_scale,
	 answer.m31 = m31 * t_scale, answer.m32 = m32 * t_scale, answer.m33 = m33 * t_scale);

	return answer;
}

//Done 13 Tested (Switches rows to columns)
MyMatrix3 MyMatrix3::transpose() const
{
	MyMatrix3 answer;

	answer.m11 = m11;
	answer.m21 = m12;
	answer.m31 = m13;

	answer.m12 = m21;
	answer.m22 = m22;
	answer.m32 = m23;

	answer.m13 = m31;
	answer.m23 = m32;
	answer.m33 = m33;

	return answer;
}

//Done 14 Tested
float MyMatrix3::determinant() const
{
	float DetA;

	DetA = (m11 * (m22 * m33 - m32 * m23)) - (m21 * (m33 * m12 - m32 * m13)) - (m31 * (m23 * m12 - m22 * m13));

	return DetA;
}


MyMatrix3 MyMatrix3::inverse() const
{
	MyMatrix3 answerInverseMatrix;
	float determinent;
	float determinentAns = 1;

	determinent = answerInverseMatrix.determinant();

	if (determinent != 0)
	{
		determinentAns = 1.0f / determinent;
	}

	answerInverseMatrix.m11 = (m33 * m22 - m32 * m23);
	answerInverseMatrix.m12 = (m32 * m13 - m33 * m12);
	answerInverseMatrix.m13 = (m23 * m12 - m22 * m13);
	answerInverseMatrix.m21 = (m31 * m23 - m33 * m21);
	answerInverseMatrix.m22 = (m33 * m11 - m31 * m13);
	answerInverseMatrix.m23 = (m21 * m13 - m23 * m11);
	answerInverseMatrix.m31 = (m32 * m21 - m31 * m22);
	answerInverseMatrix.m32 = (m31 * m12 - m32 * m11);
	answerInverseMatrix.m33 = (m22 * m11 - m21 * m12);

	answerInverseMatrix = answerInverseMatrix * determinentAns;

	return answerInverseMatrix;
}

MyVector3 MyMatrix3::row(const int t_row) const
{
	return MyVector3{}; 
}


MyVector3 MyMatrix3::column(const int t_column) const
{
	return MyVector3();
}

//Not Done 18
MyMatrix3 MyMatrix3::rotationZ(const float angleRadians)
{
	return MyMatrix3{}	;
}

//Not Done 19
MyMatrix3 MyMatrix3::rotationY(const float t_angleRadians)
{
	float radians = (float)(t_angleRadians * (acos(-1) / 180));
	return MyMatrix3
	(
		cos(radians), 0.0, -sin(radians),
		0.0, 1.0, 0.0,
		sin(radians), 0.0, cos(radians)
	);
}

//Not Done 20
MyMatrix3 MyMatrix3::rotationX(const float t_angleRadians)
{
	float radians = (float)(t_angleRadians * (acos(-1) / 180));
	return MyMatrix3
	(
		1.0, 0.0, 0.0,
		0.0, cos(radians), -sin(radians),
		0.0, sin(radians), cos(radians)
	);
}


//Not Done 21
MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
{
	return MyMatrix3
	(
		1.0 , 0.0, 0.0,
		0.0, 1.0 + (t_displacement.y/100), 0.0,
		0.0, 0.0, 1.0 
	);
}


//Not Done 22
MyMatrix3 MyMatrix3::scale(const float t_scalingfactor)
{
	return MyMatrix3
	(
		1.0 * t_scalingfactor, 0.0 , 0.0 ,
		0.0, 1.0 * t_scalingfactor, 0.0,
		0.0, 0.0, 1.0 * t_scalingfactor
	);
}
