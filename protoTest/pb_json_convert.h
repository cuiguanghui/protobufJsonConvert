// File:        pb_json_convert.h
// Description: This imply file for protobuf message and json interconversion
// Notes:       ---
// Author:      cuiguanghui <guanghui.cui@freemud.cn>
// Revision:    2018-11-23 by cuiguanghui

#pragma once

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/reader.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using protobuf_msg = ::google::protobuf::Message;
using protobuf_reflection = ::google::protobuf::Reflection;
using protobuf_field_descriptor = ::google::protobuf::FieldDescriptor;

class converter
{
public:
	/* 功能:json转protobuf
	*  参数:[1]json数据 [2]protobuf数据
	*  返回:是否转换成功
	* */
	static bool json_to_pb(const std::string& json, protobuf_msg& message);

	/* 功能:protobuf转json
	*  参数:[1]protobuf数据 [2]json数据
	*  返回:NULL
	* */
	static void pb_to_json(const protobuf_msg& message, std::string& json);

private:
	static bool _json_to_pb(const rapidjson::Value& json, protobuf_msg& message, bool str2enum = false);
	static void _pb_to_json(const protobuf_msg& message, rapidjson::Value& json, rapidjson::Document& doc, bool isRoot = false, bool enum2str = false);

	static bool _json_to_repeated_pb(const rapidjson::Value& json, protobuf_msg& message, const protobuf_field_descriptor* field,
                                     const protobuf_reflection* reflection, bool str2enum);
	static void _repeated_pb_to_json(const protobuf_msg& message, const protobuf_field_descriptor* field,
                                     const protobuf_reflection* reflection, rapidjson::Value& json, rapidjson::Document& doc, bool enum2str);
};
