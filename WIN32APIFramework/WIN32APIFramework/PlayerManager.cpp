#include "PlayerManager.h"

SINGLETON_INIT(PlayerManager)

PlayerManager::PlayerManager() {}
PlayerManager::~PlayerManager() { delete _character; }