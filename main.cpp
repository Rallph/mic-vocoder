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
    IMMDevice* ppEndpoint = nullptr;
    hr = pEnumerator->GetDefaultAudioEndpoint(eCapture, eCommunications, &ppEndpoint);

    // get properties of the audio endpoint
    IPropertyStore* propertyStore = nullptr;
    hr = ppEndpoint->OpenPropertyStore(STGM_READ, &propertyStore);
    PROPVARIANT varName;
    PropVariantInit(&varName);
    // get the human-readable name of the device associated with the endpoint
    propertyStore->GetValue(PKEY_Device_FriendlyName, &varName);
    printf("Input Audio endpoint name: %S\n", varName.pwszVal);

    IMMDevice* ppEndpoint2 = nullptr;
    hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &ppEndpoint2);

    // get properties of the audio endpoint
    IPropertyStore* propertyStore2 = nullptr;
    hr = ppEndpoint2->OpenPropertyStore(STGM_READ, &propertyStore2);
    PROPVARIANT varName2;
    PropVariantInit(&varName2);
    // get the human-readable name of the device associated with the endpoint
    propertyStore2->GetValue(PKEY_Device_FriendlyName, &varName2);
    printf("Output Audio endpoint name: %S\n", varName2.pwszVal);




    CoUninitialize();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
