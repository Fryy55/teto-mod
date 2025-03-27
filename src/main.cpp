#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/terminate.hpp>
#include <Geode/modify/SupportLayer.hpp>

#include "include/FryyGIF_v1.0.hpp"

using namespace geode::prelude;


$on_mod(Loaded) {
	listenForSettingChanges("teto-toggle", [](bool value) {
		auto teto = CCScene::get() -> getChildByID("teto-menu"_spr);
		if (value)
			teto -> setVisible(true);
		else
			teto -> setVisible(false);
	});
	listenForSettingChanges("teto-speed", [](float value) {
		static_cast<FryyGIF*>(CCScene::get() -> getChildByIDRecursive("teto"_spr)) ->
			setDelay((1.1f - value) * 0.1f);
	});
}