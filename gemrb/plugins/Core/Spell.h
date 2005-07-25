/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2003 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header: /data/gemrb/cvs2svn/gemrb/gemrb/gemrb/plugins/Core/Spell.h,v 1.12 2005/07/25 16:46:52 avenger_teambg Exp $
 *
 */

#ifndef SPELL_H
#define SPELL_H

#include <vector>
#include "../../includes/ie_types.h"

#include "AnimationMgr.h"
#include "Effect.h"
#include "EffectQueue.h"

#ifdef WIN32

#ifdef GEM_BUILD_DLL
#define GEM_EXPORT __declspec(dllexport)
#else
#define GEM_EXPORT __declspec(dllimport)
#endif

#else
#define GEM_EXPORT
#endif

//values for Spell usability Flags

#define SF_HOSTILE 0x4
#define SF_NO_LOS  0x8
#define SF_NOT_INDOORS 0x20
#define SF_HLA 0x40
#define SF_TRIGGER 0x80
//this is a relocated bit (used in iwd2 as 0x40)
#define SF_NOT_IN_COMBAT 0x100
#define SF_SIMPLIFIED_DURATION   0x400

class GEM_EXPORT SPLExtHeader {
public:
	SPLExtHeader();
	~SPLExtHeader();

	ieByte SpellForm;
	ieByte unknown1;
	ieByte Location;
	ieByte unknown2;
	ieResRef MemorisedIcon;
	ieByte Target;
	ieByte TargetNumber;
	ieWord Range;
	ieWord RequiredLevel;
	ieDword CastingTime;
	ieWord DiceSides;
	ieWord DiceThrown;
	ieWord DamageBonus;
	ieWord DamageType;
	ieWord FeatureCount;
	ieWord FeatureOffset;
	ieWord Charges;
	ieWord ChargeDepletion;
	ieWord Projectile;
	Effect* features;
};


class GEM_EXPORT Spell {
public:
	Spell();
	~Spell();

	SPLExtHeader *ext_headers;
	Effect* casting_features;
	ieResRef Name; //the resref of the spell itself!

	ieStrRef SpellName;
	ieStrRef SpellNameIdentified;
	ieResRef CompletionSound;
	ieDword Flags;
	ieWord SpellType;
	ieWord ExclusionSchool;
	ieWord PriestType;
	ieWord CastingGraphics;
	ieByte unknown1;
	ieWord PrimaryType;
	ieByte SecondaryType;
	ieDword unknown2;
	ieDword unknown3;
	ieDword unknown4;
	ieDword SpellLevel;
	ieWord unknown5;
	ieResRef SpellbookIcon;
	ieWord unknown6;
	ieDword unknown7;
	ieDword unknown8;
	ieDword unknown9;
	ieStrRef SpellDesc;
	ieStrRef SpellDescIdentified;
	ieDword unknown10;
	ieDword unknown11;
	ieDword unknown12;
	ieDword ExtHeaderOffset;
	ieWord ExtHeaderCount;
	ieDword FeatureBlockOffset;
	ieWord CastingFeatureOffset;
	ieWord CastingFeatureCount;

	// IWD2 only
	char unknown13[16];

//	AnimationMgr* SpellIconBAM;
public:
	//-1 will return the cfb
	EffectQueue *GetEffectQueue(int index);
	EffectQueue *GetEffectBlock(int wanted_level);
};

#endif  // ! SPELL_H
