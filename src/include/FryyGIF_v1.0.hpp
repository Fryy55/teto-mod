#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;


class FryyGIF : public CCSprite {
	public:
		static FryyGIF* create(char const*, float);
		inline void setDelay(float newDelay) {
			m_delay = newDelay;
			return;
		}
	protected:
		virtual bool init(char const*, float);
		void update(float) override;

		std::vector<CCSpriteFrame*> m_frames;
		float m_delay;
		unsigned short m_count;
		unsigned short m_curFrame = 1;
};