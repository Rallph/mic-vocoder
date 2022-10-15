#include <iostream>
#include <mmdeviceapi.h>

int main() {

    CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
    const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);

    IMMDeviceEnumerator* pEnumerator = nullptr;

    HRESULT hr = CoCreateInstance(
            CLSID_MMDeviceEnumerator, NULL,
            CLSCTX_ALL, IID_IMMDeviceEnumerator,
            (void**)&pEnumerator);

    IMMDeviceCollection* ppDevices = nullptr;

    hr = pEnumerator->EnumAudioEndpoints(eAll, DEVICE_STATE_ACTIVE, &ppDevices);



    CoUninitialize();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
