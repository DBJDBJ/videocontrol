/*
-----------------------------------------------------------------------------
(c) 2000 by DBJSystems LTD
-----------------------------------------------------------------------------
  Here we define category ID for dbjsystems made com stuff.
  When we want to use it we have to include this file.

  Then have this map in your interface implementation:

  public:
  BEGIN_CATEGORY_MAP(Cdbjvideo)
    IMPLEMENTED_CATEGORY(dbjsys::com::CATID_DBJSystems()) 
  END_CATEGORY_MAP()

  For all of this to work you have to put the following snippet before the 
  last '}' in your rgs file:

  	NoRemove 'Component Categories'
	{
		{1CE79154-2763-4328-85D4-455E578699B8}
		{
			val 409 = s 'DBJSystems LTD COM Artefacts'
		}
	}

  22.08.2000 DBJ Created
-----------------------------------------------------------------------------
  $Author: Admin $
  $Revision: 1 $
*/
#pragma once

namespace dbjsys {
    namespace com {

        interface
            __declspec(uuid("1CE79154-2763-4328-85D4-455E578699B8")) 
                 dbjsystems_category_guid_holder {} ;

    inline const struct _GUID & CATID_DBJSystems() 
    {
        return __uuidof( dbjsystems_category_guid_holder ) ;
    }

    } //    namespace com 
} // namespace dbjsys 

