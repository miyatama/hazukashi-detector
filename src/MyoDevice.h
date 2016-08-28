#pragma once

#define _USE_MATH_DEFINES
#include "myo/myo.hpp"
#include "cmath"

class MyoDevice : public myo::DeviceListener {
public:
	MyoDevice();

	void onUnpair(myo::Myo* myo, uint64_t timestamp);
	void onOrientationData(myo::Myo* myo, uint64_t timestamp, const myo::Quaternion<float>& quat);
	void onPose(myo::Myo* myo, uint64_t timestamp, myo::Pose pose);
	void onArmSync(myo::Myo* myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection, float rotation,
		myo::WarmupState warmupState);
	void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg);
	void onArmUnsync(myo::Myo* myo, uint64_t timestamp);
	void onUnlock(myo::Myo* myo, uint64_t timestamp);
	void onLock(myo::Myo* myo, uint64_t timestamp);
	void print();

	bool enjoy;
	bool onArm;
	myo::Arm whichArm;
	bool isUnlocked;
	int roll_w, pitch_w, yaw_w;
	myo::Pose currentPose;
	int8_t emgs[8];
};