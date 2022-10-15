#include <iostream>
#include <mmdeviceapi.h>
#include <Functiondiscoverykeys_devpkey.h>

int main() {

    CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
    const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);

    // create multimedia device enumerator
    IMMDeviceEnumerator* pEnumerator = nullptr;
    HRESULT hr = CoCreateInstance(
            CLSID_MMDeviceEnumerator, NULL,
            CLSCTX_ALL, IID_IMMDeviceEnumerator,
            (void**)&pEnumerator);

    // get default audio capture device as endpoint
    IMMDevice* inputDevice = nullptr;
    hr = pEnumerator->GetDefaultAudioEndpoint(eCapture, eCommunications, &inputDevice);

    // get properties of the audio endpoint
    IPropertyStore* inputProperties = nullptr;
    hr = inputDevice->OpenPropertyStore(STGM_READ, &inputProperties);
    PROPVARIANT inputDeviceName;
    PropVariantInit(&inputDeviceName);
    // get the human-readable name of the device associated with the endpoint
    inputProperties->GetValue(PKEY_Device_FriendlyName, &inputDeviceName);
    printf("Input Audio endpoint name: %S\n", inputDeviceName.pwszVal);

    IMMDevice* outputDevice = nullptr;
    hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &outputDevice);

    // get properties of the audio endpoint
    IPropertyStore* outputProperties = nullptr;
    hr = outputDevice->OpenPropertyStore(STGM_READ, &outputProperties);
    PROPVARIANT outputDeviceName;
    PropVariantInit(&outputDeviceName);
    // get the human-readable name of the device associated with the endpoint
    outputProperties->GetValue(PKEY_Device_FriendlyName, &outputDeviceName);
    printf("Output Audio endpoint name: %S\n", outputDeviceName.pwszVal);




    CoUninitialize();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
