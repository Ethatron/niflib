/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/Footer.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Constructor
Footer::Footer() : numRoots((uint)0) {};

//Destructor
Footer::~Footer() {};

void Footer::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	if ( version >= 0x0303000D ) {
		NifStream( numRoots, in, version );
		roots.resize(numRoots);
		for (uint i2 = 0; i2 < roots.size(); i2++) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
}

void Footer::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	numRoots = uint(roots.size());
	if ( version >= 0x0303000D ) {
		NifStream( numRoots, out, version );
		for (uint i2 = 0; i2 < roots.size(); i2++) {
			if ( roots[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(roots[i2]) )->second, out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
}

string Footer::asString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	numRoots = uint(roots.size());
	out << "  Num Roots:  " << numRoots << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < roots.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Roots[" << i1 << "]:  " << roots[i1] << endl;
		array_output_count++;
	};
	return out.str();
}