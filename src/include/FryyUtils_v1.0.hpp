#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;


namespace FryyUtils {
	inline CCArray* framesArrFromPlist(char const* plist) {
		return static_cast<CCDictionary*>(CCDictionary::createWithContentsOfFile(
			(CCFileUtils::get() -> fullPathForFilename(plist, false)).c_str()
		) -> objectForKey("frames")) -> allKeys();
	}
}