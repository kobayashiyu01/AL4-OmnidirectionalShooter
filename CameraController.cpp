#include "CameraController.h"
#include <numbers>

using namespace KamataEngine;

void CameraController::Initialize() { camera_.Initialize();
	camera_.rotation_ = {std::numbers::pi_v<float> / 2.0f, 0.0f, 0.0f};

}
void CameraController::Reset() { const WorldTransform& targetWT = target_->GetWorldTransform(); 
camera_.translation_ = targetWT.translation_ + targetOffset_;
	//camera_.TransferMatrix();
}


void CameraController::UpDate() { const WorldTransform& targetWT = target_->GetWorldTransform();

camera_.translation_ = targetWT.translation_ + targetOffset_;
	camera_.UpdateMatrix();
}


