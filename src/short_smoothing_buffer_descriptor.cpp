/*
 * $Id$
 *
 * Copyright (C) 2008 Marcel Siegert <mws@twisted-brains.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * See the file 'COPYING' in the top level directory for details.
 */
#include "dvbsi++/byte_stream.h"
#include "dvbsi++/short_smoothing_buffer_descriptor.h"

ShortSmoothingBufferDescriptor::ShortSmoothingBufferDescriptor(const uint8_t * const buffer) : Descriptor(buffer), privateDataBytes(descriptorLength > 0 ? descriptorLength-1 : 0)
{
	if (descriptorLength > 1) {
		sbSize = (buffer[2] >> 6) & 0x03;
		sbLeakRate = buffer[2] & 0x4f;
	}
	else {
		sbSize = 0;
		sbLeakRate = 0;
	}

	memcpy(&privateDataBytes[0], &buffer[3], privateDataBytes.size());
}

ShortSmoothingBufferDescriptor::~ShortSmoothingBufferDescriptor()
{
}

uint8_t ShortSmoothingBufferDescriptor::getSbSize(void) const
{
	return sbSize;
}

uint8_t ShortSmoothingBufferDescriptor::getSbLeakRate(void) const
{
	return sbLeakRate;
}

const PrivateDataByteVector *ShortSmoothingBufferDescriptor::getPrivateDataBytes(void) const
{
	return &privateDataBytes;
}
