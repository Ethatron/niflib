/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysEmitterSpeedCtlr.h"
#include "../../include/obj/NiFloatData.h"

using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterSpeedCtlr::TYPE("NiPSysEmitterSpeedCtlr", &NI_P_SYS_EMITTER_SPEED_CTLR_PARENT::TypeConst() );

NiPSysEmitterSpeedCtlr::NiPSysEmitterSpeedCtlr() NI_P_SYS_EMITTER_SPEED_CTLR_CONSTRUCT {}

NiPSysEmitterSpeedCtlr::~NiPSysEmitterSpeedCtlr() {}

void NiPSysEmitterSpeedCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysEmitterSpeedCtlr::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysEmitterSpeedCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysEmitterSpeedCtlr::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysEmitterSpeedCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysEmitterSpeedCtlr::GetType() const {
	return TYPE;
};
