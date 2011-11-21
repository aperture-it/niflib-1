/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIVISDATA_H_
#define _NIVISDATA_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "NiObject.h"
namespace Niflib {

class NiVisData;
typedef Ref<NiVisData> NiVisDataRef;

/*! Visibility data for a controller. */
class NiVisData : public NiObject {
public:
	/*! Constructor */
	NIFLIB_API NiVisData();

	/*! Destructor */
	NIFLIB_API virtual ~NiVisData();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*! Retrieves the visibility key data.
	 * \return A vector containing visibility data which specify boolean values over time.
	 * \sa NiBoolData::SetKeys, Key
	 */
	NIFLIB_API vector< Key<unsigned char> > GetKeys() const;

	/*! Sets the visibility key data.
	 * \param keys A vector containing new visibility data which will replace any existing data.
	 * \sa NiBoolData::GetKeys, Key
	 */
	NIFLIB_API void SetKeys( vector< Key<unsigned char> > const & keys );


	/*!
	 * This function will adjust the times in all the keys stored in this data
	 * object such that phase will equal 0 and frequency will equal one.  In
	 * other words, it will cause the key times to be in seconds starting from
	 * zero.
	 * \param[in] frequency The frequency to normalize to 1.0 for any keys
	 * stored in this object
	 * \param[in] phase The phase shift to remove from any keys stored in this
	 * object.
	 */
	NIFLIB_API virtual void NormalizeKeys( float phase, float frequency );


	//--END CUSTOM CODE--//
protected:
	/*! The number of visibility keys that follow. */
	mutable unsigned int numKeys;
	/*! The visibility keys. */
	vector<Key<byte > > keys;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//
//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
