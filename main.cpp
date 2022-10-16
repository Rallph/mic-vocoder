#include <iostream>
#include <mmdeviceapi.h>
#include <audioclient.h>
#include <Functiondiscoverykeys_devpkey.h>

int main() {
    
//Initialization------------------------------------------------------------
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
    const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
    const IID IID_IAudioClient           = __uuidof(IAudioClient);
    const IID IID_IAudioRenderClient = __uuidof(IAudioRenderClient);
    const IID IID_IAudioCaptureClient = __uuidof(IAudioCaptureClient);
    // create multimedia device enumerator
    IMMDeviceEnumerator* pEnumerator = nullptr;
    HRESULT hr = CoCreateInstance(
            CLSID_MMDeviceEnumerator, NULL,
            CLSCTX_ALL, IID_IMMDeviceEnumerator,
            (void**)&pEnumerator);

//Device Properties------------------------------------------------------------
    //INPUT
    // get default audio capture device as endpoint
    IMMDevice* inputDevice = nullptr;
    hr = pEnumerator->GetDefaultAudioEndpoint(eCapture, eCommunications, &inputDevice);
    // get properties of the audio endpoint (input)
    IPropertyStore* inputProperties = nullptr;
    hr = inputDevice->OpenPropertyStore(STGM_READ, &inputProperties);
    PROPVARIANT inputDeviceName;
    PropVariantInit(&inputDeviceName);
    // get the human-readable name of the device associated with the endpoint (input)
    inputProperties->GetValue(PKEY_Device_FriendlyName, &inputDeviceName);
    printf("Input Audio endpoint name: %S\n", inputDeviceName.pwszVal);

    //OUTPUT
    IMMDevice* outputDevice = nullptr;
    hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &outputDevice);
    // get properties of the audio endpoint (output)
    IPropertyStore* outputProperties = nullptr;
    hr = outputDevice->OpenPropertyStore(STGM_READ, &outputProperties);
    PROPVARIANT outputDeviceName;
    PropVariantInit(&outputDeviceName);
    // get the human-readable name of the device associated with the endpoint (output)
    outputProperties->GetValue(PKEY_Device_FriendlyName, &outputDeviceName);
    printf("Output Audio endpoint name: %S\n", outputDeviceName.pwszVal);

//Activate Devices------------------------------------------------------------
    // activate output client interface
    IAudioClient* outputAudioClient = nullptr;
    outputDevice->Activate(IID_IAudioClient, CLSCTX_ALL, nullptr, reinterpret_cast<void **>(&outputAudioClient));
    IAudioRenderClient* renderClient = nullptr;
    outputAudioClient->GetService(IID_IAudioRenderClient, reinterpret_cast<void **>(&renderClient));
    // activate input client interface
    IAudioClient* inputAudioClient = nullptr;
    inputDevice->Activate(IID_IAudioClient, CLSCTX_ALL, nullptr, reinterpret_cast<void **>(&inputAudioClient));

    IAudioCaptureClient* captureClient = nullptr;
    inputAudioClient->GetService(IID_IAudioCaptureClient, reinterpret_cast<void **>(&captureClient));


//tbd ------------------------------------------------------------







//Close-out------------------------------------------------------------
    CoUninitialize();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
