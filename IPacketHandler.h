class IPacketHandler;

#ifndef _IPACKETHANDLER_H
#define _IPACKETHANDLER_H

#include <string>

class IPacketHandler
{
public:
	virtual ~IPacketHandler() { }

	virtual void onAddObjectVehicle(int iEntity, unsigned char ucType, int iX, int iY, int iZ, int iUnk1, short unk2, short unk3, short unk4) { }
	virtual void onAnimation(int iEntity, unsigned char ucAnimation) { }
	virtual void onAttachEntity(int iEntity, int iVehicle) { }
	virtual void onBlockAction(int iX, short y, int iZ, unsigned char ucType, unsigned char ucPitch) { }
	virtual void onBlockChange(int iX, char cY, int iZ, unsigned char ucType, unsigned char ucMeta) { }
	virtual void onChat(const std::wstring &wstrMessage) { }
	virtual void onCollectItem(int iCollected, int iCollector) { }
	virtual void onCreativeInventoryAction(short iSlot, short iItem, unsigned char ucQty, short iUses) { }
	virtual void onDestroyEntity(int iEntity) { }
	virtual void onEntity(int iEntity) { }
	virtual void onEntityAction(int iEntity, unsigned char ucAction) { }
	virtual void onEntityEffect(int iEntity, unsigned char ucEffect, unsigned char ucAmplifier, short iDuration) { }
	virtual void onEntityLook(int iEntity, char cYaw, char cPitch) { }
	virtual void onEntityLookRelativeMove(int iEntity, char cX, char cY, char cZ, char cYaw, char cPitch) { }
	virtual void onEntityMetadata(int iEntity) { }
	virtual void onEntityRelativeMove(int iEntity, char cX, char cY, char cZ) { }
	virtual void onEntityStatus(int iEntity, unsigned char ucStatus) { }
	virtual void onEntityTeleport(int iEntity, int iX, int iY, int iZ, char cYaw, char cPitch) { }
	virtual void onEntityVelocity(int iEntity, short iVelX, short iVelY, short iVelZ) { }
	virtual void onEquipment(int iEntity, short iSlot, short iItem, short iUnk) { }
	virtual void onExperience(float fBar, short iLevel, short iTotal) { }
	virtual void onExperienceOrb(int iEntity, int iX, int iY, int iZ, short iCount) { }
	virtual void onExplosion(double dX, double dY, double dZ, float fRadius, int iCount) { }
	virtual void onHealthUpdate(short iHealth, short iFood, float fSaturation) { }
	virtual void onHoldingChange(short iSlot) { }
	virtual void onIncrementStatistic(int iStatistic, unsigned char ucAmount) { }
	virtual void onItemData(short iType, short iID, unsigned char ucLength) { }
	virtual void onPluginMessage(const std::wstring &wstrChannel, short iLength) { }
	virtual void onKick(const std::wstring &wstrMessage) { }
	virtual void onMapChunk(int iX, short y, int iZ, char cSX, char cSY, char cSZ, int iSize) { }
	virtual void onMobSpawn(int iEntity, unsigned char ucType, int iX, int iY, int iZ, char cYaw, char cPitch) { }
	virtual void onMultiBlockChange(int iX, int iZ, short iSize) { }
	virtual void onNamedEntitySpawn(int iEntity, const std::wstring &wstrName, int iX, int iY, int iZ, char cRot, char cPitch, short iItem) { }
	virtual void onNewInvalidState(unsigned char ucReason, unsigned char ucGamemode) { }
	virtual void onOpenWindow(unsigned char ucWindow, unsigned char ucType, const std::wstring &wstrTitle, unsigned char ucNumSlots) { }
	virtual void onPacket01(int iEntity, const std::wstring &wstrUnused, __int64 iSeed, const std::wstring &wstrLevelType, int iMode, unsigned char ucDimension, unsigned char ucDifficulty, unsigned char ucHeight, unsigned char ucMaxPlayers) { }
	virtual void onHandshake(const std::wstring &wstrHash) { }
	virtual void onPainting(int iEntity, const std::wstring &wstrTitle, int iX, int iY, int iZ, int iDirection) { }
	virtual void onPickupSpawn(int iEntity, short iItem, unsigned char ucCount, short iDamage, int iX, int iY, int iZ, char cRot, char cPitch, char cRoll) { }
	virtual void onKeepAlive(int iRandom) { }
	virtual void onPlayerBlockPlacement(int iX, char cY, int iZ, unsigned char ucDirection, short iBlockItem, unsigned char ucQty, short iDamage) { }
	virtual void onPlayerDigging(unsigned char ucStatus, int iX, char cY, int iZ, unsigned char ucFace) { }
	virtual void onPlayerListItem(const std::wstring &wstrName, bool bOnline, short iPing) { }
	virtual void onPlayerPositionLook(double dX, double dStance, double dY, double dZ, float fYaw, float fPitch, bool bGround) { }
	virtual void onPreChunk(int iX, int iZ, bool bInit) { }
	virtual void onRemoveEntityEffect(int iEntity, unsigned char ucEffect) { }
	virtual void onRespawn(unsigned char ucDimension, unsigned char ucDifficulty, bool bCreative, short iMaxHeight, __int64 iSeed, const std::wstring &wstrLevelType) { }
	virtual void onSoundEffect(int iEffect, int iX, char cY, int iZ, int iData) { }
	virtual void onSpawnPosition(int iX, int iY, int iZ) { }
	virtual void onThunderbolt(int iEntity, bool bUnk, int iX, int iY, int iZ) { }
	virtual void onTimeUpdate(__int64 iTime) { }
	virtual void onTransaction(unsigned char ucWindow, short iActionNumber, bool bAccepted) { }
	virtual void onUpdateSign(int iX, short iY, int iZ, const std::wstring &wstrLine1, const std::wstring &wstrLine2, const std::wstring &wstrLine3, const std::wstring &wstrLine4) { }
	virtual void onUseBed(int iEntity, bool bInBed, int iX, char cY, int iZ) { }
	virtual void onUseEntity(int iUser, int iTarget, bool bLeftClick) { }
	virtual void onWindowClose(unsigned char ucWindow) { }
	virtual void onWindowItems(unsigned char ucWindow, short iCount) { }
	virtual void onWindowProperty(unsigned char ucWindow, short iProperty, short iValue) { }
	virtual void onWindowSlot(unsigned char ucWindow, short iSlot, short iItem, unsigned char ucQty, short iUses) { }
};

#endif
