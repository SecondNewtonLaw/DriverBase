#include <ntddk.h>
#include <wdf.h>

/*
 *  Note for future Maintainers/Developers:
 *      The reason we need to declare this as an extern C is to very literally
 *      tell the compiler to for gods sakes, to use C linkage when doing its linking magic!
 *      Else we won't compile. Leaving this if anyone questions the `extern "C"` part.
 *      - Dottik
 */

extern "C" DRIVER_INITIALIZE DriverEntry;

extern "C" NTSTATUS DriverEntry(
        _In_ PDRIVER_OBJECT pdriver_object,
        _In_ PUNICODE_STRING pregistry_path
) {
    DbgPrint("Hello, World!");
    return STATUS_SUCCESS;
}
