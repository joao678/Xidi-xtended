/*****************************************************************************
 * Xidi
 *   DirectInput interface for XInput controllers.
 *****************************************************************************
 * Authored by Samuel Grossman
 * Copyright (c) 2016-2021
 *************************************************************************//**
 * @file ApiXidi.h
 *   Declaration of an internal API for communication between Xidi modules.
 *****************************************************************************/

#pragma once

#include <cstddef>
#include <map>
#include <set>
#include <string_view>


// -------- MACROS --------------------------------------------------------- //

/// Associates an API interface class with its enumerator.
#define XIDI_API_INTERFACE_FOR(apiClass)    protected: inline I##apiClass(void) : IXidi(EClass::##apiClass) {}


namespace Xidi
{
    namespace Api
    {
        /// Enumerates all available API classes.
        /// Once created and released an API class cannot be modified. However, it can be extended through inheritance.
        /// Order of enumerators also cannot be changed.
        enum class EClass : unsigned int
        {
            ImportFunctions                                                 ///< See #IImportFunctions.
        };

        /// Xidi API base class. All API classes must inherit from this class.
        /// Must not define any data members or virtual methods.
        class IXidi
        {
        protected:
            // -------- CONSTRUCTION AND DESTRUCTION --------------------------- //

            /// Initialization constructor.
            /// Typically, concrete API implementations are singleton objects.
            /// When constructed they are expected to be associated with a particular API class enumerator as the API implementation provider object.
            /// @param [in] apiClass API class enumerator to associate with the object.
            IXidi(EClass apiClass);
        };
        
        /// Xidi API class for manipulating the functions Xidi imports from the system.
        class IImportFunctions : public IXidi
        {
            XIDI_API_INTERFACE_FOR(ImportFunctions);

        public:
            // -------- ABSTRACT INSTANCE METHODS ------------------------------ //

            /// Retrieves a list of names of imported functions whose import addresses can be replaced.
            /// Xidi imports some of its functionality from the system, but in some cases these import locations need to be changed.
            /// Function names returned in the read-only view are also exported by Xidi, and their addresses can be retrieved using `GetProcAddress` directly.
            /// @return Read-only reference to a set of function names.
            virtual const std::set<std::wstring_view>& GetReplaceable(void) const = 0;

            /// Submits to Xidi a set of replacement import function addresses as a map from name to address.
            /// Xidi imports some of its functionality from the system, but in some cases these import locations need to be changed.
            /// Valid function names are obtained using the #GetReplaceableImportFunctions API function.
            /// @param [in] importFunctionTable Read-only reference to a map from function name to replcaement import address.
            /// @return Number of functions whose addresses were successfully replaced using the provided import function table.
            virtual size_t SetReplaceable(const std::map<std::wstring_view, const void*>& importFunctionTable) = 0;
        };

        /// Pointer type definition for the XidiApiGetInterface exported function.
        typedef IXidi*(*TGetInterfaceFunc)(EClass apiClass);
    }    
}