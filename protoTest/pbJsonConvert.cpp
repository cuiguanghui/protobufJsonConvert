// File:        convert.cpp
// Description: This imply file for protobuf message and json interconversion
// Notes:       ---
// Author:      cuiguanghui 
// Revision:    2018-11-23 by cuiguanghui

#include "pbJsonConvert.h"

bool pbJsonConvert::Json2Pb(const rapidjson::Value& json, ProtobufMsg& message, bool str2enum) {
    auto descriptor = message.GetDescriptor();
    auto reflection = message.GetReflection();
    if (nullptr == descriptor || nullptr == reflection) return false;

    auto count = descriptor->field_count();
    for (auto i = 0; i < count; ++i) {
		const auto field = descriptor->field(i);
		if (nullptr == field) continue;

		if(!json.HasMember(field->name().data())) continue;

		auto& value = json.FindMember(field->name().data());

		if (field->is_repeated()) {
			if (!value->value.IsArray()) {
				return false;
			}
			else {
				Json2RepeatedPb(value->value, message, field, reflection, str2enum);
				continue;
			}
		}

        switch (field->type()) {
            case ProtobufFieldDescriptor::TYPE_BOOL: {
                if (value->value.IsBool())
                    reflection->SetBool(&message, field, value->value.GetBool());
                else if (value->value.IsInt())
                    reflection->SetBool(&message, field, value->value.GetInt() != 0);
                else if (value->value.IsString()) {
                    if (value->value.GetString() == "true")
                        reflection->SetBool(&message, field, true);
                    else if (value->value.GetString() == "false")
                        reflection->SetBool(&message, field, false);
                }
            } break;

            case ProtobufFieldDescriptor::TYPE_ENUM: {
                auto const* pedesc = field->enum_type();
                const ::google::protobuf::EnumValueDescriptor* pevdesc = nullptr;

                if (str2enum) {
                    pevdesc = pedesc->FindValueByName(value->value.GetString());
                } else {
                    pevdesc = pedesc->FindValueByNumber(value->value.GetInt());
                }

                if (nullptr != pevdesc) {
                    reflection->SetEnum(&message, field, pevdesc);
                }
            } break;

            case ProtobufFieldDescriptor::TYPE_INT32:
            case ProtobufFieldDescriptor::TYPE_SINT32:
            case ProtobufFieldDescriptor::TYPE_SFIXED32: {
                if (value->value.IsInt()) reflection->SetInt32(&message, field, value->value.GetInt());
            } break;

            case ProtobufFieldDescriptor::TYPE_UINT32:
            case ProtobufFieldDescriptor::TYPE_FIXED32: {
                if (value->value.IsUint()) reflection->SetUInt32(&message, field, value->value.GetUint());
            } break;

            case ProtobufFieldDescriptor::TYPE_INT64:
            case ProtobufFieldDescriptor::TYPE_SINT64:
            case ProtobufFieldDescriptor::TYPE_SFIXED64: {
                if (value->value.IsInt64()) reflection->SetInt64(&message, field, value->value.GetInt64());
            } break;
            case ProtobufFieldDescriptor::TYPE_UINT64:
            case ProtobufFieldDescriptor::TYPE_FIXED64: {
                if (value->value.IsUint64()) reflection->SetUInt64(&message, field, value->value.GetUint64());
            } break;

            case ProtobufFieldDescriptor::TYPE_FLOAT: {
                if (value->value.IsFloat()) reflection->SetFloat(&message, field, value->value.GetFloat());
            } break;

            case ProtobufFieldDescriptor::TYPE_DOUBLE: {
                if (value->value.IsDouble()) reflection->SetDouble(&message, field, value->value.GetDouble());
            } break;

            case ProtobufFieldDescriptor::TYPE_STRING:
            case ProtobufFieldDescriptor::TYPE_BYTES: {
                if (value->value.IsString()) reflection->SetString(&message, field, value->value.GetString());
            } break;

            case ProtobufFieldDescriptor::TYPE_MESSAGE: {
                if (value->value.IsObject()) Json2Pb(value->value, *reflection->MutableMessage(&message, field));
            } break;

            default:
                break;
        }
    }
    return true;
}

bool pbJsonConvert::Json2RepeatedPb(const rapidjson::Value& json, ProtobufMsg& message, const ProtobufFieldDescriptor* field,
                                   const ProtobufReflection* reflection, bool str2enum) {	
    int count = json.Size();
    for (auto j = 0; j < count; ++j) {
        switch (field->type()) {
            case ProtobufFieldDescriptor::TYPE_BOOL: {
                if (json[j].IsBool())
                    reflection->AddBool(&message, field, json[j].GetBool());
                else if (json[j].IsInt())
                    reflection->AddBool(&message, field, json[j].GetInt() != 0);
                else if (json[j].IsString()) {
                    if (json[j].GetString() == "true")
                        reflection->AddBool(&message, field, true);
                    else if (json[j].GetString() == "false")
                        reflection->AddBool(&message, field, false);
                }
            } break;

            case ProtobufFieldDescriptor::TYPE_ENUM: {
                auto const* pedesc = field->enum_type();
                const ::google::protobuf::EnumValueDescriptor* pevdesc = nullptr;
                if (str2enum) {
                    pevdesc = pedesc->FindValueByName(json[j].GetString());

                } else {
                    pevdesc = pedesc->FindValueByNumber(json[j].GetInt());
                }
                if (nullptr != pevdesc) {
                    reflection->AddEnum(&message, field, pevdesc);
                }

            } break;

            case ProtobufFieldDescriptor::TYPE_INT32:
            case ProtobufFieldDescriptor::TYPE_SINT32:
            case ProtobufFieldDescriptor::TYPE_SFIXED32: {
                if (json[j].IsInt()) reflection->AddInt32(&message, field, json[j].GetInt());
            } break;

            case ProtobufFieldDescriptor::TYPE_UINT32:
            case ProtobufFieldDescriptor::TYPE_FIXED32: {
                if (json[j].IsUint()) reflection->AddUInt32(&message, field, json[j].GetUint());
            } break;

            case ProtobufFieldDescriptor::TYPE_INT64:
            case ProtobufFieldDescriptor::TYPE_SINT64:
            case ProtobufFieldDescriptor::TYPE_SFIXED64: {
                if (json[j].IsInt64()) reflection->AddInt64(&message, field, json[j].GetInt64());
            } break;

            case ProtobufFieldDescriptor::TYPE_UINT64:
            case ProtobufFieldDescriptor::TYPE_FIXED64: {
                if (json[j].IsUint64()) reflection->AddUInt64(&message, field, json[j].GetUint64());
            } break;

            case ProtobufFieldDescriptor::TYPE_FLOAT: {
                if (json[j].IsFloat()) reflection->AddFloat(&message, field, json[j].GetFloat());
            } break;

            case ProtobufFieldDescriptor::TYPE_DOUBLE: {
                if (json[j].IsDouble()) reflection->AddDouble(&message, field, json[j].GetDouble());
            } break;

            case ProtobufFieldDescriptor::TYPE_MESSAGE: {
                if (json[j].IsObject()) Json2Pb(json[j], *reflection->AddMessage(&message, field));
            } break;

            case ProtobufFieldDescriptor::TYPE_STRING:
            case ProtobufFieldDescriptor::TYPE_BYTES: {
                if (json[j].IsString()) reflection->AddString(&message, field, json[j].GetString());
            } break;

            default:
                break;
        }
    }
    return true;
}

void pbJsonConvert::Pb2Json(const ProtobufMsg& message, rapidjson::Value& json, rapidjson::Document& doc, bool enum2str) {
    auto descriptor = message.GetDescriptor();
    auto reflection = message.GetReflection();
    if (nullptr == descriptor || nullptr == descriptor) return;

    auto count = descriptor->field_count();
	rapidjson::Document::AllocatorType &allocator = doc.GetAllocator(); //ªÒ»°∑÷≈‰∆˜
	if (_isRoot) {
		json.SetObject();
		_isRoot = false;
	}
	

    for (auto i = 0; i < count; ++i) {

        const auto field = descriptor->field(i);

        if (field->is_repeated()) {
			if (reflection->FieldSize(message, field) > 0) {
				rapidjson::Value arrayJson(rapidjson::kArrayType);
				RepeatedPb2Json(message, field, reflection, arrayJson, doc,enum2str);
				json.AddMember(rapidjson::StringRef(field->name().data()), arrayJson, allocator);
			}

            continue;
        }
		
        if (!reflection->HasField(message, field)) {
            continue;
        }

        switch (field->type()) {
            case ProtobufFieldDescriptor::TYPE_MESSAGE: {
                const ProtobufMsg& tmp_message = reflection->GetMessage(message, field);
				if (0 != tmp_message.ByteSize()) {
					rapidjson::Value obj(rapidjson::kObjectType);
					Pb2Json(tmp_message, obj,doc);
					json.AddMember(rapidjson::StringRef(field->name().data()), obj, allocator);
				}
            } break;

          case ProtobufFieldDescriptor::TYPE_BOOL:
				json.AddMember(rapidjson::StringRef(field->name().data()), reflection->GetBool(message, field) ? true : false, allocator);
                break;
				
            case ProtobufFieldDescriptor::TYPE_ENUM: {
                auto* enum_value_desc = reflection->GetEnum(message, field);
                if (enum2str) {
					json.AddMember(rapidjson::StringRef(field->name().data()), rapidjson::Value(enum_value_desc->name().data(),allocator).Move(), allocator);
                } else {
					json.AddMember(rapidjson::StringRef(field->name().data()), enum_value_desc->number(), allocator);
                }
            } break;
				
            case ProtobufFieldDescriptor::TYPE_INT32:
            case ProtobufFieldDescriptor::TYPE_SINT32:
            case ProtobufFieldDescriptor::TYPE_SFIXED32:
				json.AddMember(rapidjson::StringRef(field->name().data()), reflection->GetInt32(message, field), allocator);
                break;

            case ProtobufFieldDescriptor::TYPE_UINT32:
            case ProtobufFieldDescriptor::TYPE_FIXED32:
				json.AddMember(rapidjson::StringRef(field->name().data()), reflection->GetUInt32(message, field), allocator);
                break;

            case ProtobufFieldDescriptor::TYPE_INT64:
            case ProtobufFieldDescriptor::TYPE_SINT64:
            case ProtobufFieldDescriptor::TYPE_SFIXED64:
				json.AddMember(rapidjson::StringRef(field->name().data()), reflection->GetInt64(message, field), allocator);
                break;

            case ProtobufFieldDescriptor::TYPE_UINT64:
            case ProtobufFieldDescriptor::TYPE_FIXED64:
				json.AddMember(rapidjson::StringRef(field->name().data()), reflection->GetUInt64(message, field), allocator);
                break;

            case ProtobufFieldDescriptor::TYPE_FLOAT:
				json.AddMember(rapidjson::StringRef(field->name().data()), reflection->GetFloat(message, field), allocator);
                break;

            case ProtobufFieldDescriptor::TYPE_STRING:
            case ProtobufFieldDescriptor::TYPE_BYTES:	
				json.AddMember(rapidjson::StringRef(field->name().data()), rapidjson::Value(reflection->GetString(message, field).data(), allocator).Move(), allocator);
                break;

            default:
                break;
        }
    }
}

void pbJsonConvert::RepeatedPb2Json(const ProtobufMsg& message, const ProtobufFieldDescriptor* field,
                                   const ProtobufReflection* reflection, rapidjson::Value& json, rapidjson::Document& doc, bool enum2str) {
    if (nullptr == field || nullptr == reflection) {
        Pb2Json(message, json,doc);
    }

	json.SetArray();
    for (auto i = 0; i < reflection->FieldSize(message, field); ++i) {
		rapidjson::Value tmp_json;
		rapidjson::Value root(rapidjson::kObjectType);
        switch (field->type()) {
            case ProtobufFieldDescriptor::TYPE_MESSAGE: {
                const ProtobufMsg& tmp_message = reflection->GetRepeatedMessage(message, field, i);
                if (0 != tmp_message.ByteSize()) {
                    Pb2Json(tmp_message, root,doc);
                }
            } break;

            case ProtobufFieldDescriptor::TYPE_BOOL:
                tmp_json = reflection->GetRepeatedBool(message, field, i) ? true : false;
                break;

            case ProtobufFieldDescriptor::TYPE_ENUM: {
                auto* enum_value_desc = reflection->GetRepeatedEnum(message, field, i);
                if (enum2str) {
                    tmp_json = rapidjson::Value(enum_value_desc->name().data(),doc.GetAllocator()).Move();
                } else {
                    tmp_json = enum_value_desc->number();
                }
            } break;

            case ProtobufFieldDescriptor::TYPE_INT32:
            case ProtobufFieldDescriptor::TYPE_SINT32:
            case ProtobufFieldDescriptor::TYPE_SFIXED32:
                tmp_json = reflection->GetRepeatedInt32(message, field, i);
                break;

            case ProtobufFieldDescriptor::TYPE_UINT32:
            case ProtobufFieldDescriptor::TYPE_FIXED32:
                tmp_json = reflection->GetRepeatedUInt32(message, field, i);
                break;

            case ProtobufFieldDescriptor::TYPE_INT64:
            case ProtobufFieldDescriptor::TYPE_SINT64:
            case ProtobufFieldDescriptor::TYPE_SFIXED64:
                tmp_json = reflection->GetRepeatedInt64(message, field, i);
                break;

            case ProtobufFieldDescriptor::TYPE_UINT64:
            case ProtobufFieldDescriptor::TYPE_FIXED64:
                tmp_json = reflection->GetRepeatedUInt64(message, field, i);
                break;

            case ProtobufFieldDescriptor::TYPE_FLOAT:
                tmp_json = reflection->GetRepeatedFloat(message, field, i);
                break;

            case ProtobufFieldDescriptor::TYPE_STRING:
            case ProtobufFieldDescriptor::TYPE_BYTES:
                tmp_json = rapidjson::Value(reflection->GetRepeatedString(message, field, i).data(), doc.GetAllocator()).Move();
                break;

            default:
                break;
        }
		if (field->type() == ProtobufFieldDescriptor::TYPE_MESSAGE) {
			json.PushBack(root, doc.GetAllocator());
		}
		else {
			json.PushBack(tmp_json, doc.GetAllocator());
		}
		
		
    }
}
