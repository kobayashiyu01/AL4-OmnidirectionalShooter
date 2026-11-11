#pragma once
#include "KamataEngine.h"
#include "Matrix.h"

KamataEngine::Vector3 operator+(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2) { return Add(v1, v2); }
KamataEngine::Vector3 operator-(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2) { return Subtract(v1, v2); }
KamataEngine::Vector3 operator*(float s, const KamataEngine::Vector3& v) { return Multiply(s, v); }
KamataEngine::Vector3 operator*(const KamataEngine::Vector3& v, float s) { return s * v; }
KamataEngine::Vector3 operator/(const KamataEngine::Vector3& v, float s) { return Multiply(1.0f / s, v); }

Matrix4x4 operator+(const Matrix4x4& m1, const Matrix4x4& m2) { return Add(m1, m2); }
Matrix4x4 operator-(const Matrix4x4& m1, const Matrix4x4& m2) { return Subtract(m1, m2); }
Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2) { return Multiply(m1, m2); }

KamataEngine::Vector3 Add(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
KamataEngine::Vector3 Subtract(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
KamataEngine::Vector3 Multiply(float scale, const KamataEngine::Vector3& v);
float Dot(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
float Length(const KamataEngine::Vector3& v);
KamataEngine::Vector3 Normalize(const KamataEngine::Vector3& v);
KamataEngine::Vector3 Cross(const KamataEngine::Vector3& v1, const KamataEngine::Vector3& v2);
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
