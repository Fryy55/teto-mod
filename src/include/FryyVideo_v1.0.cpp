#include <Geode/Geode.hpp>

#include "FryyVideo_v1.0.hpp"

using namespace geode::prelude;


FryyVideo* FryyVideo::create(char const* sheet, float delay) {
	auto ret = new FryyVideo;
	if (ret -> init(sheet, delay)) {
		ret -> autorelease();
		return ret;
	}

	delete ret;
	return nullptr;
}

void FryyVideo::update(float dt) {
	FryyGIF::update(dt);

	static unsigned long loops = 0;
	if (m_curFrame == 0) {
		loops++;
		if (loops >= m_loops)
			this -> removeFromParent();
	}

	return;
}