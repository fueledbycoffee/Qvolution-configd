#include <SystemConfiguration/SystemConfiguration.h>
#include <SystemConfiguration/SCNetworkConfiguration.h>
#include <SystemConfiguration/SCNetworkConnection.h>
#include <errno.h>
#include <string.h>
#include <mach/mach_error.h>
#include <servers/bootstrap.h>
#include "SCErrorMessages.h"

#ifdef DEBUG
#define STUB() printf("STUB %s\n", __func__)
#else
#define STUB() do {} while (0)
#endif

static const char* __ipv4_dummy = "ipv4";
const SCNetworkInterfaceRef kSCNetworkInterfaceIPv4 = (SCNetworkInterfaceRef)&__ipv4_dummy;
const CFStringRef kSCDynamicStoreUseSessionKeys = CFSTR("UseSessionKeys");

CFStringRef SCNetworkInterfaceGetInterfaceType(SCNetworkInterfaceRef interface)
{
    STUB();
    return NULL;
}

SCPreferencesRef SCPreferencesCreate(CFAllocatorRef allocator, CFStringRef name,
                                     CFStringRef prefsID)
{
    STUB();
    return NULL;
}

CFDictionaryRef SCPreferencesPathGetValue(SCPreferencesRef prefs, CFStringRef path)
{
    STUB();
    return NULL;
}

CFTypeID SCNetworkConnectionGetTypeID(void)
{
    STUB();
	return 0;
}

Boolean SCNetworkConnectionScheduleWithRunLoop(SCNetworkConnectionRef ref, CFRunLoopRef rl, CFStringRef rlMode)
{
    STUB();
	return 0;
}

Boolean SCNetworkConnectionUnscheduleFromRunLoop(SCNetworkConnectionRef ref, CFRunLoopRef rl, CFStringRef rlMode)
{
    STUB();
	return 0;
}

Boolean SCNetworkConnectionStop(SCNetworkConnectionRef ref, Boolean force)
{
    STUB();
	return 0;
}

Boolean SCNetworkConnectionStart(SCNetworkConnectionRef ref, CFDictionaryRef userOptions, Boolean linger)
{
    STUB();
	return 0;
}

Boolean
SCNetworkConnectionCopyUserPreferences		(
						CFDictionaryRef				  __nullable	selectionOptions,
						CFStringRef		__nonnull	* __nullable	serviceID,
						CFDictionaryRef		__nonnull	* __nullable	userOptions
						)			__OSX_AVAILABLE_STARTING(__MAC_10_3,__IPHONE_NA) {
    STUB();
	return 0;
}

SCNetworkConnectionRef SCNetworkConnectionCreateWithServiceID(CFAllocatorRef allocator, CFStringRef serviceID, SCNetworkConnectionCallBack cb, SCNetworkConnectionContext* ctxt)
{
    STUB();
	return NULL;
}

CFTypeID SCNetworkReachabilityGetTypeID(void)
{
    STUB();
	return 0;
}

Boolean SCNetworkReachabilityScheduleWithRunLoop(SCNetworkReachabilityRef ref, CFRunLoopRef rl, CFStringRef rlMode)
{
    STUB();
	return 0;
}

Boolean SCNetworkReachabilityUnscheduleFromRunLoop(SCNetworkReachabilityRef ref, CFRunLoopRef rl, CFStringRef rlMode)
{
    STUB();
	return 0;
}

Boolean SCNetworkReachabilitySetCallback(SCNetworkReachabilityRef target, SCNetworkReachabilityCallBack cb, SCNetworkReachabilityContext* ctxt)
{
    STUB();
	return 0;
}

Boolean SCNetworkReachabilityGetFlags(SCNetworkReachabilityRef target, SCNetworkReachabilityFlags* flags)
{
    STUB();
	return 0;
}

SCNetworkReachabilityRef SCNetworkReachabilityCreateWithName(CFAllocatorRef allocator, const char* nodeName)
{
    STUB();
	return NULL;
}

SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddressPair(CFAllocatorRef allocator, const struct sockaddr* localAddress, const struct sockaddr* remoteAddress)
{
    STUB();
	return NULL;
}

SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddress(CFAllocatorRef allocator, const struct sockaddr* remoteAddress)
{
    STUB();
	return NULL;
}

CFStringRef SCDynamicStoreKeyCreateNetworkGlobalEntity(CFAllocatorRef allocator, CFStringRef domain, CFStringRef entity)
{
	return CFStringCreateWithFormat(allocator, NULL, CFSTR("%@/%@/%@/%@"),
					domain, kSCCompNetwork, kSCCompGlobal, entity);
}

CFStringRef SCDynamicStoreKeyCreateProxies(CFAllocatorRef allocator)
{
	return SCDynamicStoreKeyCreateNetworkGlobalEntity(allocator,
							  kSCDynamicStoreDomainState,
							  kSCEntNetProxies);
}

const char *SCErrorString(int status)
{
	size_t i;

	for (i = 0; i < nSC_ERRMSGS; i++) {
		if (sc_errmsgs[i].status == status) {
			return sc_errmsgs[i].message;
		}
	}
	if ((status > 0) && (status <= ELAST)) {
		return strerror(status);
	}
	if ((status >= BOOTSTRAP_SUCCESS) && (status <= BOOTSTRAP_NO_MEMORY)) {
		return bootstrap_strerror(status);
	}
	return mach_error_string(status);
}

CFPropertyListRef SCDynamicStoreCopyValue(SCDynamicStoreRef store, CFStringRef key)
{
	STUB();
	return NULL;
}

SCDynamicStoreRef SCDynamicStoreCreate(CFAllocatorRef allocator, CFStringRef name, SCDynamicStoreCallBack callout, SCDynamicStoreContext *context)
{
	STUB();
	return NULL;
}

SCDynamicStoreRef __nullable SCDynamicStoreCreateWithOptions(CFAllocatorRef __nullable allocator, CFStringRef name, CFDictionaryRef __nullable storeOptions, SCDynamicStoreCallBack __nullable callout, SCDynamicStoreContext* __nullable context)
{
    STUB();
	return NULL;
};

CFStringRef SCDynamicStoreKeyCreate(CFAllocatorRef allocator, CFStringRef fmt, ...)
{
	STUB();
	return NULL;
}

Boolean SCDynamicStoreSetDispatchQueue(SCDynamicStoreRef store, dispatch_queue_t queue)
{
	STUB();
	return FALSE;
}

Boolean SCDynamicStoreSetNotificationKeys(SCDynamicStoreRef store, CFArrayRef __nullable keys, CFArrayRef __nullable patterns) {
	STUB();
	return FALSE;
}

CFStringRef SCDynamicStoreKeyCreateComputerName(CFAllocatorRef allocator) {
	STUB();
	return NULL;
};

Boolean SCPreferencesSetComputerName(SCPreferencesRef	prefs, CFStringRef __nullable	name, CFStringEncoding	nameEncoding) {
	STUB();
	return FALSE;
};

Boolean SCPreferencesSetLocalHostName(SCPreferencesRef	prefs, CFStringRef __nullable	name) {
	STUB();
	return FALSE;
};

CFStringRef SCDynamicStoreKeyCreateHostNames(CFAllocatorRef allocator) {
	STUB();
	return NULL;
};

CFStringRef SCDynamicStoreKeyCreateNetworkInterfaceEntity(CFAllocatorRef allocator, CFStringRef domain, CFStringRef ifname, CFStringRef entity) {
	STUB();
	return NULL;
};

SCNetworkInterfaceRef _SCNetworkInterfaceCreateWithBSDName(CFAllocatorRef allocator, CFStringRef bsdName)
{
	STUB();
	return (SCNetworkInterfaceRef)CFRetain(bsdName);
}

CFStringRef SCNetworkInterfaceGetBSDName(SCNetworkInterfaceRef interface)
{
	STUB();
	if (!interface) return NULL;
	if (CFGetTypeID((CFTypeRef)interface) == CFStringGetTypeID()) {
		return (CFStringRef)interface;
	}
	return CFSTR("en0");
}

CFStringRef SCNetworkInterfaceGetLocalizedDisplayName(SCNetworkInterfaceRef interface)
{
	STUB();
	return CFSTR("Ethernet");
}

SCNetworkInterfaceRef SCNetworkInterfaceGetInterface(SCNetworkInterfaceRef interface)
{
	STUB();
	return interface;
}

SCNetworkInterfaceRef SCNetworkServiceGetInterface(SCNetworkServiceRef service)
{
	STUB();
	return (SCNetworkInterfaceRef)CFSTR("en0");
}

CFArrayRef SCNetworkInterfaceCopyAll(void)
{
	STUB();
	CFStringRef en0 = CFSTR("en0");
	return CFArrayCreate(kCFAllocatorDefault, (const void**)&en0, 1, &kCFTypeArrayCallBacks);
}

CFStringRef SCDynamicStoreKeyCreateNetworkInterface(CFAllocatorRef allocator, CFStringRef domain)
{
	STUB();
	return CFStringCreateWithFormat(allocator, NULL, CFSTR("%@/%@"), domain, CFSTR("Network/Interface"));
}

CFStringRef SCDynamicStoreKeyCreateNetworkServiceEntity(CFAllocatorRef allocator, CFStringRef domain, CFStringRef serviceID, CFStringRef entity)
{
	STUB();
	return CFStringCreateWithFormat(allocator, NULL, CFSTR("%@/Network/Service/%@/%@"), domain, serviceID, entity);
}

SCNetworkConnectionRef SCNetworkConnectionCreateWithService(CFAllocatorRef allocator, CFStringRef serviceID, SCNetworkConnectionCallBack callout, SCNetworkConnectionContext* context)
{
	STUB();
	return NULL;
}

CFArrayRef SCNetworkConnectionCopyAvailableServices(void)
{
	STUB();
	return CFArrayCreate(kCFAllocatorDefault, NULL, 0, &kCFTypeArrayCallBacks);
}

CFDictionaryRef SCNetworkConnectionCopyExtendedStatus(SCNetworkConnectionRef connection)
{
	STUB();
	return CFDictionaryCreate(kCFAllocatorDefault, NULL, NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
}

CFDictionaryRef SCNetworkConnectionCopyStatistics(SCNetworkConnectionRef connection)
{
	STUB();
	return CFDictionaryCreate(kCFAllocatorDefault, NULL, NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
}

SCNetworkServiceRef SCNetworkConnectionGetService(SCNetworkConnectionRef connection)
{
	STUB();
	return NULL;
}

SCNetworkConnectionStatus SCNetworkConnectionGetStatus(SCNetworkConnectionRef connection)
{
	STUB();
	return 0; // kSCNetworkConnectionInvalid
}
