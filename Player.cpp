#define NOMINMAX
#include "Player.h"
#include "algorithm"
#include "math.h"
#include <numbers>

using namespace KamataEngine;

void Player::Initialize(Model* model, Camera* camera, const Vector3& position) {

	model_ = model;

	camera_ = camera;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.rotation_.x = std::numbers::pi_v<float> / 2.0f;

	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();
}

void Player::MoveKeys() {// 左右移動操作
	if (Input::GetInstance()->PushKey(DIK_W) || Input::GetInstance()->PushKey(DIK_A) || Input::GetInstance()->PushKey(DIK_S) || Input::GetInstance()->PushKey(DIK_D)) {
		// 左右加速
		Vector3 acceleration = {};

		if (Input::GetInstance()->TriggerKey(DIK_W)) {
			if (velocity_.y > 0.0f) {
				velocity_.y *= (1.0f - kAttenuation);
			}
			acceleration.y = kAcceleration;
			if (lrDirection_ != LRDirection::kUp) {
				lrDirection_ = LRDirection::kUp;

				turnFirstRotationX = worldTransform_.rotation_.x;

				turnTimer_ = kTurnTime;
			}
		} else if (Input::GetInstance()->TriggerKey(DIK_W)) {
			if (velocity_.y > 0.0f) {
				velocity_.y *= (1.0f - kAttenuation);
			}
			acceleration.y -= kAcceleration;
			if (lrDirection_ != LRDirection::kDown) {
				lrDirection_ = LRDirection::kDown;

				turnFirstRotationX = worldTransform_.rotation_.x;

				turnTimer_ = kTurnTime;
			}
		} else if (Input::GetInstance()->PushKey(DIK_D)) {

			if (velocity_.x < 0.0f) {
				velocity_.x *= (1.0f - kAttenuation);
			}
			acceleration.x = kAcceleration;
			if (lrDirection_ != LRDirection::kRight) {
				lrDirection_ = LRDirection::kRight;

				turnFirstRotationY = worldTransform_.rotation_.y;

				turnTimer_ = kTurnTime;
			}
		} else if (Input::GetInstance()->PushKey(DIK_A)) {

			if (velocity_.x > 0.0f) {
				velocity_.x *= (1.0f - kAttenuation);
			}
			acceleration.x -= kAcceleration;
			if (lrDirection_ != LRDirection::kLeft) {
				lrDirection_ = LRDirection::kLeft;
				//
				turnFirstRotationY = worldTransform_.rotation_.y;

				//
				turnTimer_ = kTurnTime;
			}
		}

		velocity_.x += acceleration.x;
		velocity_.y += acceleration.y;
		velocity_.z += acceleration.z;

		velocity_.x = std::clamp(velocity_.x, -kLimitRunSpeed, kLimitRunSpeed);

	} else {
		// 非入力時は移動減衰をかける
		velocity_.x *= (1.0f - kAttenuation);
	}
	// 旋回制御
	if (kTurnTime > 0.0f) {

		turnTimer_ -= 1.0f / 60.0f;

		float destinationRotationYTable[] = {
		    std::numbers::pi_v<float> / 2.0f,
		    std::numbers::pi_v<float> * 3.0f / 2.0f,
		};

		// 状態に応じた角度を取得する
		float destinationRotationY = destinationRotationYTable[static_cast<uint32_t>(lrDirection_)];

		worldTransform_.rotation_.y = Lerp(turnFirstRotationY, destinationRotationY, kTurnTime);
		worldTransform_.rotation_.y = destinationRotationY;
	}
}

void Player::Update() { MoveKeys(); }

void Player::Draw() {}
