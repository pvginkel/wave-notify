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

#include "stdafx.h"
#include "include.h"

#define PROPERTY_INSTANCE	L"WAVENOTIFY_DIALOG_INSTANCE"

CDialog::CDialog(INT nResource)
{
	m_nResource = nResource;
}

CDialog::~CDialog()
{
	if (IsWindow())
	{
		RemoveProp(PROPERTY_INSTANCE);
	}

	CModelessDialogs::UnregisterDialog(this);

	SetHandle(NULL);
}

INT_PTR CDialog::DialogProc(UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	return FALSE;
}

INT_PTR CDialog::ShowDialog(CWindowHandle * lpParentWindow)
{
	return DialogBoxParam(
		CApp::Instance()->GetInstance(),
		MAKEINTRESOURCE(m_nResource),
		lpParentWindow == NULL ? NULL : lpParentWindow->GetHandle(),
		CDialog::DialogProcCallback,
		(LPARAM)this);
}

void CDialog::Create(INT nType, CWindowHandle * lpParentWindow)
{
	HWND hWnd = CreateDialogParam(
		CApp::Instance()->GetInstance(),
		MAKEINTRESOURCE(m_nResource),
		lpParentWindow == NULL ? NULL : lpParentWindow->GetHandle(),
		CDialog::DialogProcCallback,
		(LPARAM)this);

	ASSERT(hWnd != NULL);

	SetHandle(hWnd);

	CModelessDialogs::RegisterDialog(nType, this);

	BeforeShow();

	ShowWindow(SW_SHOW);
}

INT_PTR CALLBACK CDialog::DialogProcCallback(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	CDialog * lpDialog;

	if (uMessage == WM_INITDIALOG)
	{
		lpDialog = (CDialog *)lParam;
		
		ASSERT(lpDialog != NULL);

		::SetProp(hWnd,	PROPERTY_INSTANCE, (HANDLE)lpDialog);

		lpDialog->SetHandle(hWnd);
	}
	else
	{
		lpDialog = (CDialog *)::GetProp(hWnd, PROPERTY_INSTANCE);
	}

	if (lpDialog != NULL)
	{
		lpDialog->AddRef();

		INT_PTR nResult = lpDialog->DialogProc(uMessage, wParam, lParam);

		if (uMessage == WM_DESTROY)
		{
			lpDialog->Release();
		}

		lpDialog->Release();

		return nResult;
	}
	else
	{
		return FALSE;
	}
}
