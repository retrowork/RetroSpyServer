/*
    This file is part of RetroSpy Server.

    RetroSpy Server is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RetroSpy Server is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with RetroSpy Server.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef RETROSPYCOMMON_HELPER_H
#define RETROSPYCOMMON_HELPER_H

#include "Defines.h"

// Base64
DLLAPI void B64Decode(const char *input, char *output, int inlen, int * outlen, int encodingType);
DLLAPI void B64Encode(const char *input, char *output, int inlen, int encodingType);
DLLAPI int B64DecodeLen(const char *input, int encodingType);

// Random
DLLAPI void Util_RandSeed(unsigned long seed);
DLLAPI int Util_RandInt(int low, int high);

// Helper
DLLAPI void gs_pass_decode(const char *buf, char *out);

#endif