/*
 * Copyright (c) 2000-2008, 2010-2020 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */
#include <SystemConfiguration/SystemConfiguration.h>
#include <SystemConfiguration/SCNetworkConfiguration.h>
#include <SystemConfiguration/SCDynamicStoreCopySpecific.h>
#include <SystemConfiguration/SCSchemaDefinitions.h>
#include <errno.h>
#include <string.h>
#include <mach/mach_error.h>
#include <servers/bootstrap.h>

static const struct sc_errmsg {
	int	status;
	char	*message;
} sc_errmsgs[] = {
	{ kSCStatusAccessError,		"Permission denied" },
	{ kSCStatusConnectionIgnore,	"Network connection information not available at this time" },
	{ kSCStatusConnectionNoService,	"Network service for connection not available" },
	{ kSCStatusFailed,		"Failed!" },
	{ kSCStatusInvalidArgument,	"Invalid argument" },
	{ kSCStatusKeyExists,		"Key already defined" },
	{ kSCStatusLocked,		"Lock already held" },
	{ kSCStatusMaxLink,		"Maximum link count exceeded" },
	{ kSCStatusNeedLock,		"Lock required for this operation" },
	{ kSCStatusNoStoreServer,	"Configuration daemon not (no longer) available" },
	{ kSCStatusNoStoreSession,	"Configuration daemon session not active" },
	{ kSCStatusNoConfigFile,	"Configuration file not found" },
	{ kSCStatusNoKey,		"No such key" },
	{ kSCStatusNoLink,		"No such link" },
	{ kSCStatusNoPrefsSession,	"Preference session not active" },
	{ kSCStatusNotifierActive,	"Notifier is currently active" },
	{ kSCStatusOK,			"Success!" },
	{ kSCStatusPrefsBusy,		"Preferences update currently in progress" },
	{ kSCStatusReachabilityUnknown,	"Network reachability cannot be determined" },
	{ kSCStatusStale,		"Write attempted on stale version of object" },
};

const char *SCErrorString(int status)
{
    for (size_t i = 0; i < sizeof(sc_errmsgs) / sizeof(sc_errmsgs[0]); ++i)
        if (sc_errmsgs[i].status == status)
            return sc_errmsgs[i].message;
    if (status > 0 && status <= ELAST)
        return strerror(status);
    if (status >= BOOTSTRAP_SUCCESS && status <= BOOTSTRAP_NO_MEMORY)
        return bootstrap_strerror(status);
    return mach_error_string(status);
}

CFStringRef SCDynamicStoreKeyCreateProxies(CFAllocatorRef allocator)
{
    return CFStringCreateWithFormat(allocator, NULL, CFSTR("%@/Network/Global/%@"),
        kSCDynamicStoreDomainState, kSCEntNetProxies);
}

CFRunLoopSourceRef SCDynamicStoreCreateRunLoopSource(CFAllocatorRef allocator,
    SCDynamicStoreRef store, CFIndex order)
{
    errno = ENOTSUP;
    return NULL;
}

CFStringRef SCNetworkInterfaceGetHardwareAddressString(SCNetworkInterfaceRef interface)
{
    return NULL;
}
