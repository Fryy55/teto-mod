#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>
#include <Geode/modify/EditorPauseLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>

#include "include/FryyGIF_v1.0.hpp"

using namespace geode::prelude;




class $modify(PlayLayer) {
	$override void onEnterTransitionDidFinish() {
		PlayLayer::onEnterTransitionDidFinish();

		m_pParent -> getChildByID("teto-menu"_spr) ->
			getChildByID("teto"_spr) -> setVisible(false);

		return;
	}

	$override void onQuit() {
		PlayLayer::onQuit();

		m_pParent -> getChildByID("teto-menu"_spr) ->
			getChildByID("teto"_spr) -> setVisible(true);

		return;
	}
};

class $modify(LevelEditorLayer) {
	$override bool init(GJGameLevel* p0, bool p1) {
		if (!LevelEditorLayer::init(p0, p1))
			return false;

		CCDirector::get() -> getRunningScene() -> getChildByID("teto-menu"_spr) ->
			getChildByID("teto"_spr) -> setVisible(false);

		return true;
	}
};

class $modify(EditorPauseLayer) {
	$override void onExitEditor(CCObject* sender) {
		EditorPauseLayer::onExitEditor(sender);

		CCDirector::get() -> getRunningScene() -> getChildByID("teto-menu"_spr) ->
			getChildByID("teto"_spr) -> setVisible(true);

		return;
	}
};

class $modify(LoadingLayer) {
	$override void loadAssets() {
		LoadingLayer::loadAssets();

		static bool m_tetoLoaded = false;
		if (!m_tetoLoaded) {
			auto tetoMenu = CCMenu::create();
			tetoMenu -> setID("teto-menu"_spr);
			tetoMenu -> setVisible(Mod::get() -> getSettingValue<bool>("teto-toggle"));

			auto teto = FryyGIF::create(
				"TetoSheet.plist"_spr,
				(1.1f - (Mod::get() -> getSettingValue<double>("teto-speed"))) * 0.1f
			);
			teto -> setID("teto"_spr);
			teto -> setZOrder(55);
			teto -> setAnchorPoint(CCPoint(0.f, 0.f));

			tetoMenu -> addChildAtPosition(teto, Anchor::BottomLeft);

			SceneManager::get() -> keepAcrossScenes(tetoMenu);
			m_tetoLoaded = true;
		}
		return;
	}
};