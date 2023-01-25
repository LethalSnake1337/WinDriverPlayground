#include <ntddk.h>

#define DRIVER_DEV_DOS = L"\\\\DosDevice\\DriverDev"

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);

	UNICODE_STRING devName = RTL_CONSTANT_STRING(L"\\Device\\DriverDev");
	PDEVICE_OBJECT DeviceObject;
	IoCreateDevice(
		DriverObject,
		0,
		&devName,
		FILE_DEVICE_UNKNOWN,
		0,
		FALSE,
		&DeviceObject);

	return STATUS_SUCCESS;
}