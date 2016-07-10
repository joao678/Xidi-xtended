/*****************************************************************************
 * XinputControllerDirectInput
 *      Hook and helper for older DirectInput games.
 *      Fixes issues associated with certain Xinput-based controllers.
 *****************************************************************************
 * Authored by Samuel Grossman
 * Copyright (c) 2016
 *****************************************************************************
 * Dinput8ImportApi.h
 *      Declarations related to importing the API from "dinput8.dll".
 *****************************************************************************/

#pragma once

#include "ApiDirectInput8.h"


namespace XinputControllerDirectInput
{
    // Enables access to the underlying system's "dinput8.dll" API.
    // Dynamically loads the library and holds pointers to all of its methods.
    // Methods are intended to be called directly rather than through an instance.
    class Dinput8ImportApi
    {
    private:
        // -------- CONSTRUCTION AND DESTRUCTION ----------------------------------- //

            // Default constructor. Should never be invoked.
        Dinput8ImportApi();

    public:
        // -------- CLASS METHODS -------------------------------------------------- //

            // Dynamically loads the "dinput8.dll" library and sets up all imported function calls.
            // Returns S_OK on success and E_FAIL on failure.
        static HRESULT Initialize(void);

        // Calls the imported function DirectInput8Create.
        static HRESULT ImportedDirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);

        // Calls the imported function DllRegisterServer.
        static HRESULT ImportedDllRegisterServer(void);

        // Calls the imported function DllUnregisterServer.
        static HRESULT ImportedDllUnregisterServer(void);

        // Calls the imported function DllCanUnloadNow.
        static HRESULT ImportedDllCanUnloadNow(void);

        // Calls the imported function DllGetClassObject.
        static HRESULT ImportedDllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv);
    };
}
