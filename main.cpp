#include <iostream>
#include <mmdeviceapi.h>
#include <Functiondiscoverykeys_devpkey.h>

int main() {

    CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
    const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);

    IMMDeviceEnumerator* pEnumerator = nullptr;

    HRESULT hr = CoCreateInstance(
            CLSID_MMDeviceEnumerator, NULL,
            CLSCTX_ALL, IID_IMMDeviceEnumerator,
            (void**)&pEnumerator);

    IMMDevice* ppEndpoint = nullptr;

    hr = pEnumerator->GetDefaultAudioEndpoint(eCapture, eCommunications, &ppEndpoint);

    IPropertyStore* propertyStore = nullptr;

    hr = ppEndpoint->OpenPropertyStore(STGM_READ, &propertyStore);

    PROPVARIANT varName;
    PropVariantInit(&varName);

    propertyStore->GetValue(PKEY_Device_FriendlyName, &varName);

    printf("Audio endpoint name: %S\n", varName.pwszVal);


    CoUninitialize();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
