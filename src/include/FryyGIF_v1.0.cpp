#include <Geode/Geode.hpp>
#include <vector>

#include "FryyGIF_v1.0.hpp"
#include "FryyUtils_v1.0.hpp"

using namespace geode::prelude;


FryyGIF* FryyGIF::create(char const* sheet, float delay) {
	auto ret = new FryyGIF;
	if (ret -> init(sheet, delay)) {
		ret -> autorelease();
		return ret;
	}

	delete ret;
	return nullptr;
}

bool FryyGIF::init(char const* sheet, float delay) {
	auto framesCCArr = FryyUtils::framesArrFromPlist(sheet);
	m_count = framesCCArr -> count();
	m_frames.resize(m_count);
	for (unsigned short i = 0; i < m_count; i++)
		m_frames[i] = CCSpriteFrameCache::sharedSpriteFrameCache() ->
			spriteFrameByName(
				static_cast<CCString*>(framesCCArr -> objectAtIndex(i)) -> getCString()
			);

	if (!CCSprite::initWithSpriteFrame(m_frames[0]))
		return false;

	m_delay = delay;

	this -> scheduleUpdate();

	return true;
}

void FryyGIF::update(float dt) {
	if (m_bVisible) {
		static float timer = 0;

		timer += dt;
		if (timer >= m_delay) {
			this -> setDisplayFrame(m_frames[m_curFrame]);
			m_curFrame++;
			m_curFrame %= m_count;
			timer = 0.f;
		}
	}

	return;
}