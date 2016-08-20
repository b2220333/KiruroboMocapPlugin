﻿// Copyright (c) 2015-2016 Kirurobo

#pragma once

#include "PacketParser.h"

/**
* AXIS Neuron BVH protocol reader
*/
class PacketParserNeuron : public PacketParser
{
public:
	PacketParserNeuron();
	~PacketParserNeuron();

	const static uint8 BoneCount;			/* モーキャプで受信されるボーン数 */
	const static uint8 BoneIndices[];		/* モーキャプで受信される順番のボーン */
											//const static uint8 ParentBones [];	/* モーキャプで受信されるボーンの親ボーン */
	const static uint8 EmptyBoneIndices[];	/* モーキャプでは受信されず、常に空とすべきボーン */

protected:
	int32 SampleCount;
	bool hasDisplacement;
	bool hasReference;

	void Initialize();

	/*  関節一つ分を解析 */
	void ProcessSegment(const uint8* data, const int32 segmentNo, const int32 index, UMocapPose* pose);

	FVector GetPosition(const uint8* data, const int32 index);

	FQuat GetQuaternion(const uint8* data, const int32 index);

	/*  UDPパケットのヘッダを確認 */
	bool CheckHeader(const uint8* data, const int32 length);

public:

	/*  受信データ1つ分を解析 */
	bool Read(const uint8* data, const int32 length, UMocapPose* pose);
};
