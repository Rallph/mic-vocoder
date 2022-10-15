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



