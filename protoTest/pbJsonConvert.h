// File:        convert.h
// Description: This imply file for protobuf message and json interconversion
// Notes:       ---
// Author:      cuiguanghui
// Revision:    2018-11-23 by cuiguanghui

#pragma once

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/reader.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class pbJsonConvert
{
public:
    using ProtobufMsg = ::google::protobuf::Message;
    using ProtobufReflection = ::google::protobuf::Reflection;
    using ProtobufFieldDescriptor = ::google::protobuf::FieldDescriptor;
    using ProtobufDescriptor = ::google::protobuf::Descriptor;

public:
    bool Json2Pb(const rapidjson::Value& json, ProtobufMsg& message, bool str2enum = false);
    void Pb2Json(const ProtobufMsg& message, rapidjson::Value& json, rapidjson::Document& doc, bool enum2str = false);

protected:
    bool Json2RepeatedPb(const rapidjson::Value& json, ProtobufMsg& message, const ProtobufFieldDescriptor* field,
                                     const ProtobufReflection* reflection, bool str2enum);
    void RepeatedPb2Json(const ProtobufMsg& message, const ProtobufFieldDescriptor* field,
                                     const ProtobufReflection* reflection, rapidjson::Value& json, rapidjson::Document& doc, bool enum2str);
private:
	bool _isRoot=true;
};
