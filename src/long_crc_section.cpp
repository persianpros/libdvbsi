/*
 * $Id$
 *
 * Copyright (C) 2002-2005 Andreas Oberritter <obi@saftware.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * See the file 'COPYING' in the top level directory for details.
 */

#include <dvbsi++/byte_stream.h>
#include <dvbsi++/long_crc_section.h>

LongCrcSection::LongCrcSection(const uint8_t * const buffer) : LongSection(buffer)
{
	crc32 = UINT32(&buffer[sectionLength - 1]);
}

uint32_t LongCrcSection::getCrc32(void) const
{
	return crc32;
}

