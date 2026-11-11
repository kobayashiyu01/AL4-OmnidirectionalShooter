#include "MathematicalFunction.h"

using namespace KamataEngine;

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

// スカラー倍
Vector3 Multiply(float scale, const Vector3& v) {
	Vector3 result;
	result.x = scale * v.x;
	result.y = scale * v.y;
	result.z = scale * v.z;
	return result;
}

// 内積
float Dot(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return result.x + result.y + result.z;
}

// 長さ(ノルム)
float Length(const Vector3& v) {
	Vector3 result;
	result.x = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	result.y = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	result.z = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return result.x;
}

Vector3 Normalize(const Vector3& v) {
	float length = Length(v);
	if (length == 0.0f) {
		return {0, 0, 0};
	}
	return {v.x / length, v.y / length, v.z / length};
}

// 1. クロス積

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;

	return result;
}

Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};

	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			result.m[row][column] = m1.m[row][column] + m2.m[row][column];
		}
	}

	return result;
}
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};

	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			result.m[row][column] = m1.m[row][column] - m2.m[row][column];
		}
	}

	return result;
}
