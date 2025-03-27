#pragma once

#include <Geode/Geode.hpp>

#include "FryyGIF_v1.0.hpp"

using namespace geode::prelude;


class FryyVideo : public FryyGIF {
	public:
		static FryyVideo* create(char const*, float);
		inline void setLoops(unsigned long loops) {
			m_loops = loops;
			return;
		}
	protected:
		void update(float) override;

		unsigned long m_loops = 1;
};