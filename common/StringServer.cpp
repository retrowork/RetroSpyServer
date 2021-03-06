/*
    This file is part of RetroSpy Server.

    RetroSpy Server is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/
#define RSC_EXPORT 1 //Export the methods
#include "StringServer.h"

#include "RSString.h"

DLLAPI CStringServer::CStringServer(CLoop *loop) : CServer(loop) {}
DLLAPI CStringServer::~CStringServer() {}

void DLLAPI CStringServer::OnRead(uv_stream_t* stream, const char *data, ssize_t size)
{
	bool bC = true;
	char *buffer2 = NULL;

	buffer2 = (char*)data;
	buffer2[size] = 0;

	/* Check if the buffer is valid */
	if (!is_gs_valid(data))
		return;

	/* Loop to handle multiple request in the same buffer (it happends somehow) */
	while (bC)
	{
		char *find_str = NULL;
		char *the_string = NULL;

		int pos = 0;

		/* Check if the buffer is NULL */
		if (buffer2[0] == '\0')
			bC = false;
		else
		{
			/* Find the last part of a buffer */
			find_str = strstr(buffer2, "final\\");
			
			if (find_str == NULL)
				bC = false; /* Invalid request */
			else
			{
				char type[128];

				type[0] = 0;

				int rq_pos = 0;

				pos = find_str - buffer2;
			
				/* Allocate the string where we take the part our buffer */
				the_string = (char *)malloc(sizeof(char) * (pos+1));

				/* Copy the request into the string */
				strncpy_s(the_string, sizeof(char) * (pos + 1), buffer2, pos);

				/* Get the first request "x//" */
				rq_pos = get_gs_req(the_string, type, sizeof(type));
				if (rq_pos == -1)
				{
					/* Invalid request */
					Close(stream);
					bC = false;
				}
				else
				{
					/* Send it to the master handler */
					if (!HandleRequest(stream, type, &the_string[rq_pos], pos - rq_pos))
					{
						/* It wanted to close the socket, ok */
						Close(stream);
						bC = false;
					}
				}


				free(the_string); /* Free allocated memory */
			}
		
			/* If we can continue, continue to control the buffer */
			if (bC)
				buffer2 = &buffer2[pos + 6];
		}
	}
}

// Virtual functions
bool DLLAPI CStringServer::OnNewConnection(uv_stream_t*) { return true; }
bool DLLAPI CStringServer::HandleRequest(uv_stream_t *, const char *, const char *, int) { return true; }
