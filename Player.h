#pragma once
#include "KamataEngine.h"
#include "MapChipField.h"
#include "Matrix.h"

class Player {
	enum class LRDirection {

		kRight,
		kLeft,
		kUp,
		kDown
	};

public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);
	void MoveKeys();
	void Update();
	void Draw();

	void SetMapChipField(MapChipField* mapChipField);
	KamataEngine::WorldTransform& GetWorldTransform() { return worldTransform_; }

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;

	KamataEngine::Vector3 velocity_ = {};

	LRDirection lrDirection_ = LRDirection::kUp;


	// 旋回開始時の角度
	float turnFirstRotationY = 0.0f;
	float turnFirstRotationX = 0.0f;
	// 旋回タイマー
	float turnTimer_ = 0.0f;

	// 旋回時間＜秒＞
	static inline const float kTurnTime = 0.3f;

	static inline const float kAcceleration = 0.05f;
	static inline const float kAttenuation = 0.3f;
	static inline const float kLimitRunSpeed = 0.2f;

};
