/***********************************************************************
	Copyright (c) 2017, The OpenBRAS project authors. All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are
	met:

	  * Redistributions of source code must retain the above copyright
		notice, this list of conditions and the following disclaimer.

	  * Redistributions in binary form must reproduce the above copyright
		notice, this list of conditions and the following disclaimer in
		the documentation and/or other materials provided with the
		distribution.

	  * Neither the name of OpenBRAS nor the names of its contributors may
		be used to endorse or promote products derived from this software
		without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**********************************************************************/
#include "CDHCPKickUserEventHndl.h"
#include "CDHCPServer.h"
#include "BaseDefines.h"

CDHCPKickUserEventHndl::CDHCPKickUserEventHndl(CDHCPServer &server, const Sm_Kick_User* kickInfo)
    : m_server(server)
{
    ACE_DEBUG ((LM_DEBUG,"CDHCPKickUserEventHndl::CDHCPKickUserEventHndl\n")); 
    ::memcpy(&m_kickInfo, kickInfo, sizeof(*kickInfo));
}

CDHCPKickUserEventHndl::~CDHCPKickUserEventHndl()
{
    ACE_DEBUG ((LM_DEBUG,"CDHCPKickUserEventHndl::~CDHCPKickUserEventHndl\n")); 
}

void CDHCPKickUserEventHndl::Fire()
{
    ACE_DEBUG ((LM_DEBUG, "CDHCPKickUserEventHndl::Fire\n")); 

    WORD64 sessionId = m_server.GetSessionID(&m_kickInfo);
    
    int retVal = m_server.RemoveSession(sessionId);
    if (retVal != 0)
    {
        ACE_DEBUG ((LM_ERROR, "DHCP server failed to remove session with id %#x.\n", sessionId));
    }
}


