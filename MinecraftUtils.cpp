#include "StdInc.h"
#include "MinecraftUtils.h"

bool MinecraftUtils::isEnchantable(int iID)
{
	switch (iID)
	{
	case 0x103: // Flint and steel
	case 0x105: // Bow
	case 0x15A: // Fishing rod
	case 0x167: // Shears

	// Wood tools
	case 0x10C:
	case 0x10D:
	case 0x10E:
	case 0x10F:
	case 0x122:

	// Stone tools
	case 0x110:
	case 0x111:
	case 0x112:
	case 0x113:
	case 0x123:

	// Iron tools
	case 0x10B:
	case 0x100:
	case 0x101:
	case 0x102:
	case 0x124:

	// Diamond tools
	case 0x114:
	case 0x115:
	case 0x116:
	case 0x117:
	case 0x125:

	// Gold tools
	case 0x11B:
	case 0x11C:
	case 0x11D:
	case 0x11E:
	case 0x126:

	// Leather armour
	case 0x12A:
	case 0x12B:
	case 0x12C:
	case 0x12D:

	// Chain armour
	case 0x12E:
	case 0x12F:
	case 0x130:
	case 0x131:

	// Iron armour
	case 0x132:
	case 0x133:
	case 0x134:
	case 0x135:

	// Diamond armour
	case 0x136:
	case 0x137:
	case 0x138:
	case 0x139:

	// Gold armour
	case 0x13A:
	case 0x13B:
	case 0x13C:
	case 0x14D:

		return true;
	}

	return false;
}
