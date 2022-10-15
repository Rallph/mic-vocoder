#include <iostream>



//hr = CoCreateInsatanceEx(NULL);



dataFlow = eRender //switch to eCapture for input
role = eMultimedia //switch to eCommunications for that
HRESULT GetDefaultAudioEndpoint(
  [in]  EDataFlow dataFlow,
  [in]  ERole     role,
  [out] IMMDevice **ppEndpoint
);

IMMDevice currentOut = GetDefaultAudioEndpoint(dataFlow, role)







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





DWORD  waveInMessage(
   UINT      uDeviceID,
   UINT      uMsg,
   DWORD_PTR dwParam1,
   DWORD_PTR dwParam2
);


----------------------------


    CoCreateInsatanceEx???
• CoCreateInstance function to create a device enumerator.  is an object with an IMMDeviceEnumerator interface
•  IMMDeviceEnumerator::EnumAudioEndpoints method to create a collection of endpoint objects.
	◦ (list of endpoint object)
	◦ IMMDeviceEnumerator::GetDefaultAudioEndpoint
		‣ IMMDevice **ppEndpoint
A device collection is an object with an IMMDeviceCollection interface. Each item in a device collection is an endpoint object with at least the following two interfaces:

   -  An IMMDevice interface. A client obtains a reference to the IMMDevice interface of an endpoint object in a device collection by calling the IMMDeviceCollection::Item method.
   -  An IMMEndpoint interface. A client obtains a reference to the IMMEndpoint interface of an endpoint object by calling the IMMDevice::QueryInterface method.

• After selecting a suitable device, the client can call the IMMDevice::Activate method to activate the device-specific interfaces in WASAPI 
	◦ REFIID      iid = IID_IAudioEndpointVolume
		‣ const IID IID_IAudioClient  __uuidof(IAudioCaptureClient)
	◦ DWORD dwClsCtx = CLSCTX_ALL, 
	◦ PROPVARIANT *pActivationParams = 


IAudioEndpointVolume::SetChannelVolumeLevel
345 dev on cloud,