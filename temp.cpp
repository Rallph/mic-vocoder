#include <iostream>





dataFlow = eAll
dwStateMask = DEVICE_STATE_ACTIVE


HRESULT EnumAudioEndpoints(
  [in]  EDataFlow           dataFlow,
  [in]  DWORD               dwStateMask,
  [out] IMMDeviceCollection **ppDevices
);

//ppDevices is a pointer to pointer. may return NULL if EnumAudioEndpoints call fails
 cout << ppDevices;



const IID IID_IAudioClient  __uuidof(IAudioCaptureClient)
//The Activate method creates a COM object with the specified interface.
 iid = GetDefaultAudioEndpoint('below') //The interface identifier.
 dwClsCtx = CLSCTX_ALL
 pActivationParams = NULL

         HRESULT
         Activate(
             [in] REFIID iid,
             [in] DWORD dwClsCtx,
             [in] PROPVARIANT *pActivationParams,
             [out] void **ppInterface);
             //If the method succeeds, it returns S_OK

 // obtain a counted reference to the interface (input)
 dataFlow = eCapture
     role = eCommunications

         HRESULT
         GetDefaultAudioEndpoint(
             [in] EDataFlow dataFlow,
             [in] ERole role,
             [out] IMMDevice **ppEndpoint);
