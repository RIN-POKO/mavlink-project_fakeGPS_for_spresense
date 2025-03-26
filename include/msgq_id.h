/* This file is generated automatically. */
/****************************************************************************
 * msgq_id.h
 *
 *   Copyright 2024 Sony Semiconductor Solutions Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Sony Semiconductor Solutions Corporation nor
 *    the names of its contributors may be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef MSGQ_ID_H_INCLUDED
#define MSGQ_ID_H_INCLUDED

/* Message area buffer */

extern uint8_t AutoGenMesgBuff[];

/* Message area size: 1204 bytes */

#define MSGQ_TOP_DRM (uint32_t)AutoGenMesgBuff
#define MSGQ_END_DRM (uint32_t)AutoGenMesgBuff + 0x4b4

/* Message area fill value after message poped */

#define MSG_FILL_VALUE_AFTER_POP 0x0

/* Message parameter type match check */

#define MSG_PARAM_TYPE_MATCH_CHECK false

/* Message queue pool IDs */

#define MSGQ_NULL 0
#define MSGQ_MAVLINK 1
#define MSGQ_GPS 2
#define NUM_MSGQ_POOLS 3

/* User defined constants */

/************************************************************************/
#define MSGQ_MAVLINK_QUE_BLOCK_DRM 0x44
#define MSGQ_MAVLINK_N_QUE_DRM 0xcc
#define MSGQ_MAVLINK_N_SIZE 100
#define MSGQ_MAVLINK_N_NUM 5
#define MSGQ_MAVLINK_H_QUE_DRM 0xffffffff
#define MSGQ_MAVLINK_H_SIZE 0
#define MSGQ_MAVLINK_H_NUM 0
/************************************************************************/
#define MSGQ_GPS_QUE_BLOCK_DRM 0x88
#define MSGQ_GPS_N_QUE_DRM 0x2c0
#define MSGQ_GPS_N_SIZE 100
#define MSGQ_GPS_N_NUM 5
#define MSGQ_GPS_H_QUE_DRM 0xffffffff
#define MSGQ_GPS_H_SIZE 0
#define MSGQ_GPS_H_NUM 0

#endif /* MSGQ_ID_H_INCLUDED */
