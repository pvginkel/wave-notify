/*
 * This file is part of Google Wave Notifier.
 *
 * Google Wave Notifier is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Google Wave Notifier is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Google Wave Notifier.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _INC_INCLUDE
#define _INC_INCLUDE

#pragma once

// Turn this on to test animations. These are automatically disabled with remote
// desktop and Wine when this is not enabled.
#define FORCE_ANIMATIONS	1

// Turn this on to have CCurl log to curl-log.txt.
#define CURL_VERBOSE_LOG	1

// Turn this on to route automatic update requests to a local server.
#define TEST_AUTOMATIC_UPDATE	1

// Turn this on to break every time a LOG(n) is called.
#define BREAK_ON_LOG		1

#define FILECOPY_BUFFER_SIZE	4096
#define MAX_LOG_DUMP		(128 * 1024)

#define USERAGENT 		L"Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.1.3) Gecko/20090824 Firefox/3.5.3 (.NET CLR 3.5.30729)"

#define CHM_FILENAME		L"wave-notify.chm"

#define GLOBAL_MUTEX		L"Local\\{A6A3BA8F-CDFF-48f6-B894-B869E59F2EA0}"

#if defined(_DEBUG) && defined(TEST_AUTOMATIC_UPDATE)
#define VERSION_LINK		L"http://ethan/wave-notify/htdocs/check_version.php"
#else
#define VERSION_LINK		L"http://wave-notify.sourceforge.net/check_version.php"
#endif

// All web request timeouts are registered here (in seconds).

#define WEB_TIMEOUT_LONG	(5 * 60)
#define WEB_TIMEOUT_SHORT	(1 * 60)
#define WEB_TIMEOUT_CHANNEL	(10 * 60)

// The interval in which the curl multi perform method is called (in milliseconds).

#define CURL_WAIT_TIMEOUT	1000

// User messages.

#define WM_NOTIFTICON			(WM_USER + 1)
#define WM_LINK_CLICKED			(WM_USER + 2)
#define WM_WAVE_CONNECTION_STATE	(WM_USER + 3)
#define WM_POPUP_OPENING		(WM_USER + 4)
#define WM_CURL_RESPONSE		(WM_USER + 5)
#define WM_VERSION_STATE		(WM_USER + 6)

#define ID_NOTIFYICON		1

typedef enum
{
	DT_ABOUT,
	DT_OPTIONS,
	DT_LOGIN
} DIALOG_TYPE;

typedef enum
{
	// Leave this at the bottom for the CTimer class.
	TIMER_MAX
} TIMER_ID;

// All timer intervals (in milliseconds).

#define TIMER_QUERY_INTERVAL		(2 * 60 * 1000)
#define TIMER_VERSION_INTERVAL		(60 * 60 * 1000)
#define TIMER_VERSION_INTERVAL_INITIAL	(10 * 60 * 1000)
#define TIMER_WORKING_INTERVAL		900

#define TIMER_IDLE_COMPLETE_INTERVAL	(4 * 1000)

#define TIMER_RECONNECT_INITIAL		(5 * 1000)
#define TIMER_RECONNECT_MAX		(60 * 1000)

#define TIMER_REREPORT_TIMEOUT		(3 * 60 * 1000)

// And the actual includes.

#include "resource.h"

// Framework includes.

#include "types.h"
#include "thread.h"
#include "utf8converter.h"
#include "gdi.h"
#include "lock.h"
#include "registry.h"
#include "log.h"
#include "support.h"
#include "delegate.h"
#include "event.h"
#include "mutex.h"
#include "windowhandle.h"
#include "curl.h"
#include "window.h"
#include "dialog.h"
#include "notifyicon.h"
#include "timer.h"
#include "popup.h"
#include "flyout.h"
#include "propertysheet.h"
#include "app.h"
#include "datetime.h"
#include "unzip.h"

// Application includes.

#include "version.h"
#include "settings.h"
#include "browser.h"
#include "wave.h"
#include "waverequest.h"
#include "waveresponse.h"
#include "unreadwave.h"
#include "notifierapp.h"
#include "logindialog.h"
#include "popups.h"
#include "flyouts.h"
#include "aboutdialog.h"
#include "optionssheet.h"
#include "migration.h"

#endif // _INC_INCLUDE
